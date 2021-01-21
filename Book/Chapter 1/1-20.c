#include <stdio.h>
#define N 4

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        for(int i = 0; i<N; ++i)
            putchar('a');
    }
    return 0;
}
