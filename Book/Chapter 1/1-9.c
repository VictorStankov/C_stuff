#include <stdio.h>

int main()
{
    /* Write a program to copy its input to its output, replacing each string of one or
       more blanks by a single blank.*/
    int c, condition;
    condition = 0;

    while((c = getchar()) != EOF)
    {
        if(c == 'a')
        {
            if(condition == 0)
            {
                condition = 1;
                putchar(c);
            }
        }
        if(c != 'a')
        {
            condition = 0;
            putchar(c);
        }
    }
    return 0;
}
