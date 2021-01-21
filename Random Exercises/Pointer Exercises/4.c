#include <stdio.h>

int main()
{
    int a, b, *pt_0 = &a, *pt_1 = &b;
    printf("Input the first number: ");
    scanf("%d", &a);
    printf("Input the second number: ");
    scanf("%d", &b);
    printf("The sum of %d and %d is: %d.\n", *pt_0, *pt_1, *pt_0 + *pt_1);
    return 0;
}
