#include <stdio.h>

int main()
{
    int number, product=1;
    printf("Enter a number: ");
    scanf("%d", &number);
    for(int i=1; i<=number; ++i)
        product*= i;
    printf("\n%d", product);
    return 0;
}
