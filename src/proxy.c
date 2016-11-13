#include "proxy.h"
#include "../lib/BSD/strsec.h"

/*
items of struct tcp_server_thread_info

	char stamp[128];
	char log_reg[18];
	int stamp_port;
	int accepted_socket;
	int wafmode;
	short match_option;
*/

/// get ip of client
char *get_ip_of(int sock)
{
	socklen_t len;
	struct sockaddr_storage addr;
	char ipstr[INET6_ADDRSTRLEN];

	len = sizeof addr;
	getpeername(sock, (struct sockaddr*)&addr, &len);
	if (addr.ss_family == AF_INET) 
	{
		struct sockaddr_in *s = (struct sockaddr_in *)&addr;
		inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
	} else { 
//if have AF_INET6
		struct sockaddr_in6 *s = (struct sockaddr_in6 *)&addr;
		inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
	}
	
	char *tmp=xmalloc(sizeof(ipstr)+1);
	strlcpy(tmp,ipstr,sizeof(ipstr)+1);

	return tmp;
}


int ping_socket(int socket)
{
	char buf[1];

	return recv(socket, buf, 1, MSG_PEEK | MSG_DONTWAIT);
}

// socket default to any connections 
int tcp_create_socket(int port)
{
	int s = -1;

	struct addrinfo hints, *res;
 	memset(&hints, 0, sizeof hints);
 	hints.ai_family = AF_UNSPEC; // portable to use IPv4 or IPv6, thanks Beej Jorgensen for good examples with function getaddrinfo()
	hints.ai_socktype = SOCK_STREAM;
 	hints.ai_flags = AI_PASSIVE;
//	hints.ai_flags |= AI_CANONNAME; 	
	char tmp[6];
 	snprintf(tmp,sizeof(tmp),"%5d",port);
 	getaddrinfo(NULL, tmp, &hints, &res);

	if ((s = socket(res->ai_family, SOCK_STREAM, 0)) < 0) 
	{
		DEBUG("create socket error!\n");
 		exit(1);
	}

	freeaddrinfo(res);

	return s;
}

void tcp_bind_and_listen(int socket, int port)
{
	const int LENGTH_OF_LISTEN_QUEUE = 10;
	struct addrinfo hints, *res;

 	memset(&hints, 0, sizeof hints);
 	hints.ai_family = AF_UNSPEC; 
	hints.ai_socktype = SOCK_STREAM;
 	hints.ai_flags = AI_PASSIVE;
// 	hints.ai_flags |= AI_CANONNAME;
 	char tmp[6]; 
 	snprintf(tmp,sizeof(tmp),"%5d",port);
 	getaddrinfo(NULL, tmp, &hints, &res);


 	if (bind(socket, res->ai_addr, res->ai_addrlen) < 0) 
	{
 		DEBUG("bind to port %d failure!\n", port);
 		exit(1);
 	}

	if (listen(socket, LENGTH_OF_LISTEN_QUEUE) < 0) 
	{
 		DEBUG("call listen failure!\n");
 		exit(1);
	}

	freeaddrinfo(res);

}

int tcp_connect_to_stamp(const char* stamp, int port)
{
	int stamp_socket = tcp_create_socket(port);

	struct addrinfo hints, *res;

 	memset(&hints, 0, sizeof hints);
 	hints.ai_family = AF_UNSPEC;
 	hints.ai_socktype = SOCK_STREAM;
 	hints.ai_flags = AI_PASSIVE;
//	hints.ai_flags |= AI_CANONNAME;
 	char tmp[6]; // max is 65535
 	snprintf(tmp,sizeof(tmp),"%5d",port);
 	getaddrinfo(stamp, tmp, &hints, &res);


	if (connect(stamp_socket,res->ai_addr, res->ai_addrlen) < 0)       
	{
 		DEBUG("cannot connect\n");
 		exit(1);
	}

	freeaddrinfo(res);

	return stamp_socket;
}

// this is core function to send requests to test Requests
int bridge_of_data(int from_socket, int to_socket, char *logfile, int wafmode,short match_option)
{
	const int BUF_SIZE = 10512;
	unsigned char buf[BUF_SIZE];
	memset(buf,0,BUF_SIZE-1);
	int recvbytes = recv(from_socket, buf, BUF_SIZE-1, 0);
	int sendbytes=0;
	bool block=false;
	buf[recvbytes]='\0';	
	char *tmp_addr=get_ip_of(from_socket);	

    	if (recvbytes == -1) 
	{
        	DEBUG("cannot recv data\n");
        	exit(1);
    	}


// look rule.c, if have malicious request, return true...
	block=Judge_malicious((char *)buf,BUF_SIZE,tmp_addr,logfile,wafmode,match_option);

// BLock msg of WAF
	if(block==true)
	{
		char *keepout =
	"HTTP/1.1 404 Not Found\r\n"
	"Content-type: text/html\r\n"
	"\r\n"
	"<html>\r\n"
	" <body>\r\n"
	"  <h1>Blocked</h1>\r\n"
	"  <p>The requested URL was not found on this server.</p>\r\n"
	" </body>\r\n"
	"</html>\r\n";
		
    		sendbytes = send(to_socket, keepout, strlen(keepout)+1, 0);

	} else {
    		sendbytes = send(to_socket, buf, recvbytes, 0);
	}

	memset(tmp_addr,0,strlen(tmp_addr));
	XFREE(tmp_addr);		
		
    	return sendbytes;
}


void *tcp_server_handler(void* arg)
{
	struct tcp_server_thread_info *pinfo = (struct tcp_server_thread_info *)arg;
	int stamp_socket = tcp_connect_to_stamp(pinfo->stamp, pinfo->stamp_port);

 	fd_set sockets;
 	struct timeval tv;

 	int maxfd = pinfo->accepted_socket > stamp_socket ? pinfo->accepted_socket : stamp_socket;
 	maxfd += 1;

    	int running = 1, total_bytes = 0, from = 0, to = 0, err = 0;

    	while (running) 
	{
        	FD_ZERO(&sockets);
        	FD_SET(pinfo->accepted_socket, &sockets);
        	FD_SET(stamp_socket, &sockets);

        	tv.tv_sec = 3;
        	tv.tv_usec = 0;
        
// at the future add libevent 
        	switch(select(maxfd, &sockets, NULL, NULL, &tv)) 
		{
            		case -1:
                	DEBUG("error at select()\n");
                	exit(1);

            		case 0:
//		        DEBUG("Don't have data\n");
                	break;

            		default:
                	from = pinfo->accepted_socket; 
			to = stamp_socket;
 
	               	if (FD_ISSET(stamp_socket, &sockets)) 
			{
                    		from = stamp_socket;
                    		to = pinfo->accepted_socket;
                	}

                	err = ping_socket(from);

                	if(err <= 0 && errno != EAGAIN) 
			{
//                    		DEBUG("client socket closed.\n");
                    		running = 0;
                    		break;
                	}
                	total_bytes += bridge_of_data(from, to, pinfo->log_reg, pinfo->wafmode,pinfo->match_option);
        	}
    	}


	xfree(&arg);

    	close(stamp_socket);

	return 0;
}

void tcp_reverse_proxy(int server_port, const char* stamp, int stamp_port, int waf_mode, char *logname,short option_match)
{
	int servfd, clifd;
	struct sockaddr_in cliaddr;

 	servfd = tcp_create_socket(server_port);
 	tcp_bind_and_listen(servfd, server_port);

 	while (1) 
	{
        	socklen_t length = sizeof(cliaddr);

        	clifd = accept(servfd, (struct sockaddr*)&cliaddr, &length);

        	if (clifd < 0) 
		{
            		DEBUG("Error when call accept()\n");
            		break;
        	}

        	pthread_t id = 0;
        	struct tcp_server_thread_info *pinfo =(struct tcp_server_thread_info *) xmalloc(sizeof(struct tcp_server_thread_info));
        	bzero(pinfo, sizeof(struct tcp_server_thread_info));

        	strlcpy(pinfo->stamp, stamp,sizeof(pinfo->stamp));
        	pinfo->stamp_port = stamp_port;
        	pinfo->accepted_socket = clifd;
		strlcpy(pinfo->log_reg,logname,sizeof(pinfo->log_reg));
        	pinfo->wafmode = waf_mode;
		pinfo->match_option=option_match;

        	int ret = pthread_create(&id, NULL, tcp_server_handler, pinfo);
 
       		if (ret != 0) 
		{
            		DEBUG("Create pthread error!\n");
            		exit (1);
        	}
// tcp_server_handler() use free() at pinfo pointer, if call free() here causes double free

    	}
}
