#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <stdbool.h>
#include <alloca.h>
#include "utils.h"
#include "rule.h"
#include "mem_ops.h"
//#include "dfa_match.h"
#include "file_ops.h"
#include "../lib/BSD/strsec.h"
#include "blacklist.h"


struct tcp_server_thread_info
{
	char stamp[128];
	char log_reg[18];
	int stamp_port;
	int accepted_socket;
	int wafmode;
	short match_option;
};


char *get_ip_of(int sock);
int ping_socket(int socket);
int tcp_create_socket(int port);
void tcp_bind_and_listen(int socket, int port);
int tcp_connect_to_stamp(const char* stamp, int port);
int bridge_of_data(int from_socket, int to_socket, char *logfile, int wafmode,short match_option);
void *tcp_server_handler(void* arg);
void tcp_reverse_proxy(int server_port, const char* stamp, int stamp_port, int waf_mode, char *logname, short option_match);
