#include <stdio.h>

int check_prime(int num);

int main()
{
    int number, digit, even=0, odd=0, prime=0;
    printf("Enter a number: ");
    scanf("%d", &number);
    while(number>0)
    {
        digit = number % 10;
        number /= 10;
        if(digit%2 == 0)
            even += digit;
        else odd += digit;
        if(check_prime(digit) == 1)
            prime += digit;
    }
    printf("\n%d", (even*odd)%prime);
    return 0;
}

int check_prime(int num)
{
    for(int i = 2; i<num; ++i)
        if(num != i && num % i ==0)
            return 0;
    return 1;
}
