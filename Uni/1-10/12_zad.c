#include <stdio.h>

int main()
{
    long long number;
    int sum=0;
    printf("Enter a number: ");
    scanf("%lld", &number);
    while(number>0)
    {
        sum += number%100;
        number/=100;
    }
    putchar(sum%127);
    return 0;
}
