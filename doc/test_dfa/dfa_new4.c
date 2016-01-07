// test example DFA
#line 1 "testdfa.c"
#line 1 "wafblock.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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





// random case return string, input= tomato output=ToMatO or tOmATo...
char *all2lowcase(char *str)
{
	char *str_new=malloc(sizeof(char)*strlen(str)+1);
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

enum {
  SQLI,XSS,PATHTRAVERSAL,COUNTER,END
};

//read lines of file
char *ReadLines(char * NameFile)
{
	FILE * arq=NULL;

	arq = fopen(NameFile, "rx");

	if( arq == NULL )
	{
		exit(1);
	}

	char *lineBuffer=calloc(1,1); 
	char line[2048];

	while( fgets(line,sizeof line,arq) )  
	{

		 	lineBuffer=realloc(lineBuffer,strlen(lineBuffer)+strlen(line));
		 	strncat(lineBuffer,line,2048);
	
	}

        lineBuffer=realloc(lineBuffer,strlen(lineBuffer)+4);
        strncat(lineBuffer," \n",4);
 
	if( fclose(arq) == EOF )
	{
		exit(1);
	}

	arq=NULL;

	lineBuffer[strlen(lineBuffer)-1]='\0';


	char *tmp=lineBuffer;
	free(lineBuffer);

	return tmp;
}

int parse_ion(char** p, char** lex)
{
    char* marker;

    for (;;) {
    *lex = *p;
    
#line 179 "<stdout>"
	{
		char yych;

		yych = (char)**p;
		switch (yych) {
		case 0x00:	goto yy32;
		case '\n':	goto yy30;
		case '"':	goto yy25;
		case '%':	goto yy15;
		case '&':	goto yy26;
		case '\'':	goto yy9;
		case '(':	goto yy8;
		case ')':	goto yy6;
		case '*':
		case '>':	goto yy2;
		case '+':	goto yy17;
		case ',':	goto yy12;
		case '.':	goto yy4;
		case '/':	goto yy28;
		case '0':	goto yy29;
		case '1':	goto yy13;
		case '2':	goto yy14;
		case '<':	goto yy20;
		case '=':	goto yy24;
		case '@':	goto yy10;
		case '\\':	goto yy27;
		case 'a':	goto yy16;
		case 'c':	goto yy18;
		case 'e':	goto yy19;
		case 'f':	goto yy23;
		case 'i':	goto yy21;
		case 'l':	goto yy11;
		case 'o':	goto yy22;
		case 's':	goto yy7;
		case 'u':	goto yy5;
		default:	goto yy34;
		}
yy2:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '"':
		case '%':
		case '&':
		case '\'':
		case '(':
		case ')':
		case '*':
		case '+':
		case ',':
		case '.':
		case '/':
		case '0':
		case '1':
		case '2':
		case '<':
		case '=':
		case '>':
		case '@':
		case '\\':
		case 'a':
		case 'c':
		case 'e':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'u':	goto yy537;
		default:	goto yy3;
		}
yy3:
#line 187 "testdfa.c"
		{ continue; }
#line 253 "<stdout>"
yy4:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '"':
		case '%':
		case '&':
		case '\'':
		case '(':
		case ')':
		case '*':
		case '+':
		case ',':
		case '/':
		case '0':
		case '1':
		case '2':
		case '<':
		case '=':
		case '>':
		case '@':
		case '\\':
		case 'a':
		case 'c':
		case 'e':
		case 'f':
		case 'i':
		case 'l':
		case 'o':
		case 's':
		case 'u':	goto yy537;
		case '.':	goto yy530;
		default:	goto yy3;
		}
yy5:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy519;
		default:	goto yy3;
		}
yy6:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '-':	goto yy513;
		case 's':	goto yy514;
		default:	goto yy3;
		}
yy7:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'c':	goto yy498;
		case 'e':	goto yy499;
		default:	goto yy3;
		}
yy8:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'u':	goto yy494;
		default:	goto yy3;
		}
yy9:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case ';':	goto yy210;
		case 'h':	goto yy481;
		case 's':	goto yy480;
		case 'u':	goto yy482;
		default:	goto yy3;
		}
yy10:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'v':	goto yy474;
		default:	goto yy3;
		}
yy11:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'o':	goto yy466;
		default:	goto yy3;
		}
yy12:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'b':	goto yy457;
		default:	goto yy3;
		}
yy13:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case ';':	goto yy455;
		case '=':	goto yy456;
		default:	goto yy3;
		}
yy14:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case ';':	goto yy453;
		case '=':	goto yy454;
		default:	goto yy3;
		}
yy15:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '%':	goto yy227;
		case '2':	goto yy228;
		case '3':	goto yy231;
		case '5':	goto yy230;
		case 'c':	goto yy229;
		default:	goto yy3;
		}
yy16:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'l':	goto yy218;
		case 'n':	goto yy219;
		default:	goto yy3;
		}
yy17:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'i':	goto yy213;
		default:	goto yy3;
		}
yy18:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'h':	goto yy207;
		default:	goto yy3;
		}
yy19:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'v':	goto yy196;
		case 'x':	goto yy195;
		default:	goto yy3;
		}
yy20:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'i':	goto yy188;
		case 's':	goto yy189;
		default:	goto yy3;
		}
yy21:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'm':	goto yy184;
		default:	goto yy3;
		}
yy22:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'n':	goto yy134;
		default:	goto yy3;
		}
yy23:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'r':	goto yy124;
		default:	goto yy3;
		}
yy24:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'j':	goto yy114;
		default:	goto yy3;
		}
yy25:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'j':	goto yy105;
		default:	goto yy3;
		}
yy26:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '#':	goto yy81;
		case '{':	goto yy80;
		default:	goto yy3;
		}
yy27:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '%':	goto yy68;
		default:	goto yy3;
		}
yy28:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'e':	goto yy57;
		default:	goto yy3;
		}
yy29:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '%':	goto yy35;
		default:	goto yy3;
		}
yy30:
		++*p;
#line 185 "testdfa.c"
		{ return COUNTER; }
#line 456 "<stdout>"
yy32:
		++*p;
#line 186 "testdfa.c"
		{ return END; }
#line 461 "<stdout>"
yy34:
		yych = (char)*++*p;
		goto yy3;
yy35:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy37;
		default:	goto yy36;
		}
yy36:
		*p = marker;
		goto yy3;
yy37:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy38;
		default:	goto yy36;
		}
yy38:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy39;
		default:	goto yy36;
		}
yy39:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy40;
		default:	goto yy36;
		}
yy40:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy41;
		default:	goto yy36;
		}
yy41:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy42;
		default:	goto yy36;
		}
yy42:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy43;
		default:	goto yy36;
		}
yy43:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy44;
		default:	goto yy36;
		}
yy44:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy45;
		default:	goto yy36;
		}
yy45:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy46;
		default:	goto yy36;
		}
yy46:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy47;
		default:	goto yy36;
		}
yy47:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy48;
		default:	goto yy36;
		}
yy48:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy49;
		default:	goto yy36;
		}
yy49:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy50;
		default:	goto yy36;
		}
yy50:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy51;
		default:	goto yy36;
		}
yy51:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy52;
		default:	goto yy36;
		}
yy52:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy53;
		default:	goto yy36;
		}
yy53:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy54;
		default:	goto yy36;
		}
yy54:
		++*p;
		yych = (char)**p;
yy55:
		switch (yych) {
		case '\n':	goto yy56;
		default:	goto yy54;
		}
yy56:

		{ return PATHTRAVERSAL; }

yy57:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy58;
		default:	goto yy36;
		}
yy58:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy59;
		default:	goto yy36;
		}
yy59:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy60;
		default:	goto yy36;
		}
yy60:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy61;
		default:	goto yy36;
		}
yy61:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy62;
		default:	goto yy36;
		}
yy62:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy63;
		default:	goto yy36;
		}
yy63:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy64;
		default:	goto yy36;
		}
yy64:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy65;
		default:	goto yy36;
		}
yy65:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy66;
		default:	goto yy36;
		}
yy66:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy67;
		default:	goto yy36;
		}
yy67:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy54;
		default:	goto yy36;
		}
yy68:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy69;
		default:	goto yy36;
		}
yy69:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy70;
		default:	goto yy36;
		}
yy70:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy71;
		default:	goto yy36;
		}
yy71:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy72;
		default:	goto yy36;
		}
yy72:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy73;
		default:	goto yy36;
		}
yy73:
		yych = (char)*++*p;
		switch (yych) {
		case '\\':	goto yy74;
		default:	goto yy36;
		}
yy74:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy75;
		default:	goto yy36;
		}
yy75:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy76;
		default:	goto yy36;
		}
yy76:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy77;
		default:	goto yy36;
		}
yy77:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy78;
		default:	goto yy36;
		}
yy78:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy79;
		default:	goto yy36;
		}
yy79:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy54;
		default:	goto yy36;
		}
yy80:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy103;
		default:	goto yy36;
		}
yy81:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy82;
		case '9':	goto yy84;
		case 'x':	goto yy83;
		default:	goto yy36;
		}
yy82:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy96;
		default:	goto yy36;
		}
yy83:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy95;
		default:	goto yy36;
		}
yy84:
		yych = (char)*++*p;
		switch (yych) {
		case '7':	goto yy85;
		default:	goto yy36;
		}
yy85:
		yych = (char)*++*p;
		switch (yych) {
		case ';':	goto yy86;
		default:	goto yy36;
		}
yy86:
		yych = (char)*++*p;
		switch (yych) {
		case '&':	goto yy87;
		default:	goto yy36;
		}
yy87:
		yych = (char)*++*p;
		switch (yych) {
		case '#':	goto yy88;
		default:	goto yy36;
		}
yy88:
		yych = (char)*++*p;
		switch (yych) {
		case '1':	goto yy89;
		default:	goto yy36;
		}
yy89:
		yych = (char)*++*p;
		switch (yych) {
		case '1':	goto yy90;
		default:	goto yy36;
		}
yy90:
		yych = (char)*++*p;
		switch (yych) {
		case '8':	goto yy91;
		default:	goto yy36;
		}
yy91:
		yych = (char)*++*p;
		switch (yych) {
		case ';':	goto yy92;
		default:	goto yy36;
		}
yy92:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy94;
		default:	goto yy92;
		}
yy94:

		{ return XSS; }

yy95:
		yych = (char)*++*p;
		switch (yych) {
		case '1':	goto yy92;
		default:	goto yy36;
		}
yy96:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy97;
		default:	goto yy36;
		}
yy97:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy98;
		default:	goto yy36;
		}
yy98:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy100;
		case '1':	goto yy99;
		default:	goto yy36;
		}
yy99:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy102;
		default:	goto yy36;
		}
yy100:
		yych = (char)*++*p;
		switch (yych) {
		case '9':	goto yy101;
		default:	goto yy36;
		}
yy101:
		yych = (char)*++*p;
		switch (yych) {
		case '7':	goto yy92;
		default:	goto yy36;
		}
yy102:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy92;
		default:	goto yy36;
		}
yy103:
		yych = (char)*++*p;
		switch (yych) {
		case ')':	goto yy104;
		default:	goto yy36;
		}
yy104:
		yych = (char)*++*p;
		switch (yych) {
		case '}':	goto yy92;
		default:	goto yy36;
		}
yy105:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy106;
		default:	goto yy36;
		}
yy106:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy107;
		default:	goto yy36;
		}
yy107:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy108;
		default:	goto yy36;
		}
yy108:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy109;
		default:	goto yy36;
		}
yy109:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy110;
		default:	goto yy36;
		}
yy110:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy111;
		default:	goto yy36;
		}
yy111:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy112;
		default:	goto yy36;
		}
yy112:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy113;
		default:	goto yy36;
		}
yy113:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy92;
		default:	goto yy36;
		}
yy114:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy115;
		default:	goto yy36;
		}
yy115:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy116;
		default:	goto yy36;
		}
yy116:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy117;
		default:	goto yy36;
		}
yy117:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy118;
		default:	goto yy36;
		}
yy118:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy119;
		default:	goto yy36;
		}
yy119:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy120;
		default:	goto yy36;
		}
yy120:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy121;
		default:	goto yy36;
		}
yy121:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy122;
		default:	goto yy36;
		}
yy122:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy123;
		default:	goto yy36;
		}
yy123:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy92;
		default:	goto yy36;
		}
yy124:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy125;
		default:	goto yy36;
		}
yy125:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy126;
		default:	goto yy36;
		}
yy126:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy127;
		default:	goto yy36;
		}
yy127:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy128;
		default:	goto yy36;
		}
yy128:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy129;
		default:	goto yy36;
		}
yy129:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy130;
		default:	goto yy36;
		}
yy130:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy131;
		default:	goto yy36;
		}
yy131:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy132;
		default:	goto yy36;
		}
yy132:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy133;
		default:	goto yy36;
		}
yy133:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy92;
		default:	goto yy36;
		}
yy134:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy139;
		case 'e':	goto yy137;
		case 'f':	goto yy141;
		case 'l':	goto yy136;
		case 'm':	goto yy140;
		case 'p':	goto yy138;
		case 's':	goto yy135;
		default:	goto yy36;
		}
yy135:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy180;
		default:	goto yy36;
		}
yy136:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy177;
		default:	goto yy36;
		}
yy137:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy173;
		default:	goto yy36;
		}
yy138:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy160;
		case 'r':	goto yy159;
		default:	goto yy36;
		}
yy139:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy155;
		default:	goto yy36;
		}
yy140:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy147;
		default:	goto yy36;
		}
yy141:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy142;
		default:	goto yy36;
		}
yy142:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy143;
		default:	goto yy36;
		}
yy143:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy144;
		default:	goto yy36;
		}
yy144:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy145;
		default:	goto yy36;
		}
yy145:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy146;
		default:	goto yy36;
		}
yy146:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy147:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy148;
		default:	goto yy36;
		}
yy148:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy149;
		default:	goto yy36;
		}
yy149:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy150;
		default:	goto yy36;
		}
yy150:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy151;
		default:	goto yy36;
		}
yy151:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy152;
		default:	goto yy36;
		}
yy152:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy153;
		default:	goto yy36;
		}
yy153:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy154;
		default:	goto yy36;
		}
yy154:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy155:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy156;
		default:	goto yy36;
		}
yy156:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy157;
		default:	goto yy36;
		}
yy157:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy158;
		default:	goto yy36;
		}
yy158:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy159:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy167;
		default:	goto yy36;
		}
yy160:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy161;
		default:	goto yy36;
		}
yy161:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy162;
		default:	goto yy36;
		}
yy162:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy163;
		default:	goto yy36;
		}
yy163:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy164;
		default:	goto yy36;
		}
yy164:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy165;
		default:	goto yy36;
		}
yy165:
		yych = (char)*++*p;
		switch (yych) {
		case 'w':	goto yy166;
		default:	goto yy36;
		}
yy166:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy167:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy168;
		default:	goto yy36;
		}
yy168:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy169;
		default:	goto yy36;
		}
yy169:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy170;
		default:	goto yy36;
		}
yy170:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy171;
		default:	goto yy36;
		}
yy171:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy172;
		default:	goto yy36;
		}
yy172:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy173:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy174;
		default:	goto yy36;
		}
yy174:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy175;
		default:	goto yy36;
		}
yy175:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy176;
		default:	goto yy36;
		}
yy176:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy177:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy178;
		default:	goto yy36;
		}
yy178:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy179;
		default:	goto yy36;
		}
yy179:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy180:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy181;
		default:	goto yy36;
		}
yy181:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy182;
		default:	goto yy36;
		}
yy182:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy183;
		default:	goto yy36;
		}
yy183:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy92;
		default:	goto yy36;
		}
yy184:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy185;
		default:	goto yy36;
		}
yy185:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy186;
		default:	goto yy36;
		}
yy186:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy187;
		default:	goto yy36;
		}
yy187:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':	goto yy92;
		default:	goto yy36;
		}
yy188:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy194;
		default:	goto yy36;
		}
yy189:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy190;
		default:	goto yy36;
		}
yy190:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy191;
		default:	goto yy36;
		}
yy191:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy192;
		default:	goto yy36;
		}
yy192:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy193;
		default:	goto yy36;
		}
yy193:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy92;
		default:	goto yy36;
		}
yy194:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy92;
		default:	goto yy36;
		}
yy195:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy199;
		default:	goto yy36;
		}
yy196:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy197;
		default:	goto yy36;
		}
yy197:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy198;
		default:	goto yy36;
		}
yy198:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy92;
		default:	goto yy36;
		}
yy199:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy200;
		default:	goto yy36;
		}
yy200:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy201;
		default:	goto yy36;
		}
yy201:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy202;
		default:	goto yy36;
		}
yy202:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy203;
		default:	goto yy36;
		}
yy203:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy204;
		default:	goto yy36;
		}
yy204:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy205;
		default:	goto yy36;
		}
yy205:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy206;
		default:	goto yy36;
		}
yy206:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy92;
		default:	goto yy36;
		}
yy207:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy208;
		default:	goto yy36;
		}
yy208:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy209;
		default:	goto yy36;
		}
yy209:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy210:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy212;
		default:	goto yy210;
		}
yy212:
#line 182 "testdfa.c"
		{ return SQLI; }
#line 1519 "<stdout>"
yy213:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy214;
		default:	goto yy36;
		}
yy214:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy215;
		default:	goto yy36;
		}
yy215:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy216;
		default:	goto yy36;
		}
yy216:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy217;
		default:	goto yy36;
		}
yy217:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy210;
		default:	goto yy36;
		}
yy218:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy224;
		default:	goto yy36;
		}
yy219:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy220;
		default:	goto yy36;
		}
yy220:
		yych = (char)*++*p;
		switch (yych) {
		case ' ':	goto yy221;
		default:	goto yy36;
		}
yy221:
		yych = (char)*++*p;
		switch (yych) {
		case '\'':	goto yy210;
		case '1':	goto yy222;
		default:	goto yy36;
		}
yy222:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy223;
		default:	goto yy36;
		}
yy223:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy224:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy225;
		default:	goto yy36;
		}
yy225:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy226;
		default:	goto yy36;
		}
yy226:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy92;
		default:	goto yy36;
		}
yy227:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy424;
		default:	goto yy36;
		}
yy228:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy289;
		case '2':	goto yy287;
		case '5':	goto yy288;
		case 'e':	goto yy290;
		default:	goto yy36;
		}
yy229:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy247;
		case '1':	goto yy248;
		default:	goto yy36;
		}
yy230:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy240;
		default:	goto yy36;
		}
yy231:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy232;
		default:	goto yy36;
		}
yy232:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy233;
		case 's':	goto yy234;
		default:	goto yy36;
		}
yy233:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy239;
		default:	goto yy36;
		}
yy234:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy235;
		default:	goto yy36;
		}
yy235:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy236;
		default:	goto yy36;
		}
yy236:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy237;
		default:	goto yy36;
		}
yy237:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy238;
		default:	goto yy36;
		}
yy238:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy92;
		default:	goto yy36;
		}
yy239:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy92;
		default:	goto yy36;
		}
yy240:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy241;
		default:	goto yy36;
		}
yy241:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy242;
		default:	goto yy36;
		}
yy242:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy243;
		default:	goto yy36;
		}
yy243:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy244;
		default:	goto yy36;
		}
yy244:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy245;
		default:	goto yy36;
		}
yy245:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy246;
		default:	goto yy36;
		}
yy246:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy54;
		default:	goto yy36;
		}
yy247:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy261;
		default:	goto yy36;
		}
yy248:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy249;
		default:	goto yy36;
		}
yy249:
		yych = (char)*++*p;
		switch (yych) {
		case '9':	goto yy250;
		default:	goto yy36;
		}
yy250:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy251;
		default:	goto yy36;
		}
yy251:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy252;
		default:	goto yy36;
		}
yy252:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy253;
		default:	goto yy36;
		}
yy253:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy254;
		default:	goto yy36;
		}
yy254:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy255;
		default:	goto yy36;
		}
yy255:
		yych = (char)*++*p;
		switch (yych) {
		case '1':	goto yy256;
		default:	goto yy36;
		}
yy256:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy257;
		default:	goto yy36;
		}
yy257:
		yych = (char)*++*p;
		switch (yych) {
		case '9':	goto yy258;
		default:	goto yy36;
		}
yy258:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy259;
		default:	goto yy36;
		}
yy259:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy260;
		default:	goto yy36;
		}
yy260:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy54;
		default:	goto yy36;
		}
yy261:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy262;
		default:	goto yy36;
		}
yy262:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy264;
		case 'f':	goto yy263;
		default:	goto yy36;
		}
yy263:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy276;
		default:	goto yy36;
		}
yy264:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy265;
		default:	goto yy36;
		}
yy265:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy266;
		default:	goto yy36;
		}
yy266:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy267;
		default:	goto yy36;
		}
yy267:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy268;
		default:	goto yy36;
		}
yy268:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy269;
		default:	goto yy36;
		}
yy269:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy270;
		default:	goto yy36;
		}
yy270:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy271;
		default:	goto yy55;
		}
yy271:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy272;
		default:	goto yy55;
		}
yy272:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy273;
		default:	goto yy55;
		}
yy273:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy274;
		default:	goto yy55;
		}
yy274:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy275;
		default:	goto yy55;
		}
yy275:
		yych = (char)*++*p;
		goto yy55;
yy276:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy277;
		default:	goto yy36;
		}
yy277:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy278;
		default:	goto yy36;
		}
yy278:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy279;
		default:	goto yy36;
		}
yy279:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy280;
		default:	goto yy36;
		}
yy280:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy281;
		default:	goto yy36;
		}
yy281:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy282;
		default:	goto yy36;
		}
yy282:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy283;
		default:	goto yy36;
		}
yy283:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy284;
		default:	goto yy36;
		}
yy284:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy285;
		default:	goto yy36;
		}
yy285:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy286;
		default:	goto yy36;
		}
yy286:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy54;
		default:	goto yy36;
		}
yy287:
		yych = (char)*++*p;
		switch (yych) {
		case '+':	goto yy413;
		default:	goto yy36;
		}
yy288:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy357;
		case '5':	goto yy359;
		case 'c':	goto yy358;
		default:	goto yy36;
		}
yy289:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy349;
		default:	goto yy36;
		}
yy290:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy291;
		default:	goto yy36;
		}
yy291:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy292;
		default:	goto yy36;
		}
yy292:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy293;
		default:	goto yy36;
		}
yy293:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy295;
		case '/':	goto yy294;
		case '\\':	goto yy296;
		default:	goto yy36;
		}
yy294:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy331;
		case '2':	goto yy332;
		default:	goto yy36;
		}
yy295:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy303;
		case '5':	goto yy302;
		default:	goto yy36;
		}
yy296:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy297;
		default:	goto yy36;
		}
yy297:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy298;
		default:	goto yy36;
		}
yy298:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy299;
		default:	goto yy36;
		}
yy299:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy300;
		default:	goto yy36;
		}
yy300:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy301;
		default:	goto yy36;
		}
yy301:
		yych = (char)*++*p;
		switch (yych) {
		case '\\':	goto yy54;
		default:	goto yy36;
		}
yy302:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy322;
		default:	goto yy36;
		}
yy303:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy304;
		default:	goto yy36;
		}
yy304:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy305;
		default:	goto yy36;
		}
yy305:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy306;
		default:	goto yy36;
		}
yy306:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy307;
		default:	goto yy36;
		}
yy307:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy308;
		default:	goto yy36;
		}
yy308:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy309;
		default:	goto yy36;
		}
yy309:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy310;
		default:	goto yy36;
		}
yy310:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy311;
		default:	goto yy36;
		}
yy311:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy312;
		default:	goto yy36;
		}
yy312:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy313;
		default:	goto yy36;
		}
yy313:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy314;
		default:	goto yy36;
		}
yy314:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy315;
		default:	goto yy36;
		}
yy315:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy316;
		default:	goto yy36;
		}
yy316:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy317;
		default:	goto yy36;
		}
yy317:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy318;
		default:	goto yy36;
		}
yy318:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy319;
		default:	goto yy36;
		}
yy319:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy320;
		default:	goto yy36;
		}
yy320:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy321;
		default:	goto yy36;
		}
yy321:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy54;
		default:	goto yy36;
		}
yy322:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy323;
		default:	goto yy36;
		}
yy323:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy324;
		default:	goto yy36;
		}
yy324:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy325;
		default:	goto yy36;
		}
yy325:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy326;
		default:	goto yy36;
		}
yy326:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy327;
		default:	goto yy36;
		}
yy327:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy328;
		default:	goto yy36;
		}
yy328:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy329;
		default:	goto yy36;
		}
yy329:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy330;
		default:	goto yy36;
		}
yy330:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy54;
		default:	goto yy36;
		}
yy331:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy337;
		default:	goto yy36;
		}
yy332:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy333;
		default:	goto yy36;
		}
yy333:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy334;
		default:	goto yy36;
		}
yy334:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy335;
		default:	goto yy36;
		}
yy335:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy336;
		default:	goto yy36;
		}
yy336:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy54;
		default:	goto yy36;
		}
yy337:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy338;
		default:	goto yy36;
		}
yy338:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy339;
		default:	goto yy36;
		}
yy339:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy340;
		default:	goto yy36;
		}
yy340:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy341;
		default:	goto yy36;
		}
yy341:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy342;
		default:	goto yy36;
		}
yy342:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy343;
		default:	goto yy36;
		}
yy343:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy344;
		default:	goto yy36;
		}
yy344:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy345;
		default:	goto yy36;
		}
yy345:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy346;
		default:	goto yy36;
		}
yy346:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy347;
		default:	goto yy36;
		}
yy347:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy348;
		default:	goto yy36;
		}
yy348:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy54;
		default:	goto yy36;
		}
yy349:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy350;
		default:	goto yy36;
		}
yy350:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy351;
		default:	goto yy36;
		}
yy351:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy352;
		default:	goto yy36;
		}
yy352:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy353;
		default:	goto yy36;
		}
yy353:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy354;
		default:	goto yy36;
		}
yy354:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy355;
		default:	goto yy36;
		}
yy355:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy356;
		default:	goto yy36;
		}
yy356:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy210;
		default:	goto yy36;
		}
yy357:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy384;
		case 'e':	goto yy385;
		default:	goto yy36;
		}
yy358:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy369;
		default:	goto yy36;
		}
yy359:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy360;
		default:	goto yy36;
		}
yy360:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy361;
		default:	goto yy36;
		}
yy361:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy362;
		default:	goto yy36;
		}
yy362:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy363;
		default:	goto yy36;
		}
yy363:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy364;
		default:	goto yy36;
		}
yy364:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy365;
		default:	goto yy36;
		}
yy365:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy366;
		default:	goto yy36;
		}
yy366:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy367;
		default:	goto yy36;
		}
yy367:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy368;
		default:	goto yy36;
		}
yy368:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy54;
		default:	goto yy36;
		}
yy369:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy370;
		default:	goto yy36;
		}
yy370:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy371;
		default:	goto yy36;
		}
yy371:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy372;
		default:	goto yy36;
		}
yy372:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy373;
		default:	goto yy36;
		}
yy373:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy374;
		default:	goto yy36;
		}
yy374:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy375;
		default:	goto yy36;
		}
yy375:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy376;
		default:	goto yy36;
		}
yy376:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy377;
		default:	goto yy36;
		}
yy377:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy378;
		default:	goto yy36;
		}
yy378:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy379;
		default:	goto yy36;
		}
yy379:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy380;
		default:	goto yy36;
		}
yy380:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy381;
		default:	goto yy36;
		}
yy381:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy382;
		default:	goto yy36;
		}
yy382:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy383;
		default:	goto yy36;
		}
yy383:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy54;
		default:	goto yy36;
		}
yy384:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy400;
		default:	goto yy36;
		}
yy385:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy386;
		default:	goto yy36;
		}
yy386:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy387;
		default:	goto yy36;
		}
yy387:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy388;
		default:	goto yy36;
		}
yy388:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy389;
		default:	goto yy36;
		}
yy389:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy390;
		default:	goto yy36;
		}
yy390:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy391;
		default:	goto yy36;
		}
yy391:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy392;
		default:	goto yy36;
		}
yy392:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy393;
		default:	goto yy36;
		}
yy393:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy394;
		default:	goto yy36;
		}
yy394:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy395;
		case 'f':	goto yy54;
		default:	goto yy36;
		}
yy395:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy396;
		default:	goto yy36;
		}
yy396:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy397;
		default:	goto yy36;
		}
yy397:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy398;
		default:	goto yy36;
		}
yy398:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy399;
		default:	goto yy36;
		}
yy399:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy54;
		default:	goto yy36;
		}
yy400:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy401;
		default:	goto yy36;
		}
yy401:
		yych = (char)*++*p;
		switch (yych) {
		case 'b':	goto yy402;
		default:	goto yy36;
		}
yy402:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy403;
		case 's':	goto yy404;
		case 'u':	goto yy405;
		default:	goto yy36;
		}
yy403:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy210;
		default:	goto yy36;
		}
yy404:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy409;
		default:	goto yy36;
		}
yy405:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy406;
		default:	goto yy36;
		}
yy406:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy407;
		default:	goto yy36;
		}
yy407:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy408;
		default:	goto yy36;
		}
yy408:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy210;
		default:	goto yy36;
		}
yy409:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy410;
		default:	goto yy36;
		}
yy410:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy411;
		default:	goto yy36;
		}
yy411:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy412;
		default:	goto yy36;
		}
yy412:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy210;
		default:	goto yy36;
		}
yy413:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy414;
		case 's':	goto yy416;
		case 'u':	goto yy415;
		default:	goto yy36;
		}
yy414:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy210;
		default:	goto yy36;
		}
yy415:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy421;
		default:	goto yy36;
		}
yy416:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy417;
		default:	goto yy36;
		}
yy417:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy418;
		default:	goto yy36;
		}
yy418:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy419;
		default:	goto yy36;
		}
yy419:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy420;
		default:	goto yy36;
		}
yy420:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy210;
		default:	goto yy36;
		}
yy421:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy422;
		default:	goto yy36;
		}
yy422:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy423;
		default:	goto yy36;
		}
yy423:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy210;
		default:	goto yy36;
		}
yy424:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy425;
		case '5':	goto yy426;
		default:	goto yy36;
		}
yy425:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy440;
		default:	goto yy36;
		}
yy426:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy427;
		default:	goto yy36;
		}
yy427:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy428;
		default:	goto yy36;
		}
yy428:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy429;
		default:	goto yy36;
		}
yy429:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy430;
		default:	goto yy36;
		}
yy430:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy431;
		default:	goto yy36;
		}
yy431:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy432;
		default:	goto yy36;
		}
yy432:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy433;
		default:	goto yy36;
		}
yy433:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy434;
		default:	goto yy36;
		}
yy434:
		yych = (char)*++*p;
		switch (yych) {
		case '5':	goto yy435;
		default:	goto yy36;
		}
yy435:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy436;
		default:	goto yy36;
		}
yy436:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy437;
		default:	goto yy36;
		}
yy437:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy438;
		default:	goto yy36;
		}
yy438:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy439;
		default:	goto yy36;
		}
yy439:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy54;
		default:	goto yy36;
		}
yy440:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy441;
		default:	goto yy36;
		}
yy441:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy442;
		default:	goto yy36;
		}
yy442:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy443;
		default:	goto yy36;
		}
yy443:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy444;
		default:	goto yy36;
		}
yy444:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy445;
		default:	goto yy36;
		}
yy445:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy446;
		default:	goto yy36;
		}
yy446:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy447;
		default:	goto yy36;
		}
yy447:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy448;
		default:	goto yy36;
		}
yy448:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy449;
		default:	goto yy36;
		}
yy449:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy450;
		default:	goto yy36;
		}
yy450:
		yych = (char)*++*p;
		switch (yych) {
		case '6':	goto yy451;
		default:	goto yy36;
		}
yy451:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy452;
		default:	goto yy36;
		}
yy452:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy54;
		default:	goto yy36;
		}
yy453:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy454:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy210;
		default:	goto yy36;
		}
yy455:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy456:
		yych = (char)*++*p;
		switch (yych) {
		case '1':	goto yy210;
		default:	goto yy36;
		}
yy457:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy458;
		default:	goto yy36;
		}
yy458:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy459;
		default:	goto yy36;
		}
yy459:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy460;
		default:	goto yy36;
		}
yy460:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy461;
		default:	goto yy36;
		}
yy461:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy462;
		default:	goto yy36;
		}
yy462:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy463;
		default:	goto yy36;
		}
yy463:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy464;
		default:	goto yy36;
		}
yy464:
		yych = (char)*++*p;
		switch (yych) {
		case 'k':	goto yy465;
		default:	goto yy36;
		}
yy465:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy466:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy467;
		default:	goto yy36;
		}
yy467:
		yych = (char)*++*p;
		switch (yych) {
		case 'd':	goto yy468;
		default:	goto yy36;
		}
yy468:
		yych = (char)*++*p;
		switch (yych) {
		case '_':	goto yy469;
		default:	goto yy36;
		}
yy469:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy470;
		default:	goto yy36;
		}
yy470:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy471;
		default:	goto yy36;
		}
yy471:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy472;
		default:	goto yy36;
		}
yy472:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy473;
		default:	goto yy36;
		}
yy473:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy474:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy475;
		default:	goto yy36;
		}
yy475:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy476;
		default:	goto yy36;
		}
yy476:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy477;
		default:	goto yy36;
		}
yy477:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy478;
		default:	goto yy36;
		}
yy478:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy479;
		default:	goto yy36;
		}
yy479:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy210;
		default:	goto yy36;
		}
yy480:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy490;
		default:	goto yy36;
		}
yy481:
		yych = (char)*++*p;
		switch (yych) {
		case 'a':	goto yy486;
		default:	goto yy36;
		}
yy482:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy483;
		default:	goto yy36;
		}
yy483:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy484;
		default:	goto yy36;
		}
yy484:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy485;
		default:	goto yy36;
		}
yy485:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy210;
		default:	goto yy36;
		}
yy486:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy487;
		default:	goto yy36;
		}
yy487:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy488;
		default:	goto yy36;
		}
yy488:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy489;
		default:	goto yy36;
		}
yy489:
		yych = (char)*++*p;
		switch (yych) {
		case 'g':	goto yy210;
		default:	goto yy36;
		}
yy490:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy491;
		default:	goto yy36;
		}
yy491:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy492;
		default:	goto yy36;
		}
yy492:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy493;
		default:	goto yy36;
		}
yy493:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy210;
		default:	goto yy36;
		}
yy494:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy495;
		default:	goto yy36;
		}
yy495:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy496;
		default:	goto yy36;
		}
yy496:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy497;
		default:	goto yy36;
		}
yy497:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy210;
		default:	goto yy36;
		}
yy498:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy504;
		default:	goto yy36;
		}
yy499:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy500;
		default:	goto yy36;
		}
yy500:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy501;
		default:	goto yy36;
		}
yy501:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy502;
		default:	goto yy36;
		}
yy502:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy503;
		default:	goto yy36;
		}
yy503:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		default:	goto yy36;
		}
yy504:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy505;
		default:	goto yy36;
		}
yy505:
		yych = (char)*++*p;
		switch (yych) {
		case 'p':	goto yy506;
		default:	goto yy36;
		}
yy506:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy507;
		default:	goto yy36;
		}
yy507:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy508;
		default:	goto yy36;
		}
yy508:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy509;
		default:	goto yy36;
		}
yy509:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':	goto yy510;
		default:	goto yy36;
		}
yy510:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy511;
		default:	goto yy36;
		}
yy511:
		yych = (char)*++*p;
		switch (yych) {
		case '3':	goto yy512;
		default:	goto yy36;
		}
yy512:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':	goto yy92;
		default:	goto yy36;
		}
yy513:
		yych = (char)*++*p;
		switch (yych) {
		case '-':	goto yy210;
		default:	goto yy36;
		}
yy514:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy515;
		default:	goto yy36;
		}
yy515:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy516;
		default:	goto yy36;
		}
yy516:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy517;
		default:	goto yy36;
		}
yy517:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy518;
		default:	goto yy36;
		}
yy518:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy210;
		default:	goto yy36;
		}
yy519:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy520;
		default:	goto yy36;
		}
yy520:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy521;
		default:	goto yy36;
		}
yy521:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy522;
		default:	goto yy36;
		}
yy522:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy210;
		case 'a':	goto yy523;
		case 's':	goto yy524;
		default:	goto yy36;
		}
yy523:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy529;
		default:	goto yy36;
		}
yy524:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy525;
		default:	goto yy36;
		}
yy525:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy526;
		default:	goto yy36;
		}
yy526:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy527;
		default:	goto yy36;
		}
yy527:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy528;
		default:	goto yy36;
		}
yy528:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy210;
		default:	goto yy36;
		}
yy529:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy210;
		default:	goto yy36;
		}
yy530:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '"':	goto yy546;
		case '%':	goto yy560;
		case '&':	goto yy547;
		case '\'':	goto yy551;
		case '(':	goto yy550;
		case ')':	goto yy549;
		case '*':
		case '>':	goto yy536;
		case '+':	goto yy557;
		case ',':	goto yy554;
		case '.':	goto yy530;
		case '/':	goto yy562;
		case '0':	goto yy535;
		case '1':	goto yy555;
		case '2':	goto yy556;
		case '<':	goto yy539;
		case '=':	goto yy545;
		case '@':	goto yy552;
		case '\\':	goto yy561;
		case 'a':	goto yy543;
		case 'c':	goto yy558;
		case 'e':	goto yy538;
		case 'f':	goto yy544;
		case 'i':	goto yy541;
		case 'l':	goto yy553;
		case 'o':	goto yy542;
		case 's':	goto yy540;
		case 'u':	goto yy548;
		default:	goto yy36;
		}
yy532:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy227;
		case '2':	goto yy228;
		case '3':	goto yy231;
		case '5':	goto yy230;
		case 'c':	goto yy229;
		default:	goto yy36;
		}
yy533:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy68;
		default:	goto yy36;
		}
yy534:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy57;
		default:	goto yy36;
		}
yy535:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy35;
		default:	goto yy36;
		}
yy536:
		++*p;
		yych = (char)**p;
yy537:
		switch (yych) {
		case '"':	goto yy546;
		case '%':	goto yy532;
		case '&':	goto yy547;
		case '\'':	goto yy551;
		case '(':	goto yy550;
		case ')':	goto yy549;
		case '*':
		case '>':	goto yy536;
		case '+':	goto yy557;
		case ',':	goto yy554;
		case '.':	goto yy559;
		case '/':	goto yy534;
		case '0':	goto yy535;
		case '1':	goto yy555;
		case '2':	goto yy556;
		case '<':	goto yy539;
		case '=':	goto yy545;
		case '@':	goto yy552;
		case '\\':	goto yy533;
		case 'a':	goto yy543;
		case 'c':	goto yy558;
		case 'e':	goto yy538;
		case 'f':	goto yy544;
		case 'i':	goto yy541;
		case 'l':	goto yy553;
		case 'o':	goto yy542;
		case 's':	goto yy540;
		case 'u':	goto yy548;
		default:	goto yy36;
		}
yy538:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy196;
		case 'x':	goto yy195;
		default:	goto yy36;
		}
yy539:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy188;
		case 's':	goto yy189;
		default:	goto yy36;
		}
yy540:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy498;
		case 'e':	goto yy499;
		default:	goto yy36;
		}
yy541:
		yych = (char)*++*p;
		switch (yych) {
		case 'm':	goto yy184;
		default:	goto yy36;
		}
yy542:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy134;
		default:	goto yy36;
		}
yy543:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy218;
		case 'n':	goto yy219;
		default:	goto yy36;
		}
yy544:
		yych = (char)*++*p;
		switch (yych) {
		case 'r':	goto yy124;
		default:	goto yy36;
		}
yy545:
		yych = (char)*++*p;
		switch (yych) {
		case 'j':	goto yy114;
		default:	goto yy36;
		}
yy546:
		yych = (char)*++*p;
		switch (yych) {
		case 'j':	goto yy105;
		default:	goto yy36;
		}
yy547:
		yych = (char)*++*p;
		switch (yych) {
		case '#':	goto yy81;
		case '{':	goto yy80;
		default:	goto yy36;
		}
yy548:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy519;
		default:	goto yy36;
		}
yy549:
		yych = (char)*++*p;
		switch (yych) {
		case '-':	goto yy513;
		case 's':	goto yy514;
		default:	goto yy36;
		}
yy550:
		yych = (char)*++*p;
		switch (yych) {
		case 'u':	goto yy494;
		default:	goto yy36;
		}
yy551:
		yych = (char)*++*p;
		switch (yych) {
		case ';':	goto yy210;
		case 'h':	goto yy481;
		case 's':	goto yy480;
		case 'u':	goto yy482;
		default:	goto yy36;
		}
yy552:
		yych = (char)*++*p;
		switch (yych) {
		case 'v':	goto yy474;
		default:	goto yy36;
		}
yy553:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy466;
		default:	goto yy36;
		}
yy554:
		yych = (char)*++*p;
		switch (yych) {
		case 'b':	goto yy457;
		default:	goto yy36;
		}
yy555:
		yych = (char)*++*p;
		switch (yych) {
		case ';':	goto yy455;
		case '=':	goto yy456;
		default:	goto yy36;
		}
yy556:
		yych = (char)*++*p;
		switch (yych) {
		case ';':	goto yy453;
		case '=':	goto yy454;
		default:	goto yy36;
		}
yy557:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy213;
		default:	goto yy36;
		}
yy558:
		yych = (char)*++*p;
		switch (yych) {
		case 'h':	goto yy207;
		default:	goto yy36;
		}
yy559:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '"':	goto yy546;
		case '%':	goto yy532;
		case '&':	goto yy547;
		case '\'':	goto yy551;
		case '(':	goto yy550;
		case ')':	goto yy549;
		case '*':
		case '>':	goto yy536;
		case '+':	goto yy557;
		case ',':	goto yy554;
		case '.':	goto yy530;
		case '/':	goto yy534;
		case '0':	goto yy535;
		case '1':	goto yy555;
		case '2':	goto yy556;
		case '<':	goto yy539;
		case '=':	goto yy545;
		case '@':	goto yy552;
		case '\\':	goto yy533;
		case 'a':	goto yy543;
		case 'c':	goto yy558;
		case 'e':	goto yy538;
		case 'f':	goto yy544;
		case 'i':	goto yy541;
		case 'l':	goto yy553;
		case 'o':	goto yy542;
		case 's':	goto yy540;
		case 'u':	goto yy548;
		default:	goto yy36;
		}
yy560:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy227;
		case '2':	goto yy567;
		case '3':	goto yy231;
		case '5':	goto yy230;
		case 'c':	goto yy229;
		default:	goto yy36;
		}
yy561:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy68;
		case '.':	goto yy565;
		default:	goto yy36;
		}
yy562:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy563;
		case 'e':	goto yy57;
		default:	goto yy36;
		}
yy563:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy564;
		default:	goto yy36;
		}
yy564:
		yych = (char)*++*p;
		switch (yych) {
		case '/':	goto yy54;
		default:	goto yy36;
		}
yy565:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy566;
		default:	goto yy36;
		}
yy566:
		yych = (char)*++*p;
		switch (yych) {
		case '\\':	goto yy54;
		default:	goto yy36;
		}
yy567:
		yych = (char)*++*p;
		switch (yych) {
		case '0':	goto yy289;
		case '2':	goto yy287;
		case '5':	goto yy288;
		case 'F':	goto yy568;
		case 'e':	goto yy290;
		case 'f':	goto yy569;
		default:	goto yy36;
		}
yy568:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy579;
		default:	goto yy36;
		}
yy569:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy570;
		default:	goto yy36;
		}
yy570:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy571;
		default:	goto yy36;
		}
yy571:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy572;
		default:	goto yy36;
		}
yy572:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy573;
		default:	goto yy36;
		}
yy573:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy574;
		default:	goto yy36;
		}
yy574:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy575;
		default:	goto yy36;
		}
yy575:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy576;
		default:	goto yy36;
		}
yy576:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy577;
		default:	goto yy36;
		}
yy577:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy578;
		default:	goto yy36;
		}
yy578:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy54;
		default:	goto yy36;
		}
yy579:
		yych = (char)*++*p;
		switch (yych) {
		case '.':	goto yy580;
		default:	goto yy36;
		}
yy580:
		yych = (char)*++*p;
		switch (yych) {
		case '%':	goto yy581;
		default:	goto yy36;
		}
yy581:
		yych = (char)*++*p;
		switch (yych) {
		case '2':	goto yy582;
		default:	goto yy36;
		}
yy582:
		++*p;
		switch ((yych = (char)**p)) {
		case 'F':	goto yy54;
		default:	goto yy36;
		}
	}

    }
}


int main() 
{
    char *z = ReadLines("test.txt");
    char *p = all2lowcase(z);

    char *last = p;
    int result=0,line_number=1,count=0;

    puts(p);

    while(!result )
	switch (parse_ion(&p, &last)) 
	{
        	case SQLI:
		printf("Have SQL injection here line number %d \n",line_number);
		count++;	
            	break;

	        case XSS:
     	        printf("Have XSS here! line number %d \n",line_number);
		count++;	
   	        break;

	        case PATHTRAVERSAL:
     	        printf("Have PATH Traversal here! line number %d \n",line_number);
		count++;	
   	        break;

		case COUNTER:
	    	line_number++;
            	break;

        	case END:
	    	result=1;	
            	break;
        }

	puts("Raptor DFA Tester");
	printf("Total of matchs %d\nLines: %d\n",count,line_number);

	free(z);
	z=NULL;
	free(p);
	p=NULL;
	

    exit(0);
}

