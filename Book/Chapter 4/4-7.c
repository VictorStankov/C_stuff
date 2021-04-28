#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int getch();
void ungetch(int);
void ungets(char s[]);

int main()
{
    int c;
    char arr[BUFSIZE];
	ungets(gets(arr));
	while(c = getch())
        putchar(c);
	return 0;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch() /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* Write a routine ungets(s) that will push back an entire string onto the input.
   Should ungets know about buf and bufp, or should it just use ungetch? */

void ungets(char s[])
{
    for(int i=strlen(s); i>=0; --i)
        ungetch(s[i]);
}
