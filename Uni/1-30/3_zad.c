#include <stdio.h>
#define FLAG 1

int check_prime(int num, int flag);

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if(check_prime(number, 0) == 1)
        printf("YES");
    else printf("NO");
    for(int i = 1; i<number; ++i)
        check_prime(i, FLAG);
    return 0;
}

int check_prime(int num, int flag)
{
    for(int i = 2; i<num; ++i)
        if(num != i && num % i ==0)
            return 0;
    if(flag == 1)
        printf(", %d", num);
    return 1;
}
