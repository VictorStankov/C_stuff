#include <stdio.h>

int main()
{
    int a, b, *pt_0 = &a, *pt_1 = &b, biggest;
    printf("Input the first number: ");
    scanf("%d", &a);
    printf("Input the second number: ");
    scanf("%d", &b);
    if(*pt_0 >= *pt_1)
        biggest = *pt_0;
    else
        biggest = *pt_1;
    printf("The maximum number is %d.", biggest);
    return 0;
}
