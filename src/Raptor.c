#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <getopt.h>
#include <signal.h>
#include <sys/resource.h>
#include "utils.h"
#include "proxy.h" // reverse proxy
#include "../lib/BSD/strsec.h" // strlcpy(),strlcat()...
#include "matchlist.h" 
#include "validate.h" // argvs_validate

void init_banner_raptor()
{
 puts(
   "\n\t\tCoded by CoolerVoid - coolerlair[at]gmail[dot]com\n\n"
   "     ▄████████    ▄████████    ▄███████▄     ███      ▄██████▄     ▄████████   \n"       
   "    ███    ███   ███    ███   ███    ███ ▀█████████▄ ███    ███   ███    ███   \n"       
   "    ███    ███   ███    ███   ███    ███    ▀███▀▀██ ███    ███   ███    ███   \n"       
   "   ▄███▄▄▄▄██▀   ███    ███   ███    ███     ███   ▀ ███    ███  ▄███▄▄▄▄██▀   \n"       
   "  ▀▀███▀▀▀▀▀   ▀███████████ ▀█████████▀      ███     ███    ███ ▀▀███▀▀▀▀▀     \n"       
   "  ▀███████████   ███    ███   ███            ███     ███    ███ ▀███████████   \n"       
   "    ███    ███   ███    ███   ███            ███     ███    ███   ███    ███   \n"       
   "    ███    ███   ███    █▀   ▄████▀         ▄████▀    ▀██████▀    ███    ███   \n"       
   "    ███    ███                                                    ███    ███   \n"       
   "                       ▄█     █▄     ▄████████    ▄████████       \n"           
   "                      ███     ███   ███    ███   ███    ███       \n"           
   "                      ███     ███   ███    ███   ███    █▀        \n"           
   "                      ███     ███   ███    ███  ▄███▄▄▄           \n"           
   "                      ███     ███ ▀███████████ ▀▀███▀▀▀           \n"           
   "                      ███     ███   ███    ███   ███              \n"           
   "                      ███ ▄█▄ ███   ███    ███   ███              \n"           
   "                       ▀███▀███▀    ███    █▀    ███              \n"                                            
   "\n\tRAPTOR WEB APPLICATION FIREWALL v0.04 \n\n\t██████████████████████████████████████████████████\n"
 );

}

void option_banner_raptor()
{
 puts(
	"\tOptions argv:\n"
	"\t--host or -h : host to protect \n"
	"\t--port or -p : port of host to protect \n"
	"\t--redirect or -r : port to redirect HTTP \n"
	"\t--wafmode or -w : Waf mode protection level, choice level of protection between 1,2,3 or 4 (mode 1 and 3 block all javascripts)\n"
	"\t--log or -o : Write in log file \n"
	"\t--match or -m : match algorithm you can choice (dfa, horspool or karp-rabin), example --match dfa \n"
	"\tConfig Blacklist at config/blacklist_ip.txt\n"	
	"\tConfig list rule of matchs at config/match_list.txt\n"
 );

}

static struct option long_options[] =
{
	{"host", required_argument, NULL, 'h'},
	{"port", required_argument, NULL, 'p'},	
	{"redirect", required_argument, NULL, 'r'},
	{"wafmode", required_argument, NULL, 'w'},
 	{"log", required_argument, NULL, 'o'}, 
 	{"match", required_argument, NULL, 'm'}, 
	{NULL, 0, NULL, 0}
};

int main(int argc, char ** argv)
{
 	char c;
	short options_match=0;

 	no_write_coredump();
 	load_signal_alarm();
	param.wafmode=0;

	if(argc < 8) 
	{
		init_banner_raptor();
		option_banner_raptor();
		DEBUG(" Need more arguments.\n");
		exit(0);
	}
 

	opterr = 0;

// get inputs of argvs
 	while((c = getopt_long(argc, argv, "h:p:r:w:o:m:",long_options,NULL)) != -1)
  		switch(c) 
  		{
// host
			case 'h':
				if ( strnlen(optarg,65)<= 64 )
				{
					burn_mem(param.hostarg,0,64);
					strlcpy(param.hostarg,optarg,65);	
				} else {
					DEBUG("Error at param host");
					exit(0);
				}
			break;
// port
			case 'p':
				if ( strnlen(optarg,6)<= 5 )
				{
					param.portarg=(int) strtol(optarg, (char **)NULL, 10);	
				} else {
					DEBUG("Error at param port");
					exit(0);
				}
			break;
// redirect port
			case 'r':
				if ( strnlen(optarg,6)<= 5 )
				{
					
					param.redirectarg=(int) strtol(optarg, (char **)NULL, 10);	
				} else {
					DEBUG("Error at param redirect port");
					exit(0);
				}
			break;
// waf mode
			case 'w':
				if ( strnlen(optarg,2)<= 1 )
				{	
					param.wafmode=(int) strtol(optarg, (char **)NULL, 10);	

					if(param.wafmode > 4 || param.wafmode < 1)
					{
						DEBUG("param of Waf mode is NULL, Disable DFA Match mode!");
						param.wafmode=0;
					}

				} else {
					DEBUG("Error at param Waf mode");
					exit(0);
				}
			break;
// log
			case 'o':
				if ( strnlen(optarg,16)<= 16 )
				{
					burn_mem(param.logarg,0,16);	
					strlcpy(param.logarg,optarg,17);	
				} else {
					DEBUG("Error at param Log");
					exit(0);
				}
			break;

// match algorithm, this funtion uses for match_algorithms.c-->matchlist.c-->rule.c
			case 'm':
				if ( strnlen(optarg,12)<= 11 )
				{
					char algorithm[12];

					burn_mem(algorithm,0,11);	
					strlcpy(algorithm,optarg,11);

					if(strnstr(algorithm,"dfa",3))
						options_match=1;

					if(strnstr(algorithm,"horspool",8))
						options_match=2;

					if(strnstr(algorithm,"karp-rabin",10))
						options_match=3;

					if(options_match==0)
					{
						DEBUG("need match argv example --match dfa");
						exit(0);
					}

					param.option_algorithm=options_match;					
				} else {
					DEBUG("Error at param Log");
					exit(0);
				}
			break;


			case '?':
    				if(optopt == 'h' || optopt == 'p' || optopt == 'r' || optopt == 'w' || optopt == 'o' || optopt == 'm') 
    				{
     					init_banner_raptor();
					option_banner_raptor();
     					DEBUG("Option -%c requires an argument.\n", optopt); 
     					exit(0);
    				}
			break;
		}
	

	isnull_argv();
	init_banner_raptor();
	puts("\n\tSTART raptor...\n");

// at proxy.c
	tcp_reverse_proxy(param.redirectarg, param.hostarg, param.portarg, param.wafmode, param.logarg, param.option_algorithm);

	exit(0);
}
