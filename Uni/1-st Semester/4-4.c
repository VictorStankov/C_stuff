#include <stdio.h>

int main()
{
    int number, counter=0;
    char arr[20];
    scanf("%d", &number);
    while(number>=1)
    {
        arr[counter] = number%10 + '0';
        ++counter;
        number /= 10;
    }
    arr[counter] = '\0';
    printf("\n%s", arr);
    return 0;
}
