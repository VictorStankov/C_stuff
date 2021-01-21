#include <stdio.h>
#define FLAG 1

int check_prime(int num, int flag);

int main()
{
    int start_number, end_number;
    printf("Enter a starting number: ");
    scanf("%d", &start_number);
    printf("Enter an ending number: ");
    scanf("%d", &end_number);

    for(int i = start_number; i<end_number; ++i)
        check_prime(i, FLAG);
    return 0;
}

int check_prime(int num, int flag)
{
    for(int i = 2; i<num; ++i)
        if(num != i && num % i ==0)
            return 0;
    if(flag == 1)
        printf("%d, ", num);
    return 1;
}
