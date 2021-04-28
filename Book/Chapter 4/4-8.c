#include <stdio.h>
#define BUFSIZE 100

int getch();
void ungetch(int c);

int main()
{
    int c;
	while(c = getchar())
    {
        ungetch(c);
        putchar(getch());
    }
	return 0;
}

/* Suppose that there will never be more than one character of pushback. Modify
   getch and ungetch accordingly.*/

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
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
