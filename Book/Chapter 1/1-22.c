#include <stdio.h>

int main()
{
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
