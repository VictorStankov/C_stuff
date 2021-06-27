#include <stdio.h>
#define N 4

int main()
{
    /* 1-21. Write a program entab that replaces strings of blanks by the minimum
       number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
       When either a tab or a single blank would suffice to reach a tab stop, which should be given
       preference?*/
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            ++i;
        if(i == N)
        {
            i = 0;
            printf("aaaa");
            continue;
        }
        if(i > 0 && c != ' ')
        {
            for(int t = 0; t < i; ++t)
                putchar('b');
            i = 0;
            putchar(c);
        }
        else if(c != ' ')
            putchar(c);
    }
    return 0;
}
