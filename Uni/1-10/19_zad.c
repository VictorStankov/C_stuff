#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    a += b;
    b = a - b;
    a -= b;

    printf("A: %d\tB: %d", a, b);
    return 0;
}
