#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Enter the sides of the triangle in ascending order: ");
    scanf("%d%d%d", &a, &b, &c);
    if(a+b<=c || b+c<=a || a+c<=b)
    {
        printf("\nNO");
        return 0;
    }
    printf("\nYES\n");
    if(a*a + b*b<c*c)
    {
        printf("Typoygylen\n");
        return 0;
    }
    else if(a*a + b*b==c*c)
    {
        printf("Pravoygylen\n");
        return 0;
    }
    else
    {
        printf("Ostroygylen\n");
        return 0;
    }
}
