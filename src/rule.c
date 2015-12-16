#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h> 
#include <stdbool.h>
#include <alloca.h>
#include <time.h>
#include "utils.h"
#include "mem_ops.h"
#include "dfa_match.h"
#include "file_ops.h"
#include "blacklist.h"


bool Judge_malicious(char *buf, const int BUF_SIZE, char *addr, char *logfile, int wafmode)
{
	int line_number=1;
	time_t t = time(NULL); 
	bool xss=false,sqli=false,pathtraversal=false,match=false,block=false,blacklist=false;
	char *tmp3=alloca(sizeof(char)*BUF_SIZE+1),*tmp4=tmp3,*d=ctime(&t); 

	if(blacklist_ip(addr)==true) // function in blacklist.c
	{ 
		blacklist=true;
		goto blacklist_JMP;
	}

// wash the request before pass to filter ;-)
	char *tmpbuf=urldecode(buf,BUF_SIZE); // function at utils.h
	char *clbuf=deadspace(tmpbuf); // function at utils.h, this function remove all spaces ' ' aka remove blanks of string

//modes 2 and 4 not is case sentive
	if(wafmode==2 || wafmode==4)
	{
		char *http_request2=all2lowcase(clbuf);
		strcpy(tmp3,http_request2);
 		memset(http_request2,0,strlen(http_request2)-1);
		xfree((void **)http_request2);
	} else {
		strcpy(tmp3,(char *)clbuf); 
	}

	
	if(is_request((char *)tmp3)==true)
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
		report=xmalloc(BUF_SIZE+256);
		sprintf(report,"Path Traversal Attack\n IP: %s\n Time: %s\n Request:\n%s\n-----\n",addr,d,buf);
		WriteFile(logfile,report);
		memset(report,0,BUF_SIZE+255);
		xfree((void**)report);
		block=true;
	}

	if(sqli==true)
	{
		char *report=NULL;
		report=xmalloc(BUF_SIZE+256);
		sprintf(report,"SQL injection Attack\n IP: %s\n Time: %s\n Request:\n%s\n-----\n",addr,d,buf);
		WriteFile(logfile,report);
		memset(report,0,BUF_SIZE+255);
		xfree((void**)report);
		block=true;
	}

	if(xss==true)
	{	
		char *report=NULL;
		report=xmalloc(BUF_SIZE+256);
		sprintf(report,"Cross-site scripting\n IP: %s\n Time: %s\n Request:\n%s\n-----\n",addr,d,buf);
		WriteFile(logfile,report);
		memset(report,0,BUF_SIZE+255);
		xfree((void**)report);
		block=true;
	}

// jump here if block per blacklist
	blacklist_JMP:

	if(blacklist==true)
	{	
		char *report=NULL;
		report=xmalloc(256);
		sprintf(report,"Address at blacklist try connect\n IP: %s\n Time: %s\n-----\n",addr,d);
		WriteFile(logfile,report);
		memset(report,0,255);
		xfree((void**)report);
		block=true;
		memset(addr,0,strlen(addr));
		xfree((void **)addr);
		return block;
	}

	memset(addr,0,strlen(addr));
	xfree((void **)addr);

	memset(clbuf,0,BUF_SIZE-1);	
	xfree((void **)clbuf);	

	memset(tmpbuf,0,BUF_SIZE-1);	
	xfree((void **)tmpbuf);	
		
    	return block;
}

