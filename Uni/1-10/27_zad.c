#include <stdio.h>

int main()
{
    int a, b, c, D;
    printf("Enter the coefficients of a quadratic equation: ");
    scanf("%d%d%d", &a, &b, &c);
    D = b*b - 4*a*c;
    if(D<0)
    {
        printf("The equation has no real solutions.");
        return 0;
    }
    printf("\nX1 = %.2f", (-b + pow(D, 0.5))/(2*a));
    printf("\nX2 = %.2f", (-b - pow(D, 0.5))/(2*a));
    return 0;
}
