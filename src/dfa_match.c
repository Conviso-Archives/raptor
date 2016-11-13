/*
WAF mode level 1

DFA to block

Block payloads SQLi
union"|"select"|"insert"|"\@version"|"load_file"|"1=1"|"2=2" etc...

Block Payloads XSS
"eval"|"script"|"onstart"|"onload"|"onerror"|"onpageshow"|"onprogress"|"alert"|"onclick"|"onmouseover"|"onfinish"|"fromCharCode" etc..

Block Payload PATH traversal
../|..\   etc...

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa_match.h"
#include "mem_ops.h"
#include <alloca.h>
#include <stdbool.h>

// DFA to test if letter between a-z or A-Z
int test_letter(char p)
{
	unsigned char yych;

	yych = p;
	switch (yych) {
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy3;
	default:	goto yy2;
	}
yy2:
	{ return 1; }
yy3:
	++p;
	{ return 0; }
    

}


/*
Example use this DFA
int main() 
{
    char *p = ReadLines("test.txt");
    char *last = p;
    int test=0,result=0,line_number=1;

    puts(p);

    while(!result )
	switch (block_waf_level1(&p, &last)) 
	{
        	case SQLI:
	    	test=1;
		printf("Have SQL injection here line number %d \n",line_number);	
            	break;

	        case XSS:
	        test=0;
     	        printf("Have XSS here! line number %d \n",line_number);
   	        break;
   	        
   	       	case PATHTRAVERSAL:
	        test=0;
     	        printf("Have XSS here! line number %d \n",line_number);
   	        break;


		case COUNTER:
	    	line_number++;
            	break;

        	case END:
	    	result=1;	
            	break;
        }

    if(test)
	puts("Have BAD Request\n");
    else
	puts("Ok here");

   
    return 0;
}
*/


// random case return string, input= tomato output=ToMatO or tOmATo...
char *all2lowcase(char *str)
{
	char *str_new=xmallocarray(sizeof(char),strlen(str)+1);
	int i=0;
	
	while(*str != '\0')
	{
		
		if(!test_letter( *str ) )
		{

			*(str_new+i)=*str | 0x20;	
			i++;
		} else {
			*(str_new+i)=*str;
			i++;
		}

	
		str++;	
	}


	return str_new;

}

bool is_request(char *ptr)
{
// is GET ?
 	if(ptr[0]=='G' && ptr[1]=='E' && ptr[2]=='T')
 	{
		while(*ptr!='\n' || *ptr!='\r')
		{
			if(*ptr=='=')
				return true;
			ptr++;	
		}

		return false;
 	}


 	if(ptr[0]=='g' && ptr[1]=='e' && ptr[2]=='t')
 	{

		while(*ptr!='\n' || *ptr!='\r')
		{
			if(*ptr=='=')
				return true;
			ptr++;	
		}


		return false;
 	}

// is POST ?
 	if(ptr[0]=='P' && ptr[1]=='O' && ptr[2]=='S' && ptr[3]=='T')
 	{
		return true;
 	}


 	if(ptr[0]=='p' && ptr[1]=='o' && ptr[2]=='s' && ptr[3]=='t')
 	{
		return true;
 	}


 return false;
}




int block_waf_level1(char** p, char** lex)
{
  
    char* marker;

    for (;;) {
    *lex = *p;
    
	{
		char yych;

		yych = (char)**p;
		switch (yych) {
		case 0x00:	goto yy20;
		case '\n':	goto yy18;
		case '%':	goto yy17;
		case '*':
		case '>':	goto yy2;
		case '.':	goto yy4;
		case '/':	goto yy16;
		case '1':	goto yy10;
		case '2':	goto yy11;
		case '@':	goto yy8;
		case 'a':	goto yy14;
		case 'e':	goto yy12;
		case 'f':	goto yy15;
		case 'i':	goto yy7;
		case 'l':	goto yy9;
		case 'o':	goto yy13;
		case 's':	goto yy6;
		case 'u':	goto yy5;
		default:	goto yy22;
		}
yy2:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '%':
		case '*':
		case '.':
		case '/':
		case '1':
		case '2':
		case '>':
		case '@':
		case 'a':
		case 'e':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'u':	goto yy208;
		default:	goto yy3;
		}
yy3:

		{ continue; }

yy4:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '%':
		case '*':
		case '/':
		case '1':
		case '2':
		case '>':
		case '@':
		case 'a':
		case 'e':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'u':	goto yy208;
		case '.':	goto yy203;
		default:	goto yy3;
		}
yy5:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy200;
		default:	goto yy3;
		}
yy6:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'c':	goto yy192;
		case 'e':	goto yy193;
		default:	goto yy3;
		}
yy7:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy188;
		default:	goto yy3;
		}
yy8:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'v':	goto yy182;
		default:	goto yy3;
		}
yy9:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'o':	goto yy175;
		default:	goto yy3;
		}
yy10:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '=':	goto yy174;
		default:	goto yy3;
		}
yy11:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '=':	goto yy170;
		default:	goto yy3;
		}
yy12:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'v':	goto yy168;
		default:	goto yy3;
		}
yy13:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy126;
		default:	goto yy3;
		}
yy14:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'l':	goto yy123;
		default:	goto yy3;
		}
yy15:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'r':	goto yy110;
		default:	goto yy3;
		}
yy16:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'e':	goto yy99;
		default:	goto yy3;
		}
yy17:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '2':	goto yy23;
		default:	goto yy3;
		}
yy18:
		++*p;

		{ return COUNTER; }

yy20:
		++*p;

		{ return END; }

yy22:
		yych = (char)*++*p;
		goto yy3;
yy23:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy26;
		case 'e':	goto yy25;
		default:	goto yy24;
		}
yy24:
		*p = marker;
		goto yy3;
yy25:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy46;
		default:	goto yy24;
		}
yy26:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy27;
		default:	goto yy24;
		}
yy27:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy28;
		default:	goto yy24;
		}
yy28:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy29;
		default:	goto yy24;
		}
yy29:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy30;
		default:	goto yy24;
		}
yy30:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy31;
		default:	goto yy24;
		}
yy31:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy32;
		default:	goto yy24;
		}
yy32:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy33;
		default:	goto yy24;
		}
yy33:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy34;
		default:	goto yy24;
		}
yy34:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy35;
		default:	goto yy24;
		}
yy35:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy36;
		default:	goto yy24;
		}
yy36:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy37;
		default:	goto yy24;
		}
yy37:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy38;
		default:	goto yy24;
		}
yy38:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy39;
		default:	goto yy24;
		}
yy39:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy40;
		default:	goto yy24;
		}
yy40:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy41;
		default:	goto yy24;
		}
yy41:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy42;
		default:	goto yy24;
		}
yy42:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy43;
		default:	goto yy24;
		}
yy43:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy45;
		default:	goto yy43;
		}
yy45:

		{ return PATHTRAVERSAL; }

yy46:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy47;
		default:	goto yy24;
		}
yy47:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy48;
		default:	goto yy24;
		}
yy48:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy49;
		case '/':	goto yy50;
		case '\\':	goto yy51;
		default:	goto yy24;
		}
yy49:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy71;
		case '5':	goto yy70;
		default:	goto yy24;
		}
yy50:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy57;
		default:	goto yy24;
		}
yy51:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy52;
		default:	goto yy24;
		}
yy52:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy53;
		default:	goto yy24;
		}
yy53:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy54;
		default:	goto yy24;
		}
yy54:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy55;
		default:	goto yy24;
		}
yy55:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy56;
		default:	goto yy24;
		}
yy56:
		yych = (char)*++*p;
		switch (yych) {
		case '\\':	goto yy43;
		default:	goto yy24;
		}
yy57:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy58;
		default:	goto yy24;
		}
yy58:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy59;
		default:	goto yy24;
		}
yy59:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy60;
		default:	goto yy24;
		}
yy60:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy61;
		default:	goto yy24;
		}
yy61:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy62;
		default:	goto yy24;
		}
yy62:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy63;
		default:	goto yy24;
		}
yy63:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy64;
		default:	goto yy24;
		}
yy64:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy65;
		default:	goto yy24;
		}
yy65:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy66;
		default:	goto yy24;
		}
yy66:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy67;
		default:	goto yy24;
		}
yy67:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy68;
		default:	goto yy24;
		}
yy68:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy69;
		default:	goto yy24;
		}
yy69:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy43;
		default:	goto yy24;
		}
yy70:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy90;
		default:	goto yy24;
		}
yy71:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy72;
		default:	goto yy24;
		}
yy72:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy73;
		default:	goto yy24;
		}
yy73:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy74;
		default:	goto yy24;
		}
yy74:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy75;
		default:	goto yy24;
		}
yy75:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy76;
		default:	goto yy24;
		}
yy76:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy77;
		default:	goto yy24;
		}
yy77:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy78;
		default:	goto yy24;
		}
yy78:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy79;
		default:	goto yy24;
		}
yy79:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy80;
		default:	goto yy24;
		}
yy80:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy81;
		default:	goto yy24;
		}
yy81:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy82;
		default:	goto yy24;
		}
yy82:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy83;
		default:	goto yy24;
		}
yy83:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy84;
		default:	goto yy24;
		}
yy84:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy85;
		default:	goto yy24;
		}
yy85:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy86;
		default:	goto yy24;
		}
yy86:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy87;
		default:	goto yy24;
		}
yy87:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy88;
		default:	goto yy24;
		}
yy88:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy89;
		default:	goto yy24;
		}
yy89:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy43;
		default:	goto yy24;
		}
yy90:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy91;
		default:	goto yy24;
		}
yy91:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy92;
		default:	goto yy24;
		}
yy92:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy93;
		default:	goto yy24;
		}
yy93:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy94;
		default:	goto yy24;
		}
yy94:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy95;
		default:	goto yy24;
		}
yy95:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy96;
		default:	goto yy24;
		}
yy96:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy97;
		default:	goto yy24;
		}
yy97:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy98;
		default:	goto yy24;
		}
yy98:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy43;
		default:	goto yy24;
		}
yy99:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy100;
		default:	goto yy24;
		}
yy100:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy101;
		default:	goto yy24;
		}
yy101:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy102;
		default:	goto yy24;
		}
yy102:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy103;
		default:	goto yy24;
		}
yy103:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy104;
		default:	goto yy24;
		}
yy104:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy105;
		default:	goto yy24;
		}
yy105:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy106;
		default:	goto yy24;
		}
yy106:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy107;
		default:	goto yy24;
		}
yy107:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy108;
		default:	goto yy24;
		}
yy108:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy109;
		default:	goto yy24;
		}
yy109:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy43;
		default:	goto yy24;
		}
yy110:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy111;
		default:	goto yy24;
		}
yy111:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy112;
		default:	goto yy24;
		}
yy112:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy113;
		default:	goto yy24;
		}
yy113:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy114;
		default:	goto yy24;
		}
yy114:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy115;
		default:	goto yy24;
		}
yy115:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy116;
		default:	goto yy24;
		}
yy116:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy117;
		default:	goto yy24;
		}
yy117:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy118;
		default:	goto yy24;
		}
yy118:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy119;
		default:	goto yy24;
		}
yy119:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy120;
		default:	goto yy24;
		}
yy120:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy122;
		default:	goto yy120;
		}
yy122:
#line 62 "detect.c"
		{ return XSS; }
#line 808 "<stdout>"
yy123:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy124;
		default:	goto yy24;
		}
yy124:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy125;
		default:	goto yy24;
		}
yy125:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy120;
		default:	goto yy24;
		}
yy126:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy131;
		case 'e':	goto yy129;
		case 'f':	goto yy133;
		case 'l':	goto yy128;
		case 'm':	goto yy132;
		case 'p':	goto yy130;
		case 's':	goto yy127;
		default:	goto yy24;
		}
yy127:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy165;
		default:	goto yy24;
		}
yy128:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy163;
		default:	goto yy24;
		}
yy129:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy160;
		default:	goto yy24;
		}
yy130:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy149;
		case 'r':	goto yy148;
		default:	goto yy24;
		}
yy131:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy145;
		default:	goto yy24;
		}
yy132:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy138;
		default:	goto yy24;
		}
yy133:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy134;
		default:	goto yy24;
		}
yy134:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy135;
		default:	goto yy24;
		}
yy135:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy136;
		default:	goto yy24;
		}
yy136:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy137;
		default:	goto yy24;
		}
yy137:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy120;
		default:	goto yy24;
		}
yy138:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy139;
		default:	goto yy24;
		}
yy139:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy140;
		default:	goto yy24;
		}
yy140:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy141;
		default:	goto yy24;
		}
yy141:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy142;
		default:	goto yy24;
		}
yy142:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy143;
		default:	goto yy24;
		}
yy143:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy144;
		default:	goto yy24;
		}
yy144:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy120;
		default:	goto yy24;
		}
yy145:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy146;
		default:	goto yy24;
		}
yy146:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy147;
		default:	goto yy24;
		}
yy147:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy120;
		default:	goto yy24;
		}
yy148:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy155;
		default:	goto yy24;
		}
yy149:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy150;
		default:	goto yy24;
		}
yy150:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy151;
		default:	goto yy24;
		}
yy151:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy152;
		default:	goto yy24;
		}
yy152:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy153;
		default:	goto yy24;
		}
yy153:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy154;
		default:	goto yy24;
		}
yy154:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy120;
		default:	goto yy24;
		}
yy155:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy156;
		default:	goto yy24;
		}
yy156:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy157;
		default:	goto yy24;
		}
yy157:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy158;
		default:	goto yy24;
		}
yy158:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy159;
		default:	goto yy24;
		}
yy159:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy120;
		default:	goto yy24;
		}
yy160:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy161;
		default:	goto yy24;
		}
yy161:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy162;
		default:	goto yy24;
		}
yy162:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy120;
		default:	goto yy24;
		}
yy163:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy164;
		default:	goto yy24;
		}
yy164:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy120;
		default:	goto yy24;
		}
yy165:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy166;
		default:	goto yy24;
		}
yy166:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy167;
		default:	goto yy24;
		}
yy167:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy120;
		default:	goto yy24;
		}
yy168:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy169;
		default:	goto yy24;
		}
yy169:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy120;
		default:	goto yy24;
		}
yy170:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy171;
		default:	goto yy24;
		}
yy171:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy173;
		default:	goto yy171;
		}
yy173:
#line 61 "detect.c"
		{ return SQLI; }
#line 1114 "<stdout>"
yy174:
		yych = (char)*++*p;
		switch (yych) {
		case '1':	goto yy171;
		default:	goto yy24;
		}
yy175:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy176;
		default:	goto yy24;
		}
yy176:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy177;
		default:	goto yy24;
		}
yy177:
		yych = (char)*++*p;
		switch (yych) {
		case '_':	goto yy178;
		default:	goto yy24;
		}
yy178:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy179;
		default:	goto yy24;
		}
yy179:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy180;
		default:	goto yy24;
		}
yy180:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy181;
		default:	goto yy24;
		}
yy181:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy171;
		default:	goto yy24;
		}
yy182:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy183;
		default:	goto yy24;
		}
yy183:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy184;
		default:	goto yy24;
		}
yy184:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy185;
		default:	goto yy24;
		}
yy185:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy186;
		default:	goto yy24;
		}
yy186:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy187;
		default:	goto yy24;
		}
yy187:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy171;
		default:	goto yy24;
		}
yy188:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy189;
		default:	goto yy24;
		}
yy189:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy190;
		default:	goto yy24;
		}
yy190:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy191;
		default:	goto yy24;
		}
yy191:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy171;
		default:	goto yy24;
		}
yy192:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy197;
		default:	goto yy24;
		}
yy193:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy194;
		default:	goto yy24;
		}
yy194:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy195;
		default:	goto yy24;
		}
yy195:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy196;
		default:	goto yy24;
		}
yy196:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy171;
		default:	goto yy24;
		}
yy197:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy198;
		default:	goto yy24;
		}
yy198:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy199;
		default:	goto yy24;
		}
yy199:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy120;
		default:	goto yy24;
		}
yy200:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy201;
		default:	goto yy24;
		}
yy201:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy202;
		default:	goto yy24;
		}
yy202:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy171;
		default:	goto yy24;
		}
yy203:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '%':	goto yy222;
		case '*':
		case '>':	goto yy207;
		case '.':	goto yy203;
		case '/':	goto yy221;
		case '1':	goto yy218;
		case '2':	goto yy219;
		case '@':	goto yy216;
		case '\\':	goto yy223;
		case 'a':	goto yy212;
		case 'e':	goto yy209;
		case 'f':	goto yy213;
		case 'i':	goto yy215;
		case 'l':	goto yy217;
		case 'o':	goto yy211;
		case 's':	goto yy210;
		case 'u':	goto yy214;
		default:	goto yy24;
		}
yy205:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy99;
		default:	goto yy24;
		}
yy206:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy23;
		default:	goto yy24;
		}
yy207:
		++*p;
		yych = (char)**p;
yy208:
		switch (yych) {
		case '%':	goto yy206;
		case '*':
		case '>':	goto yy207;
		case '.':	goto yy220;
		case '/':	goto yy205;
		case '1':	goto yy218;
		case '2':	goto yy219;
		case '@':	goto yy216;
		case 'a':	goto yy212;
		case 'e':	goto yy209;
		case 'f':	goto yy213;
		case 'i':	goto yy215;
		case 'l':	goto yy217;
		case 'o':	goto yy211;
		case 's':	goto yy210;
		case 'u':	goto yy214;
		default:	goto yy24;
		}
yy209:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy168;
		default:	goto yy24;
		}
yy210:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy192;
		case 'e':	goto yy193;
		default:	goto yy24;
		}
yy211:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy126;
		default:	goto yy24;
		}
yy212:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy123;
		default:	goto yy24;
		}
yy213:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy110;
		default:	goto yy24;
		}
yy214:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy200;
		default:	goto yy24;
		}
yy215:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy188;
		default:	goto yy24;
		}
yy216:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy182;
		default:	goto yy24;
		}
yy217:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy175;
		default:	goto yy24;
		}
yy218:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy174;
		default:	goto yy24;
		}
yy219:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy170;
		default:	goto yy24;
		}
yy220:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '%':	goto yy206;
		case '*':
		case '>':	goto yy207;
		case '.':	goto yy203;
		case '/':	goto yy205;
		case '1':	goto yy218;
		case '2':	goto yy219;
		case '@':	goto yy216;
		case 'a':	goto yy212;
		case 'e':	goto yy209;
		case 'f':	goto yy213;
		case 'i':	goto yy215;
		case 'l':	goto yy217;
		case 'o':	goto yy211;
		case 's':	goto yy210;
		case 'u':	goto yy214;
		default:	goto yy24;
		}
yy221:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy242;
		case 'e':	goto yy99;
		default:	goto yy24;
		}
yy222:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy226;
		default:	goto yy24;
		}
yy223:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy224;
		default:	goto yy24;
		}
yy224:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy225;
		default:	goto yy24;
		}
yy225:
		yych = (char)*++*p;
		switch (yych) {
		case '\\':	goto yy43;
		default:	goto yy24;
		}
yy226:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy26;
		case 'F':	goto yy227;
		case 'e':	goto yy25;
		case 'f':	goto yy228;
		default:	goto yy24;
		}
yy227:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy238;
		default:	goto yy24;
		}
yy228:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy229;
		default:	goto yy24;
		}
yy229:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy230;
		default:	goto yy24;
		}
yy230:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy231;
		default:	goto yy24;
		}
yy231:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy232;
		default:	goto yy24;
		}
yy232:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy233;
		default:	goto yy24;
		}
yy233:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy234;
		default:	goto yy24;
		}
yy234:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy235;
		default:	goto yy24;
		}
yy235:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy236;
		default:	goto yy24;
		}
yy236:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy237;
		default:	goto yy24;
		}
yy237:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy43;
		default:	goto yy24;
		}
yy238:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy239;
		default:	goto yy24;
		}
yy239:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy240;
		default:	goto yy24;
		}
yy240:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy241;
		default:	goto yy24;
		}
yy241:
		yych = (char)*++*p;
		switch (yych) {
		case 'F':	goto yy43;
		default:	goto yy24;
		}
yy242:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy243;
		default:	goto yy24;
		}
yy243:
		++*p;
		switch ((yych = (char)**p)) {
		case '/':	goto yy43;
		default:	goto yy24;
		}
	}


    }
}


int block_waf_level2(char** p, char** lex)
{
    char* marker;

    for (;;) {
    *lex = *p;
    
#line 58 "<stdout>"
	{
		char zzch;

		zzch = (char)**p;
		switch (zzch) {
		case 0x00:	goto zz28;
		case '\n':	goto zz26;
		case '"':	goto zz23;
		case '%':	goto zz11;
		case '&':	goto zz24;
		case '\'':	goto zz13;
		case ')':	goto zz6;
		case '*':
		case '>':	goto zz2;
		case '+':	goto zz14;
		case '.':	goto zz4;
		case '/':	goto zz25;
		case '1':	goto zz9;
		case '2':	goto zz10;
		case '<':	goto zz17;
		case '=':	goto zz22;
		case '@':	goto zz7;
		case 'a':	goto zz12;
		case 'c':	goto zz15;
		case 'e':	goto zz16;
		case 'f':	goto zz21;
		case 'i':	goto zz19;
		case 'l':	goto zz8;
		case 'o':	goto zz20;
		case 's':	goto zz18;
		case 'u':	goto zz5;
		default:	goto zz30;
		}
zz2:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case '"':
		case '%':
		case '&':
		case '\'':
		case ')':
		case '*':
		case '+':
		case '.':
		case '/':
		case '1':
		case '2':
		case '<':
		case '=':
		case '>':
		case '@':
		case 'a':
		case 'c':
		case 'e':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'u':	goto zz368;
		default:	goto zz3;
		}
zz3:

		{ continue; }

zz4:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case '"':
		case '%':
		case '&':
		case '\'':
		case ')':
		case '*':
		case '+':
		case '/':
		case '1':
		case '2':
		case '<':
		case '=':
		case '>':
		case '@':
		case 'a':
		case 'c':
		case 'e':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'u':	goto zz368;
		case '.':	goto zz363;
		default:	goto zz3;
		}
zz5:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'n':	goto zz350;
		default:	goto zz3;
		}
zz6:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case '-':	goto zz349;
		default:	goto zz3;
		}
zz7:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'v':	goto zz343;
		default:	goto zz3;
		}
zz8:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'o':	goto zz335;
		default:	goto zz3;
		}
zz9:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case ';':	goto zz333;
		case '=':	goto zz334;
		default:	goto zz3;
		}
zz10:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case ';':	goto zz331;
		case '=':	goto zz332;
		default:	goto zz3;
		}
zz11:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case '2':	goto zz215;
		case '3':	goto zz216;
		default:	goto zz3;
		}
zz12:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'l':	goto zz206;
		case 'n':	goto zz207;
		default:	goto zz3;
		}
zz13:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case ' ':	goto zz194;
		case ';':	goto zz195;
		default:	goto zz3;
		}
zz14:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'i':	goto zz189;
		default:	goto zz3;
		}
zz15:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'h':	goto zz183;
		default:	goto zz3;
		}
zz16:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'v':	goto zz172;
		case 'x':	goto zz171;
		default:	goto zz3;
		}
zz17:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'i':	goto zz164;
		case 's':	goto zz165;
		default:	goto zz3;
		}
zz18:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'c':	goto zz154;
		default:	goto zz3;
		}
zz19:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'm':	goto zz150;
		default:	goto zz3;
		}
zz20:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'n':	goto zz100;
		default:	goto zz3;
		}
zz21:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'r':	goto zz90;
		default:	goto zz3;
		}
zz22:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'j':	goto zz80;
		default:	goto zz3;
		}
zz23:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'j':	goto zz71;
		default:	goto zz3;
		}
zz24:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case '#':	goto zz47;
		case '{':	goto zz46;
		default:	goto zz3;
		}
zz25:
		zzch = (char)*(marker = ++*p);
		switch (zzch) {
		case 'e':	goto zz31;
		default:	goto zz3;
		}
zz26:
		++*p;

		{ return COUNTER; }

zz28:
		++*p;

		{ return END; }

zz30:
		zzch = (char)*++*p;
		goto zz3;
zz31:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz33;
		default:	goto zz32;
		}
zz32:
		*p = marker;
		goto zz3;
zz33:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz34;
		default:	goto zz32;
		}
zz34:
		zzch = (char)*++*p;
		switch (zzch) {
		case '/':	goto zz35;
		default:	goto zz32;
		}
zz35:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz36;
		default:	goto zz32;
		}
zz36:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz37;
		default:	goto zz32;
		}
zz37:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz38;
		default:	goto zz32;
		}
zz38:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz39;
		default:	goto zz32;
		}
zz39:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'w':	goto zz40;
		default:	goto zz32;
		}
zz40:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz41;
		default:	goto zz32;
		}
zz41:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz42;
		default:	goto zz32;
		}
zz42:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'd':	goto zz43;
		default:	goto zz32;
		}
zz43:
		++*p;
		zzch = (char)**p;
		switch (zzch) {
		case '\n':	goto zz45;
		default:	goto zz43;
		}
zz45:

		{ return PATHTRAVERSAL; }

zz46:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz69;
		default:	goto zz32;
		}
zz47:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz48;
		case '9':	goto zz50;
		case 'x':	goto zz49;
		default:	goto zz32;
		}
zz48:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz62;
		default:	goto zz32;
		}
zz49:
		zzch = (char)*++*p;
		switch (zzch) {
		case '6':	goto zz61;
		default:	goto zz32;
		}
zz50:
		zzch = (char)*++*p;
		switch (zzch) {
		case '7':	goto zz51;
		default:	goto zz32;
		}
zz51:
		zzch = (char)*++*p;
		switch (zzch) {
		case ';':	goto zz52;
		default:	goto zz32;
		}
zz52:
		zzch = (char)*++*p;
		switch (zzch) {
		case '&':	goto zz53;
		default:	goto zz32;
		}
zz53:
		zzch = (char)*++*p;
		switch (zzch) {
		case '#':	goto zz54;
		default:	goto zz32;
		}
zz54:
		zzch = (char)*++*p;
		switch (zzch) {
		case '1':	goto zz55;
		default:	goto zz32;
		}
zz55:
		zzch = (char)*++*p;
		switch (zzch) {
		case '1':	goto zz56;
		default:	goto zz32;
		}
zz56:
		zzch = (char)*++*p;
		switch (zzch) {
		case '8':	goto zz57;
		default:	goto zz32;
		}
zz57:
		zzch = (char)*++*p;
		switch (zzch) {
		case ';':	goto zz58;
		default:	goto zz32;
		}
zz58:
		++*p;
		zzch = (char)**p;
		switch (zzch) {
		case '\n':	goto zz60;
		default:	goto zz58;
		}
zz60:

		{ return XSS; }

zz61:
		zzch = (char)*++*p;
		switch (zzch) {
		case '1':	goto zz58;
		default:	goto zz32;
		}
zz62:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz63;
		default:	goto zz32;
		}
zz63:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz64;
		default:	goto zz32;
		}
zz64:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz66;
		case '1':	goto zz65;
		default:	goto zz32;
		}
zz65:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz68;
		default:	goto zz32;
		}
zz66:
		zzch = (char)*++*p;
		switch (zzch) {
		case '9':	goto zz67;
		default:	goto zz32;
		}
zz67:
		zzch = (char)*++*p;
		switch (zzch) {
		case '7':	goto zz58;
		default:	goto zz32;
		}
zz68:
		zzch = (char)*++*p;
		switch (zzch) {
		case '6':	goto zz58;
		default:	goto zz32;
		}
zz69:
		zzch = (char)*++*p;
		switch (zzch) {
		case ')':	goto zz70;
		default:	goto zz32;
		}
zz70:
		zzch = (char)*++*p;
		switch (zzch) {
		case '}':	goto zz58;
		default:	goto zz32;
		}
zz71:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz72;
		default:	goto zz32;
		}
zz72:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'v':	goto zz73;
		default:	goto zz32;
		}
zz73:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz74;
		default:	goto zz32;
		}
zz74:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz75;
		default:	goto zz32;
		}
zz75:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz76;
		default:	goto zz32;
		}
zz76:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz77;
		default:	goto zz32;
		}
zz77:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz78;
		default:	goto zz32;
		}
zz78:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz79;
		default:	goto zz32;
		}
zz79:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz58;
		default:	goto zz32;
		}
zz80:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz81;
		default:	goto zz32;
		}
zz81:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'v':	goto zz82;
		default:	goto zz32;
		}
zz82:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz83;
		default:	goto zz32;
		}
zz83:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz84;
		default:	goto zz32;
		}
zz84:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz85;
		default:	goto zz32;
		}
zz85:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz86;
		default:	goto zz32;
		}
zz86:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz87;
		default:	goto zz32;
		}
zz87:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz88;
		default:	goto zz32;
		}
zz88:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz89;
		default:	goto zz32;
		}
zz89:
		zzch = (char)*++*p;
		switch (zzch) {
		case ':':	goto zz58;
		default:	goto zz32;
		}
zz90:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz91;
		default:	goto zz32;
		}
zz91:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'm':	goto zz92;
		default:	goto zz32;
		}
zz92:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'C':	goto zz93;
		default:	goto zz32;
		}
zz93:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'h':	goto zz94;
		default:	goto zz32;
		}
zz94:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz95;
		default:	goto zz32;
		}
zz95:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz96;
		default:	goto zz32;
		}
zz96:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'C':	goto zz97;
		default:	goto zz32;
		}
zz97:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz98;
		default:	goto zz32;
		}
zz98:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'd':	goto zz99;
		default:	goto zz32;
		}
zz99:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz58;
		default:	goto zz32;
		}
zz100:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz105;
		case 'e':	goto zz103;
		case 'f':	goto zz107;
		case 'l':	goto zz102;
		case 'm':	goto zz106;
		case 'p':	goto zz104;
		case 's':	goto zz101;
		default:	goto zz32;
		}
zz101:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz146;
		default:	goto zz32;
		}
zz102:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz143;
		default:	goto zz32;
		}
zz103:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz139;
		default:	goto zz32;
		}
zz104:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz126;
		case 'r':	goto zz125;
		default:	goto zz32;
		}
zz105:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz121;
		default:	goto zz32;
		}
zz106:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz113;
		default:	goto zz32;
		}
zz107:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz108;
		default:	goto zz32;
		}
zz108:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz109;
		default:	goto zz32;
		}
zz109:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz110;
		default:	goto zz32;
		}
zz110:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz111;
		default:	goto zz32;
		}
zz111:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'h':	goto zz112;
		default:	goto zz32;
		}
zz112:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz113:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'u':	goto zz114;
		default:	goto zz32;
		}
zz114:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz115;
		default:	goto zz32;
		}
zz115:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz116;
		default:	goto zz32;
		}
zz116:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz117;
		default:	goto zz32;
		}
zz117:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'v':	goto zz118;
		default:	goto zz32;
		}
zz118:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz119;
		default:	goto zz32;
		}
zz119:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz120;
		default:	goto zz32;
		}
zz120:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz121:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz122;
		default:	goto zz32;
		}
zz122:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz123;
		default:	goto zz32;
		}
zz123:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'k':	goto zz124;
		default:	goto zz32;
		}
zz124:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz125:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz133;
		default:	goto zz32;
		}
zz126:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'g':	goto zz127;
		default:	goto zz32;
		}
zz127:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz128;
		default:	goto zz32;
		}
zz128:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz129;
		default:	goto zz32;
		}
zz129:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'h':	goto zz130;
		default:	goto zz32;
		}
zz130:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz131;
		default:	goto zz32;
		}
zz131:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'w':	goto zz132;
		default:	goto zz32;
		}
zz132:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz133:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'g':	goto zz134;
		default:	goto zz32;
		}
zz134:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz135;
		default:	goto zz32;
		}
zz135:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz136;
		default:	goto zz32;
		}
zz136:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz137;
		default:	goto zz32;
		}
zz137:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz138;
		default:	goto zz32;
		}
zz138:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz139:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz140;
		default:	goto zz32;
		}
zz140:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz141;
		default:	goto zz32;
		}
zz141:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz142;
		default:	goto zz32;
		}
zz142:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz143:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz144;
		default:	goto zz32;
		}
zz144:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'd':	goto zz145;
		default:	goto zz32;
		}
zz145:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz146:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz147;
		default:	goto zz32;
		}
zz147:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz148;
		default:	goto zz32;
		}
zz148:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz149;
		default:	goto zz32;
		}
zz149:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz58;
		default:	goto zz32;
		}
zz150:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'g':	goto zz151;
		default:	goto zz32;
		}
zz151:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz152;
		default:	goto zz32;
		}
zz152:
		zzch = (char)*++*p;
		switch (zzch) {
		case '3':	goto zz153;
		default:	goto zz32;
		}
zz153:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'E':	goto zz58;
		default:	goto zz32;
		}
zz154:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz155;
		default:	goto zz32;
		}
zz155:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz156;
		default:	goto zz32;
		}
zz156:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz157;
		default:	goto zz32;
		}
zz157:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz158;
		default:	goto zz32;
		}
zz158:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz159;
		default:	goto zz32;
		}
zz159:
		zzch = (char)*++*p;
		switch (zzch) {
		case '3':	goto zz160;
		default:	goto zz32;
		}
zz160:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'E':	goto zz161;
		default:	goto zz32;
		}
zz161:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz162;
		default:	goto zz32;
		}
zz162:
		zzch = (char)*++*p;
		switch (zzch) {
		case '3':	goto zz163;
		default:	goto zz32;
		}
zz163:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'C':	goto zz58;
		default:	goto zz32;
		}
zz164:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'm':	goto zz170;
		default:	goto zz32;
		}
zz165:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz166;
		default:	goto zz32;
		}
zz166:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz167;
		default:	goto zz32;
		}
zz167:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz168;
		default:	goto zz32;
		}
zz168:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz169;
		default:	goto zz32;
		}
zz169:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz58;
		default:	goto zz32;
		}
zz170:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'g':	goto zz58;
		default:	goto zz32;
		}
zz171:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz175;
		default:	goto zz32;
		}
zz172:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz173;
		default:	goto zz32;
		}
zz173:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz174;
		default:	goto zz32;
		}
zz174:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz58;
		default:	goto zz32;
		}
zz175:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz176;
		default:	goto zz32;
		}
zz176:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz177;
		default:	goto zz32;
		}
zz177:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz178;
		default:	goto zz32;
		}
zz178:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz179;
		default:	goto zz32;
		}
zz179:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz180;
		default:	goto zz32;
		}
zz180:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz181;
		default:	goto zz32;
		}
zz181:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz182;
		default:	goto zz32;
		}
zz182:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz58;
		default:	goto zz32;
		}
zz183:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz184;
		default:	goto zz32;
		}
zz184:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz185;
		default:	goto zz32;
		}
zz185:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz186;
		default:	goto zz32;
		}
zz186:
		++*p;
		zzch = (char)**p;
		switch (zzch) {
		case '\n':	goto zz188;
		default:	goto zz186;
		}
zz188:
		{ return SQLI; }
zz189:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz190;
		default:	goto zz32;
		}
zz190:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz191;
		default:	goto zz32;
		}
zz191:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'u':	goto zz192;
		default:	goto zz32;
		}
zz192:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz193;
		default:	goto zz32;
		}
zz193:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz186;
		default:	goto zz32;
		}
zz194:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'h':	goto zz196;
		case 's':	goto zz197;
		default:	goto zz32;
		}
zz195:
		zzch = (char)*++*p;
		switch (zzch) {
		case ' ':	goto zz186;
		default:	goto zz32;
		}
zz196:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz202;
		default:	goto zz32;
		}
zz197:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz198;
		default:	goto zz32;
		}
zz198:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz199;
		default:	goto zz32;
		}
zz199:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz200;
		default:	goto zz32;
		}
zz200:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz201;
		default:	goto zz32;
		}
zz201:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz186;
		default:	goto zz32;
		}
zz202:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'v':	goto zz203;
		default:	goto zz32;
		}
zz203:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz204;
		default:	goto zz32;
		}
zz204:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz205;
		default:	goto zz32;
		}
zz205:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'g':	goto zz186;
		default:	goto zz32;
		}
zz206:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz212;
		default:	goto zz32;
		}
zz207:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'd':	goto zz208;
		default:	goto zz32;
		}
zz208:
		zzch = (char)*++*p;
		switch (zzch) {
		case ' ':	goto zz209;
		default:	goto zz32;
		}
zz209:
		zzch = (char)*++*p;
		switch (zzch) {
		case '\'':	goto zz186;
		case '1':	goto zz210;
		default:	goto zz32;
		}
zz210:
		zzch = (char)*++*p;
		switch (zzch) {
		case '=':	goto zz211;
		default:	goto zz32;
		}
zz211:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz186;
		default:	goto zz32;
		}
zz212:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz213;
		default:	goto zz32;
		}
zz213:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz214;
		default:	goto zz32;
		}
zz214:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz58;
		default:	goto zz32;
		}
zz215:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz227;
		case '2':	goto zz225;
		case '5':	goto zz226;
		case 'e':	goto zz228;
		default:	goto zz32;
		}
zz216:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'C':	goto zz217;
		default:	goto zz32;
		}
zz217:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz218;
		case 's':	goto zz219;
		default:	goto zz32;
		}
zz218:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'm':	goto zz224;
		default:	goto zz32;
		}
zz219:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz220;
		default:	goto zz32;
		}
zz220:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz221;
		default:	goto zz32;
		}
zz221:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz222;
		default:	goto zz32;
		}
zz222:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'p':	goto zz223;
		default:	goto zz32;
		}
zz223:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz58;
		default:	goto zz32;
		}
zz224:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'g':	goto zz58;
		default:	goto zz32;
		}
zz225:
		zzch = (char)*++*p;
		switch (zzch) {
		case '+':	goto zz320;
		default:	goto zz32;
		}
zz226:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz290;
		default:	goto zz32;
		}
zz227:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz282;
		default:	goto zz32;
		}
zz228:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz229;
		default:	goto zz32;
		}
zz229:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz230;
		default:	goto zz32;
		}
zz230:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz231;
		default:	goto zz32;
		}
zz231:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz232;
		case '/':	goto zz233;
		case '\\':	goto zz234;
		default:	goto zz32;
		}
zz232:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz254;
		case '5':	goto zz253;
		default:	goto zz32;
		}
zz233:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz240;
		default:	goto zz32;
		}
zz234:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz235;
		default:	goto zz32;
		}
zz235:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz236;
		default:	goto zz32;
		}
zz236:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz237;
		default:	goto zz32;
		}
zz237:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz238;
		default:	goto zz32;
		}
zz238:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz239;
		default:	goto zz32;
		}
zz239:
		zzch = (char)*++*p;
		switch (zzch) {
		case '\\':	goto zz43;
		default:	goto zz32;
		}
zz240:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz241;
		default:	goto zz32;
		}
zz241:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz242;
		default:	goto zz32;
		}
zz242:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz243;
		default:	goto zz32;
		}
zz243:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz244;
		default:	goto zz32;
		}
zz244:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz245;
		default:	goto zz32;
		}
zz245:
		zzch = (char)*++*p;
		switch (zzch) {
		case '/':	goto zz246;
		default:	goto zz32;
		}
zz246:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz247;
		default:	goto zz32;
		}
zz247:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz248;
		default:	goto zz32;
		}
zz248:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz249;
		default:	goto zz32;
		}
zz249:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz250;
		default:	goto zz32;
		}
zz250:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz251;
		default:	goto zz32;
		}
zz251:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz252;
		default:	goto zz32;
		}
zz252:
		zzch = (char)*++*p;
		switch (zzch) {
		case '/':	goto zz43;
		default:	goto zz32;
		}
zz253:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz273;
		default:	goto zz32;
		}
zz254:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'f':	goto zz255;
		default:	goto zz32;
		}
zz255:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz256;
		default:	goto zz32;
		}
zz256:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz257;
		default:	goto zz32;
		}
zz257:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz258;
		default:	goto zz32;
		}
zz258:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz259;
		default:	goto zz32;
		}
zz259:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz260;
		default:	goto zz32;
		}
zz260:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz261;
		default:	goto zz32;
		}
zz261:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz262;
		default:	goto zz32;
		}
zz262:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz263;
		default:	goto zz32;
		}
zz263:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'f':	goto zz264;
		default:	goto zz32;
		}
zz264:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz265;
		default:	goto zz32;
		}
zz265:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz266;
		default:	goto zz32;
		}
zz266:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz267;
		default:	goto zz32;
		}
zz267:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz268;
		default:	goto zz32;
		}
zz268:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz269;
		default:	goto zz32;
		}
zz269:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz270;
		default:	goto zz32;
		}
zz270:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz271;
		default:	goto zz32;
		}
zz271:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz272;
		default:	goto zz32;
		}
zz272:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'f':	goto zz43;
		default:	goto zz32;
		}
zz273:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz274;
		default:	goto zz32;
		}
zz274:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz275;
		default:	goto zz32;
		}
zz275:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz276;
		default:	goto zz32;
		}
zz276:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz277;
		default:	goto zz32;
		}
zz277:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz278;
		default:	goto zz32;
		}
zz278:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz279;
		default:	goto zz32;
		}
zz279:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz280;
		default:	goto zz32;
		}
zz280:
		zzch = (char)*++*p;
		switch (zzch) {
		case '5':	goto zz281;
		default:	goto zz32;
		}
zz281:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz43;
		default:	goto zz32;
		}
zz282:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz283;
		default:	goto zz32;
		}
zz283:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz284;
		default:	goto zz32;
		}
zz284:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz285;
		default:	goto zz32;
		}
zz285:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz286;
		default:	goto zz32;
		}
zz286:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz287;
		default:	goto zz32;
		}
zz287:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz288;
		default:	goto zz32;
		}
zz288:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz289;
		default:	goto zz32;
		}
zz289:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz186;
		default:	goto zz32;
		}
zz290:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz291;
		case 'e':	goto zz292;
		default:	goto zz32;
		}
zz291:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz307;
		default:	goto zz32;
		}
zz292:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz293;
		default:	goto zz32;
		}
zz293:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz294;
		default:	goto zz32;
		}
zz294:
		zzch = (char)*++*p;
		switch (zzch) {
		case '5':	goto zz295;
		default:	goto zz32;
		}
zz295:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz296;
		default:	goto zz32;
		}
zz296:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz297;
		default:	goto zz32;
		}
zz297:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz298;
		default:	goto zz32;
		}
zz298:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz299;
		default:	goto zz32;
		}
zz299:
		zzch = (char)*++*p;
		switch (zzch) {
		case '5':	goto zz300;
		default:	goto zz32;
		}
zz300:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz301;
		default:	goto zz32;
		}
zz301:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz302;
		default:	goto zz32;
		}
zz302:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz303;
		default:	goto zz32;
		}
zz303:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz304;
		default:	goto zz32;
		}
zz304:
		zzch = (char)*++*p;
		switch (zzch) {
		case '5':	goto zz305;
		default:	goto zz32;
		}
zz305:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz306;
		default:	goto zz32;
		}
zz306:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz43;
		default:	goto zz32;
		}
zz307:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz308;
		default:	goto zz32;
		}
zz308:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'b':	goto zz309;
		default:	goto zz32;
		}
zz309:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz310;
		case 's':	goto zz311;
		case 'u':	goto zz312;
		default:	goto zz32;
		}
zz310:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz186;
		default:	goto zz32;
		}
zz311:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz316;
		default:	goto zz32;
		}
zz312:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz313;
		default:	goto zz32;
		}
zz313:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz314;
		default:	goto zz32;
		}
zz314:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz315;
		default:	goto zz32;
		}
zz315:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz186;
		default:	goto zz32;
		}
zz316:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz317;
		default:	goto zz32;
		}
zz317:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz318;
		default:	goto zz32;
		}
zz318:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz319;
		default:	goto zz32;
		}
zz319:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz186;
		default:	goto zz32;
		}
zz320:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz321;
		case 's':	goto zz323;
		case 'u':	goto zz322;
		default:	goto zz32;
		}
zz321:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz186;
		default:	goto zz32;
		}
zz322:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz328;
		default:	goto zz32;
		}
zz323:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz324;
		default:	goto zz32;
		}
zz324:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz325;
		default:	goto zz32;
		}
zz325:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz326;
		default:	goto zz32;
		}
zz326:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz327;
		default:	goto zz32;
		}
zz327:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz186;
		default:	goto zz32;
		}
zz328:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz329;
		default:	goto zz32;
		}
zz329:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz330;
		default:	goto zz32;
		}
zz330:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz186;
		default:	goto zz32;
		}
zz331:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz186;
		default:	goto zz32;
		}
zz332:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz186;
		default:	goto zz32;
		}
zz333:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz186;
		default:	goto zz32;
		}
zz334:
		zzch = (char)*++*p;
		switch (zzch) {
		case '1':	goto zz186;
		default:	goto zz32;
		}
zz335:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz336;
		default:	goto zz32;
		}
zz336:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'd':	goto zz337;
		default:	goto zz32;
		}
zz337:
		zzch = (char)*++*p;
		switch (zzch) {
		case '_':	goto zz338;
		default:	goto zz32;
		}
zz338:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'f':	goto zz339;
		default:	goto zz32;
		}
zz339:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz340;
		default:	goto zz32;
		}
zz340:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz341;
		default:	goto zz32;
		}
zz341:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz342;
		default:	goto zz32;
		}
zz342:
		zzch = (char)*++*p;
		switch (zzch) {
		case '(':	goto zz186;
		default:	goto zz32;
		}
zz343:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz344;
		default:	goto zz32;
		}
zz344:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz345;
		default:	goto zz32;
		}
zz345:
		zzch = (char)*++*p;
		switch (zzch) {
		case 's':	goto zz346;
		default:	goto zz32;
		}
zz346:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz347;
		default:	goto zz32;
		}
zz347:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz348;
		default:	goto zz32;
		}
zz348:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz186;
		default:	goto zz32;
		}
zz349:
		zzch = (char)*++*p;
		switch (zzch) {
		case '-':	goto zz186;
		default:	goto zz32;
		}
zz350:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz351;
		default:	goto zz32;
		}
zz351:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz352;
		default:	goto zz32;
		}
zz352:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz353;
		default:	goto zz32;
		}
zz353:
		zzch = (char)*++*p;
		switch (zzch) {
		case ' ':	goto zz354;
		default:	goto zz32;
		}
zz354:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'a':	goto zz356;
		case 's':	goto zz355;
		default:	goto zz32;
		}
zz355:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz358;
		default:	goto zz32;
		}
zz356:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz357;
		default:	goto zz32;
		}
zz357:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz186;
		default:	goto zz32;
		}
zz358:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz359;
		default:	goto zz32;
		}
zz359:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz360;
		default:	goto zz32;
		}
zz360:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz361;
		default:	goto zz32;
		}
zz361:
		zzch = (char)*++*p;
		switch (zzch) {
		case 't':	goto zz362;
		default:	goto zz32;
		}
zz362:
		zzch = (char)*++*p;
		switch (zzch) {
		case ' ':	goto zz186;
		default:	goto zz32;
		}
zz363:
		++*p;
		zzch = (char)**p;
		switch (zzch) {
		case '"':	goto zz377;
		case '%':	goto zz389;
		case '&':	goto zz378;
		case '\'':	goto zz385;
		case ')':	goto zz380;
		case '*':
		case '>':	goto zz367;
		case '+':	goto zz386;
		case '.':	goto zz363;
		case '/':	goto zz390;
		case '1':	goto zz383;
		case '2':	goto zz384;
		case '<':	goto zz370;
		case '=':	goto zz376;
		case '@':	goto zz381;
		case '\\':	goto zz391;
		case 'a':	goto zz374;
		case 'c':	goto zz387;
		case 'e':	goto zz369;
		case 'f':	goto zz375;
		case 'i':	goto zz372;
		case 'l':	goto zz382;
		case 'o':	goto zz373;
		case 's':	goto zz371;
		case 'u':	goto zz379;
		default:	goto zz32;
		}
zz365:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'e':	goto zz31;
		default:	goto zz32;
		}
zz366:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz215;
		case '3':	goto zz216;
		default:	goto zz32;
		}
zz367:
		++*p;
		zzch = (char)**p;
zz368:
		switch (zzch) {
		case '"':	goto zz377;
		case '%':	goto zz366;
		case '&':	goto zz378;
		case '\'':	goto zz385;
		case ')':	goto zz380;
		case '*':
		case '>':	goto zz367;
		case '+':	goto zz386;
		case '.':	goto zz388;
		case '/':	goto zz365;
		case '1':	goto zz383;
		case '2':	goto zz384;
		case '<':	goto zz370;
		case '=':	goto zz376;
		case '@':	goto zz381;
		case 'a':	goto zz374;
		case 'c':	goto zz387;
		case 'e':	goto zz369;
		case 'f':	goto zz375;
		case 'i':	goto zz372;
		case 'l':	goto zz382;
		case 'o':	goto zz373;
		case 's':	goto zz371;
		case 'u':	goto zz379;
		default:	goto zz32;
		}
zz369:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'v':	goto zz172;
		case 'x':	goto zz171;
		default:	goto zz32;
		}
zz370:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz164;
		case 's':	goto zz165;
		default:	goto zz32;
		}
zz371:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'c':	goto zz154;
		default:	goto zz32;
		}
zz372:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'm':	goto zz150;
		default:	goto zz32;
		}
zz373:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz100;
		default:	goto zz32;
		}
zz374:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'l':	goto zz206;
		case 'n':	goto zz207;
		default:	goto zz32;
		}
zz375:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'r':	goto zz90;
		default:	goto zz32;
		}
zz376:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'j':	goto zz80;
		default:	goto zz32;
		}
zz377:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'j':	goto zz71;
		default:	goto zz32;
		}
zz378:
		zzch = (char)*++*p;
		switch (zzch) {
		case '#':	goto zz47;
		case '{':	goto zz46;
		default:	goto zz32;
		}
zz379:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'n':	goto zz350;
		default:	goto zz32;
		}
zz380:
		zzch = (char)*++*p;
		switch (zzch) {
		case '-':	goto zz349;
		default:	goto zz32;
		}
zz381:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'v':	goto zz343;
		default:	goto zz32;
		}
zz382:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'o':	goto zz335;
		default:	goto zz32;
		}
zz383:
		zzch = (char)*++*p;
		switch (zzch) {
		case ';':	goto zz333;
		case '=':	goto zz334;
		default:	goto zz32;
		}
zz384:
		zzch = (char)*++*p;
		switch (zzch) {
		case ';':	goto zz331;
		case '=':	goto zz332;
		default:	goto zz32;
		}
zz385:
		zzch = (char)*++*p;
		switch (zzch) {
		case ' ':	goto zz194;
		case ';':	goto zz195;
		default:	goto zz32;
		}
zz386:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'i':	goto zz189;
		default:	goto zz32;
		}
zz387:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'h':	goto zz183;
		default:	goto zz32;
		}
zz388:
		++*p;
		zzch = (char)**p;
		switch (zzch) {
		case '"':	goto zz377;
		case '%':	goto zz366;
		case '&':	goto zz378;
		case '\'':	goto zz385;
		case ')':	goto zz380;
		case '*':
		case '>':	goto zz367;
		case '+':	goto zz386;
		case '.':	goto zz363;
		case '/':	goto zz365;
		case '1':	goto zz383;
		case '2':	goto zz384;
		case '<':	goto zz370;
		case '=':	goto zz376;
		case '@':	goto zz381;
		case 'a':	goto zz374;
		case 'c':	goto zz387;
		case 'e':	goto zz369;
		case 'f':	goto zz375;
		case 'i':	goto zz372;
		case 'l':	goto zz382;
		case 'o':	goto zz373;
		case 's':	goto zz371;
		case 'u':	goto zz379;
		default:	goto zz32;
		}
zz389:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz396;
		case '3':	goto zz216;
		default:	goto zz32;
		}
zz390:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz394;
		case 'e':	goto zz31;
		default:	goto zz32;
		}
zz391:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz392;
		default:	goto zz32;
		}
zz392:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz393;
		default:	goto zz32;
		}
zz393:
		zzch = (char)*++*p;
		switch (zzch) {
		case '\\':	goto zz43;
		default:	goto zz32;
		}
zz394:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz395;
		default:	goto zz32;
		}
zz395:
		zzch = (char)*++*p;
		switch (zzch) {
		case '/':	goto zz43;
		default:	goto zz32;
		}
zz396:
		zzch = (char)*++*p;
		switch (zzch) {
		case '0':	goto zz227;
		case '2':	goto zz225;
		case '5':	goto zz226;
		case 'F':	goto zz397;
		case 'e':	goto zz228;
		case 'f':	goto zz398;
		default:	goto zz32;
		}
zz397:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz408;
		default:	goto zz32;
		}
zz398:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz399;
		default:	goto zz32;
		}
zz399:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz400;
		default:	goto zz32;
		}
zz400:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz401;
		default:	goto zz32;
		}
zz401:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz402;
		default:	goto zz32;
		}
zz402:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'f':	goto zz403;
		default:	goto zz32;
		}
zz403:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz404;
		default:	goto zz32;
		}
zz404:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz405;
		default:	goto zz32;
		}
zz405:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz406;
		default:	goto zz32;
		}
zz406:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz407;
		default:	goto zz32;
		}
zz407:
		zzch = (char)*++*p;
		switch (zzch) {
		case 'f':	goto zz43;
		default:	goto zz32;
		}
zz408:
		zzch = (char)*++*p;
		switch (zzch) {
		case '.':	goto zz409;
		default:	goto zz32;
		}
zz409:
		zzch = (char)*++*p;
		switch (zzch) {
		case '%':	goto zz410;
		default:	goto zz32;
		}
zz410:
		zzch = (char)*++*p;
		switch (zzch) {
		case '2':	goto zz411;
		default:	goto zz32;
		}
zz411:
		++*p;
		switch ((zzch = (char)**p)) {
		case 'F':	goto zz43;
		default:	goto zz32;
		}
	}


    }
}



