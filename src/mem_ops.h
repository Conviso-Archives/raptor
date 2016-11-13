#include <stdio.h>	
#include <sys/types.h>
#include <string.h>		
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>
#define XFREE(x) xfree((void **)x);
#define MUL_NO_OVERFLOW	((size_t)1 << (sizeof(size_t)*4))

void *xallocaarray (size_t nmemb, size_t size); 
void *xmallocarray (size_t nmemb, size_t size);
void *xmalloc (size_t size);
void *xcalloc (size_t mem, size_t size);
void *xrealloc (void *ptr, size_t size);
void xfree(void **ptr);


