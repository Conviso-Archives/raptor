#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h> 
#include <stdbool.h>
#include <time.h>
#include "utils.h"
#include "mem_ops.h"
#include "dfa_match.h"
#include "file_ops.h"
#include "blacklist.h"
#include "matchlist.h"
#include "../lib/BSD/strsec.h"


bool Judge_malicious(char *buf, const int BUF_SIZE, char *addr, char *logfile, int wafmode, short match_option)
{
	int line_number=1;
	time_t t = time(NULL);
	size_t tmp_size_buf=BUF_SIZE+1; 
	bool xss=false,sqli=false,pathtraversal=false,match=false,block=false,blacklist=false,match_list=false,isrequest=false;
	char *tmp3=xallocaarray(tmp_size_buf,sizeof(char)),*tmp4=tmp3,*d=ctime(&t); 

// so this part i use GOTO, don't have problem, don't have dragons here, its only loop unrolling...

	if(blacklist_ip(addr)==true) // function in blacklist.c
	{ 
		blacklist=true;
		goto blacklist_JMP;
	}

	isrequest=is_request(buf);



// wash the request before pass to filter ;-)
	char *tmpbuf=urldecode(buf,BUF_SIZE); // function at utils.h
	char *clbuf=deadspace(tmpbuf); // function at utils.h, this function remove all spaces ' ' aka remove blanks of string
	char *match_string=matchlist(tmpbuf,BUF_SIZE,match_option); // matchlist.c

	if(isrequest==true && match_option>0 && match_string!=NULL) 
	{
		match_list=true;
		goto matchlist_JMP;
	}



// disable DFA
	if(wafmode==0)
		goto end_JMP;

//modes 2 and 4 not is case sentive
	if(wafmode==2 || wafmode==4)
	{
		char *http_request2=all2lowcase(clbuf);
		strlcpy(tmp3,http_request2,tmp_size_buf);
	} else {
		strlcpy(tmp3,(char *)clbuf,tmp_size_buf); 
	}

	
	if(isrequest==true)
	{	

// Call	deterministic finite automaton to detect attacks
		while(match!=true)
			if(wafmode<=2)
				switch(block_waf_level1(&tmp4, &tmp3))  // function at dfa_match.c
				{
		       			case SQLI:
	  		 		sqli=true;
					match=true;
         				break;
		
			  	  	case XSS:
			   		xss=true;
					match=true;
   		       			break;
   	       		 	
	   		      		case PATHTRAVERSAL:
			   		pathtraversal=true;
					match=true;
   		       			break;

					case COUNTER:
		    			line_number++;
            				break;

        				case END:
		   			match=true;	
        	    			break;
	
				}
			else
				switch(block_waf_level2(&tmp4, &tmp3))  // function at dfa_match.c
				{
		       			case SQLI:
	  		 		sqli=true;
					match=true;
         				break;
		
			  	  	case XSS:
			   		xss=true;
					match=true;
   		       			break;
   	       		 	
	   		      		case PATHTRAVERSAL:
			   		pathtraversal=true;
					match=true;
   		       			break;

					case COUNTER:
		    			line_number++;
            				break;

        				case END:
		   			match=true;	
        	    			break;
	
				}
	}
	
// write in log file
	if(pathtraversal==true)
	{
		char *report=NULL;
		size_t tmp_size=BUF_SIZE+256;
		report=xmallocarray(tmp_size,sizeof(char));
		snprintf(report,tmp_size,"Path Traversal Attack\n IP: %s\n Time: %s\n Request:\n%s\n-----\n",addr,d,buf);
		WriteFile(logfile,report);
		memset(report,0,BUF_SIZE+255);
		XFREE(report);
		block=true;
	}

	if(sqli==true)
	{
		char *report=NULL;
		size_t tmp_size=BUF_SIZE+256;
		report=xmallocarray(tmp_size,sizeof(char));
		snprintf(report,tmp_size,"SQL injection Attack\n IP: %s\n Time: %s\n Request:\n%s\n-----\n",addr,d,buf);
		WriteFile(logfile,report);
		memset(report,0,BUF_SIZE+255);
		XFREE(report);
		block=true;
	}

	if(xss==true)
	{	
		char *report=NULL;
		size_t tmp_size=BUF_SIZE+256;
		report=xmallocarray(tmp_size,sizeof(char));
		snprintf(report,tmp_size,"Cross-site scripting\n IP: %s\n Time: %s\n Request:\n%s\n-----\n",addr,d,buf);
		WriteFile(logfile,report);
		memset(report,0,BUF_SIZE+255);
		XFREE(report);
		block=true;
	}

// jump here if block per blacklist
	blacklist_JMP:

	if(blacklist==true)
	{	
		char *report=NULL;
		report=xmalloc(256);
		snprintf(report,256,"Address at blacklist try connect\n IP: %s\n Time: %s\n-----\n",addr,d);
		WriteFile(logfile,report);
		memset(report,0,255);
		XFREE(report);
		block=true;
		memset(addr,0,strlen(addr));
		XFREE(addr);
	}



// jump here if block per match list
	matchlist_JMP:

	if(match_list==true)
	{	
		char *report=NULL;
		int total=250+BUF_SIZE+1024;
		report=xmallocarray(total,sizeof(char));
		memset(report,0,total-1);
		snprintf(report,total,"String at match list try connect\n IP: %s\n Time: %s\n Match: %s \n Buffer: %s\n",addr,d,match_string,buf);
		WriteFile(logfile,report);
		memset(report,0,total-1);
		XFREE(report);
		block=true;	
	}

	end_JMP:

	memset(addr,0,strlen(addr));
	XFREE(addr);

		
    	return block;
}

