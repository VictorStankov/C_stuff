#include <stdio.h>

int main()
{
    /* Write a program to "fold" long input lines into two or more shorter lines after
       last non-blank character that occurs before the n-th column of input. Make sure your
       program does something intelligent with very long lines, and if there are no blanks or tabs
       before the specified column.*/
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {
        ++i;
        if(i>10 && c == ' ')
        {
            putchar('\n');
            i = 0;
        }
        else if(i == 16)
        {
            putchar('\n');
            putchar(c);
            i = 0;
        }
        else
            putchar(c);
    }
    return 0;
}
