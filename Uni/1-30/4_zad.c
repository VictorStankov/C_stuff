#include <stdio.h>

int check_divider(int number);

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    while(1)
    {
        if(number != 1)
        {
            int divider = check_divider(number);
            printf("%d, ", divider);
            number /= divider;
        }
        else break;
    }
    return 0;
}

int check_divider(int number)
{
    for(int i=2; i<=number; ++i)
        if(number%i == 0)
            return i;
}
