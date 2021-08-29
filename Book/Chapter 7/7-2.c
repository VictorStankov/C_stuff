#include <stdio.h>
#include <ctype.h>
#define LIMIT 25

void checkLimit(int *lim, int len);

/* 7-2. Write a program that will print arbitrary input in a sensible way. As a
 * minimum, it should print non-graphic characters in octal or hexadecimal according
 * to local custom, and break long text lines.*/

int main()
{
    char c;
    int lim = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
            continue;
        else if(isgraph(c))
        {
            putchar(c);
            checkLimit(&lim, 1);
        }
        else
            checkLimit(&lim, printf("0x%02x", c));
    }
    return 0;
}

void checkLimit(int *lim, int len)
{
    *lim += len;
    if(*lim >= LIMIT)
    {
        putchar('\n');
        *lim -= LIMIT;
    }
}