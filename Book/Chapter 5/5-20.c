#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

#define MAXTOKEN  100

enum { NAME, PARENS, BRACKETS }; 

void dcl(void); 
void dirdcl(void); 

int bufp = 0; /* next free position in buf */
int gettoken(void); 
int tokentype;           /* type of last token */ 
char token[MAXTOKEN];    /* last token string */ 
char name[MAXTOKEN];     /* identifier name */ 
char datatype[MAXTOKEN]; /* data type = char, int, etc. */ 
char out[1000];
int const_flag = 0;

int main()  /* convert declaration to words */ 
{
    while (gettoken() != EOF) {   /* 1st token on line */
		if(strcmp(token, "const") == 0)
		{
			const_flag = 1;
			gettoken();
		}
        strcpy(datatype, token);  /* is the datatype */ 
        out[0] = '\0'; 
        dcl();       /* parse rest of line */ 
		if(tokentype != '\n' || bufp != 0) 
		{
			printf("syntax error\n");
            char c;
            while((c = getchar()) != '\n')
                ;
            bufp = 0;
		}
		else
            printf("%s:%s%s %s\n", name, (const_flag) ? " constant" : "", out, datatype);
    } 
    return 0; 
}

int gettoken(void)  /* return next token */ 
{ 
    int c, getch(void); 
    void ungetch(int); 
    char *p = token; 

    while ((c = getch()) == ' ' || c == '\t') 
        ;

	if (c == '(') 
	{ 
        if ((c = getch()) == ')') { 
            strcpy(token, "()"); 
            return tokentype = PARENS; 
        } else { 
            ungetch(c); 
            return tokentype = '('; 
        } 
    } 
		
	else if (c == '[') 
	{ 
        for (*p++ = c; (*p++ = getch()) != ']'; ) 
            ; 
        *p = '\0'; 
        return tokentype = BRACKETS; 
    } 
	else if (isalpha(c)) 
	{ 
        for (*p++ = c; isalnum(c = getch()); ) 
            *p++ = c; 
        *p = '\0'; 
        ungetch(c); 
        return tokentype = NAME; 
    } 
	else 
        return tokentype = c; 
}

/* dcl:  parse a declarator */ 
void dcl(void) 
{ 
    int ns; 

    for (ns = 0; gettoken() == '*'; ) /* count *'s */
 	            ns++; 
    dirdcl(); 
    while (ns-- > 0) 
        strcat(out, " pointer to"); 
} 

/* dirdcl:  parse a direct declarator */ 
void dirdcl(void) 
{
	int check_word(char *s);
    int type; 

	if (tokentype == '(') 
	{         /* ( dcl ) */ 
        dcl(); 
        if (tokentype != ')') 
            printf("error: missing )\n"); 
    } 
	else if (tokentype == NAME)  /* variable name */
	{
		if(check_word(token) == 0) // To finish
			strcpy(name, token);
	}

	else 
        printf("error: expected name or (dcl)\n"); 
    while ((type=gettoken()) == PARENS || type == BRACKETS || type == NAME) 
		if (type == PARENS) 
            strcat(out, " function returning");
		else if(type == NAME)
			;
		else 
		{ 
            strcat(out, " array"); 
            strcat(out, token); 
            strcat(out, " of"); 
        } 
}

int getch() /* get a (possibly pushed-back) character */
{
    int temp = bufp;
    bufp = 0;
    return (temp > 0) ? temp : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp != 0)
        printf("ungetch: too many characters\n");
    else
        bufp = c;
}

int check_word(char *s) // To finish 
{
	char words[][10] = {"void", "int", "double", "float", "char"};
	if(strcmp(s, "const") == 0)
	{
		const_flag = 1;
		return 1;
	}
	else
	{
		for(int i = 0; i < 5; ++i)
			if(strcmp(s, words[i]) == 0)
				return 1;
	}
	return 0;
}
