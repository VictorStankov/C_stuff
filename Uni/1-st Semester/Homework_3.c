#include <stdio.h>

int main()
{
    int c, sum;
    sum = 0;

    while((c = getchar()) != EOF)
    {
        if(c != '\n')
        {
            c -= '0';
            if(c % 3 == 0)
                sum += c;
        }
        else
        {
            printf("%d\n", sum);
            sum = 0;
        }
    }
}
