#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
#define SIZE 5


int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int n, array[SIZE], getint(int *), i;
    for (n = 0; n < SIZE && (i = getint(&array[n])) != EOF; n++)
        if(i == 0)
            --n;
    for(int i=0; i<SIZE; ++i)
        printf("%d ", array[i]);
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') 
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-' )
    {
        /* 5-1. As written, getint treats a + or - not followed by a digit as a valid
           representation of zero. Fix it to push such a character back on the input.*/
        c = getchar();
        if(!isdigit(c) && c != EOF)
        {
            ungetch(c);
            return 0;
        }
        else if(c == EOF)
        {
            return EOF;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
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