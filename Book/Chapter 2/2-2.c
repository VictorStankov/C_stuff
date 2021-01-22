#include <stdio.h>
#define lim 5

int main()
{
    char s[lim], c;
    for (int i=0; i < lim-1; ++i)
    {
        if((c=getchar()) != '\n')
            if(c != EOF)
                s[i] = c;
    }
    printf("\n\n%s\n", s);
    return 0;
}
