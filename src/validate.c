#include <stdio.h>
#include "utils.h"
#include "validate.h"

void isnull_argv() 
{
	if(strnlen(param.hostarg,64)==0)
	{
		DEBUG("Need host argument\n");
		exit(0);
	}

	if(param.portarg==0)
	{
		DEBUG("Need port argument\n");
		exit(0);
	}

	if(param.redirectarg==0)
	{
		DEBUG("Need redirect argument");
		exit(0);
	}

	if(strnlen(param.logarg,16)==0)
	{
		DEBUG("Need log argument");
		exit(0);
	}

}
