#include <stdio.h>

int main()
{
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
