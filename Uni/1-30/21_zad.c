#include <stdio.h>

int main()
{
    int number, digit, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    while(number>1)
    {
        digit = number % 10;
        if(digit % 2 == 0)
            sum += digit;
        number /= 10;
    }
    printf("\n%d", sum);
    return 0;
}
