#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

#define MAXTOKEN  100

enum { NAME, PARENS, BRACKETS }; 

int undcl();
int bufp = 0; /* next free position in buf */
int gettoken(void); 
int tokentype;           /* type of last token */ 
char token[MAXTOKEN];    /* last token string */ 
char name[MAXTOKEN];     /* identifier name */ 
char datatype[MAXTOKEN]; /* data type = char, int, etc. */ 
char out[1000]; 

int main()
{
	while(undcl() == 0)
		;
	
	return 0;
}

/* undcl:  convert word descriptions to declarations */ 
int undcl() 
{ 
    int type, getch(); 
    char temp[MAXTOKEN], c;
	void ungetch(int c);

    while (gettoken() != EOF) { 
        strcpy(out, token); 
        while ((type = gettoken()) != '\n') 
            if (type == PARENS || type == BRACKETS) 
                strcat(out, token); 
            else if (type == '*') {
				while((c = getch()) == ' ')
					;
                (isalpha(c)) ? sprintf(temp, "*%s", out) : sprintf(temp, "(*%s)", out); 
                ungetch(c);
				strcpy(out, temp); 
            } else if (type == NAME) { 
                sprintf(temp, "%s %s", token, out); 
                strcpy(out, temp); 
            } else
			{
                printf("invalid input at %s\n", token);
				return 1;
			}
		printf("%s\n", out);
	}
    return (gettoken() == EOF) ? 1 : 0;
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
