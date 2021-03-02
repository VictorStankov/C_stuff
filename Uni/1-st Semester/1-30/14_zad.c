#include <stdio.h>
#include <math.h>

void convert(int number, int divider);

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    convert(number, 2);
    convert(number, 8);
    convert(number, 16);
    return 0;
}

void convert(int number, int divider)
{
    int i=0, holder;
    char list[100];
    while(number>0)
    {
        holder = number%divider;
        if(holder<10)
            list[i] = holder + '0';
        else list[i] = holder + '0' + 7;
        ++i;
        number /= divider;
    }
    for(i-=1; i>=0; --i)
        printf("%c", list[i]);
    printf("\n");
}
