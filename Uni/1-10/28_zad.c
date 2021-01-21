#include <stdio.h>

int main()
{
    int number_0= 0, number_1= 1, position;
    printf("Enter a number: ");
    scanf("%d", &position);
    for(int i=0; i<position; ++i)
    {
        printf("%d, ", number_0);
        int temp = number_1;
        number_1 += number_0;
        number_0 = temp;
    }
    return 0;
}
