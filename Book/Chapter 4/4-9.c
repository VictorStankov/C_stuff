#include <stdio.h>
#define BUFSIZE 100

int getch();
void ungetch(int);

int main()
{
	int c;
	while(c = getchar())
    {
        if(c != ' ' || c != '\n' || c != '\t')
            ungetch(c);
        if((c = getch()) == EOF)
            break;
        putchar(c);
    }
	return 0;
}

/* Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what
   their properties ought to be if an EOF is pushed back, then implement your design.*/

/* Note: not sure what I was supposed to do here since it was working anyways.*/

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch() /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    //printf("%d\n", c);
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
