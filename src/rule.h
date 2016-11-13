#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <errno.h>
#include <pthread.h>
#include <alloca.h>
#include <time.h>
#include "utils.h"
#include "mem_ops.h"
#include "file_ops.h"
//#include "dfa_match.h"
#include "blacklist.h"
#include "matchlist.h"

bool Judge_malicious(char *buf, const int BUF_SIZE,char *addr, char *logfile, int wafmode,short match_option);
