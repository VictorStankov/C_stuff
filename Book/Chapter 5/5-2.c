#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define BUFSIZE 100
#define SIZE 5

float getfloat(float *pn);
int getch(void);
void ungetch(int c);

int main()
{
    printf("%d\n", 54.3123*10==543.123);
    int n;
    float array[SIZE], i;
    for (n = 0; n < SIZE && (i = getfloat(&array[n])) != EOF; n++)
        if(i == 0)
            --n;
    for(int i=0; i<SIZE; ++i)
        printf("%f ", array[i]);
    return 0;
}

/* 5-2. Write getfloat, the floating-point analog of getint. What type does
   getfloat return as its function value?*/
float getfloat(float *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') 
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
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
    if(c == '.')
    {
        c = getch();
        for (int i=0; isdigit(c); c = getch())
        {
            ++i;
            *pn += (float)(c - '0') / pow(10, i);
        }
    }

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