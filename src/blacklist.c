#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mem_ops.h"

//read lines of file
bool blacklist_ip(char * addr)
{
	FILE * arq;
	bool at_list=false;

	arq = fopen("config/blacklist_ip.txt", "r");

	if( arq == NULL )
	{

		DEBUG("error to open() file"); 	 
		exit(1);
	}

	char line[128];

	while( fgets(line,sizeof line,arq) && at_list==false )
	{    
		if(strstr(line,addr))
			at_list=true;
	}

	if( fclose(arq) == EOF )
	{
		DEBUG("Error in close() file config/blacklist_ip.txt ");
		exit(1);
	}
	arq=NULL;

	DEBUG("Return bool is %s \n",(at_list==false)?"false":"true");

	return at_list;
}


