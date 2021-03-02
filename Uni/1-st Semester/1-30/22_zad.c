#include <stdio.h>

int getDigit(int position);
int number;

int main()
{
    extern int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if(getDigit(3)%2 != 0 && getDigit(5)%2 == 0)
        printf("\n%d", getDigit(3)*getDigit(5));
    else if(getDigit(3)%2 == 0 && getDigit(5)%2 != 0)
    {
        printf("\n%f", (double)getDigit(3)/getDigit(5));
    }
    return 0;
}

int getDigit(int position)
{
    extern int number;
    int local_number = number;
    for(int i = 1; i<position; ++i)
    {
        local_number /= 10;
    }
    return local_number % 10;
}
