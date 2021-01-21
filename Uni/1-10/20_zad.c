#include <stdio.h>

int main()
{
    int number, digit, product = 1;
    printf("Enter a number: ");
    scanf("%d", &number);

    while(number>1)
    {
        digit = number % 10;
        if(digit % 2 != 0)
            product *= digit;
        number /= 10;
    }
    printf("\n%d", product);
    return 0;
}
