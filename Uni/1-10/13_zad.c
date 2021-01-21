#include <stdio.h>
#define N 10

int check_prime(int num);

int main()
{
    int number, product = 1;
    for(int i=0; i<N; ++i)
    {
        scanf("%d", &number);
        if(check_prime(number) == 1)
            product *= number;
    }
    printf("\n%d", product);
    return 0;
}

int check_prime(int num)
{
    for(int i = 2; i<num; ++i)
        if(num != i && num % i ==0)
            return 0;
    return 1;
}
