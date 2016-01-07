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
#include "proxy.h"


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
   "\n\tRAPTOR WEB APPLICATION FIREWALL v0.01 \n\n\t██████████████████████████████████████████████████\n"
 );

}

void option_banner_raptor()
{
 puts(
	"\tOptions argv:\n"
	"\t--host or -h : host to protect \n"
	"\t--port or -p : port of host to protect \n"
	"\t--redirect or -r : port to redirect HTTP \n"
	"\t--wafmode or -w : Waf mode protection level, choice level of protection between 1,2,3 or 4 \n"
	"\t--log or -o : Write in log file \n"
	"\tConfig Blacklist at config/blacklist_ip.txt\n"
 );

}

static struct option long_options[] =
{
	{"host", required_argument, NULL, 'h'},
	{"port", required_argument, NULL, 'p'},	
	{"redirect", required_argument, NULL, 'r'},
	{"wafmode", required_argument, NULL, 'w'},
 	{"log", required_argument, NULL, 'o'}, 
	{NULL, 0, NULL, 0}
};

struct choice  {
 char hostarg[65];
 char logarg[17];
 int portarg;
 int redirectarg;
 int wafmode;
};

struct choice param;


int main(int argc, char ** argv)
{
 	char c;

 	no_write_coredump();
 	load_signal_alarm();


	if(argc < 8) 
	{
		init_banner_raptor();
		option_banner_raptor();
		DEBUG(" Need more arguments.\n");
		exit(0);
	}
 

	opterr = 0;

// get inputs of argvs
 	while((c = getopt_long(argc, argv, "h:p:r:w:o:",long_options,NULL)) != -1)
  		switch(c) 
  		{
// host
			case 'h':
				if ( strnlen(optarg,65)<= 64 )
				{
					strcpy(param.hostarg,optarg);	
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
						DEBUG("Error at param Waf mode");
						exit(0);
					}

				} else {
					DEBUG("Error at param Waf mode");
					exit(0);
				}
			break;
// log
			case 'o':
				if ( strnlen(optarg,15)<= 14 )
				{
					
					strcpy(param.logarg,optarg);	
				} else {
					DEBUG("Error at param Log");
					exit(0);
				}
			break;

			case '?':
    				if(optopt == 'h' || optopt == 'p' || optopt == 'r' || optopt == 'w' || optopt == 'o') 
    				{
     					init_banner_raptor();
					option_banner_raptor();
     					DEBUG("Option -%c requires an argument.\n", optopt); 
     					exit(0);
    				}
			break;

			default:
				init_banner_raptor();
				option_banner_raptor();
     				DEBUG("Option -%c requires an argument.\n", optopt); 
     				exit(0);
		}

	init_banner_raptor();
	puts("\n\tSTART raptor...\n");

// at proxy.c
	tcp_reverse_proxy(param.redirectarg, param.hostarg, param.portarg, param.wafmode, param.logarg);

	exit(0);
}
