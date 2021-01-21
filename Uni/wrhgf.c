#include <stdio.h>

int main()
{
    int x, counter=0, sum=0;
    while(1)
    {
        scanf("%d", &x);
        if(x==0)
            break;
        if(x%2==0)
        {
            ++counter;
            sum += x;
        }
    }
    printf("Sum: %d, Counter: %d", sum, counter);
    return 0;
}
