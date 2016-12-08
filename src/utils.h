#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <alloca.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <sys/resource.h>
#include <errno.h> 
#include <sys/types.h>
#include <time.h>


// set DEBUG ON
#define BUGVIEW 1
#define DEBUG(x, s...) do { \
 if (!BUGVIEW) { break; } \
 time_t t = time(NULL); \
 char *d = ctime(&t); \
 fprintf(stderr, "\n--- DEBUG-START ---\n\n %.*s %s[%d] %s(): \n", \
 (int)strlen(d) - 1, d, __FILE__, \
 __LINE__, __FUNCTION__); \
 fprintf(stderr, x, ## s); \
 fprintf(stderr,"\n\n--- DEBUG-END ---\n"); \
} while (0);

// colors macro
#define RED "\033[22;31m"
#define YELLOW "\033[01;33m"
#define CYAN "\033[22;36m"
#define GREEN "\033[22;32m"
#define LAST "\033[0m"

void No_Pause_Waf();
void no_write_coredump (void);
void load_signal_alarm (void);
char from_hex(char ch);
char *urldecode(char *str, int size) ;
char *deadspace(char *str);
