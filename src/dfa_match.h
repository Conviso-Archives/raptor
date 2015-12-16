/*
WAF mode level 1

DFA to block

Block payloads SQLi examples
union"|"select"|"\@version"|"load_file"|"1=1"|"2=2"

Block Payloads XSS
"eval"|"script"|"onstart"|"onload"|"onerror"|"onpageshow"|"onprogress"|"alert"|"onclick"|"onmouseover"|"onfinish"|"fromCharCode"

Block payloads path traversal
some thing like ../,..\  etc...


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "mem_ops.h"

enum {
  SQLI,XSS,PATHTRAVERSAL,COUNTER,END
};


int test_letter(char p);
char *all2lowcase(char *str);
bool is_request(char *ptr);
int block_waf_level1(char** p, char** lex);
int block_waf_level2(char** p, char** lex);

