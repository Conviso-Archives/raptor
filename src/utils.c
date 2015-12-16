#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <alloca.h>
#include <unistd.h>
#include <signal.h>
#include <sys/resource.h>
#include <errno.h> 
#include <sys/types.h>
#include <time.h>
#include "utils.h"
#include "mem_ops.h"

void No_Pause_Waf()
{
	DEBUG("\n When start Waf\n You Cannot be terminated using Ctrl+C or Ctrl+Z...\n Wait task ends... press <enter> to continue... \n");
	getchar();
	fflush(stdout);
}

void no_write_coredump (void) 
{
  	struct rlimit rlim;
   
	rlim.rlim_cur = 0; 
	rlim.rlim_max = 0; 
	setrlimit(RLIMIT_CORE, &rlim);

}

void load_signal_alarm (void)
{
 	struct sigaction sigIntHandler;

   	sigIntHandler.sa_handler = (void (*)(int))No_Pause_Waf;
   	sigemptyset(&sigIntHandler.sa_mask);
   	sigIntHandler.sa_flags = 0;

	if(sigemptyset(&sigIntHandler.sa_mask)!=0)
	{
		DEBUG("Error at signal");
		exit(1);
	}

   	if(sigaction(SIGINT, &sigIntHandler, NULL)!=0)
	{
		DEBUG("Error at signal");
		exit(1);
	}

   	if(sigaction(SIGTSTP, &sigIntHandler, NULL)!=0)
	{
		DEBUG("Error at signal");
		exit(1);
	}

   	if(sigaction(SIGQUIT, &sigIntHandler, NULL)!=0)
	{
		DEBUG("Error at signal");
		exit(1);
	}

}



int ishex(int x)
{
	return	(x >= '0' && x <= '9') || (x >= 'a' && x <= 'f') || (x >= 'A' && x <= 'F');
}

char *urldecode(const char *s, int sizestr)
{
	char *o;
	const char *end = s + strlen(s);
	int c=0;
 	
	char *dec=xmalloc(sizestr*sizeof(char));

	for (o = dec; s <= end; o++) 
	{
		c = *s++;

		if (c == '+') 
			c = ' ';
		else if (c == '%' && (!ishex(*s++)||!ishex(*s++)||!sscanf(s - 2, "%2x", &c)))
			return " ";
 
		if (dec) 
			*o = c;
	}

	
	return dec;
}
 

// remove all blank space ' ' from string
char *deadspace(char *str)
{
 	char *out = str, *put = str;

	for(; *str != '\0'; ++str)
	{
		if(*str != ' ')
 			*put++ = *str;
	}

	*put = '\0';

	return out;
}

