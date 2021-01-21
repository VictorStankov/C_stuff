#include <stdio.h>

int main()
{
    int height, width, counter, c, i;
    printf("Enter a symbol: ");
    scanf("%c", &c);
    printf("Enter height: ");
    scanf("%d", &height);
    --height;
    for(i = 1; i<height; ++i)
    {
        counter = 0;
        for(int whitespace = 1; whitespace<=height - i; ++whitespace)
            printf("  ");
        while(counter != 2*i - 1)
        {
            ++counter;
                putchar(c);
                printf(" ");
        }
        printf("\n");
    }
    if(i==height)
    {
        counter = 0;
        while(counter != 2*i -1)
        {
            putchar(c);
            printf(" ");
            ++counter;
        }
        printf("\n");
    }
    for(int t=2; t<i; ++t)
    {
        printf("  ");
    }
    putchar(c);
    printf("   ");
    putchar(c);
    return 0;
}
