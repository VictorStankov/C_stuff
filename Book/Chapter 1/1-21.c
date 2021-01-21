#include <stdio.h>

int main()
{
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
