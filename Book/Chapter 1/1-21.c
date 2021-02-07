#include <stdio.h>

int main()
{
    /* Write a program entab that replaces strings of blanks by the minimum
       number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
       When either a tab or a single blank would suffice to reach a tab stop, which should be given
       preference?*/
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            ++i;
        if(i == 4)
        {
            i = 0;
            putchar('\t');
        }
        if(i > 0 && c == '\n')
        {
            for(int t = i % 4; t>0; --t)
                putchar(' ');
            i = 0;
        }
    }
    return 0;
}
