#include <stdio.h>

int main()
{
    int c, sum;
    sum = 0;

    while((c = getchar()) != EOF)
    {
        if(c != '\n')
            sum += c - '0';
        else
        {
            printf("%d\n", sum);
            sum = 0;
        }
    }
}
