#include <stdio.h>

void triangle();
void rectangle();
int type;

int main()
{
    extern int type;
    printf("1- Triangle, 2- Rectangle, 3- Square\nPlease enter a number: ");
    scanf("%d", &type);
    if(type == 1)
        triangle();
    else if(type == 2 || type == 3)
        rectangle();
    return 0;
}

void triangle()
{
    int height, width, counter, i;
    printf("Enter height: ");
    scanf("%d", &height);
    for(i = 1; i<height; ++i)
    {
        counter = 0;
        for(int whitespace = 1; whitespace<=height - i; ++whitespace)
            printf("  ");
        while(counter != 2*i - 1)
        {
            ++counter;
            if(counter==1)
                printf("* ");
            else if(counter==2*i -1)
                printf("*");
            else printf("  ");
        }
        printf("\n");
    }
    if(i==height)
    {
        counter = 0;
        while(counter != 2*i -1)
        {
            printf("* ");
            ++counter;
        }
    }
}

void rectangle()
{
    extern int type;
    int height;
    printf("Enter height: ");
    scanf("%d", &height);
    if(type == 2)
    {
        int width;
        printf("Enter width: ");
        scanf("%d", &width);
        for(int i = 0; i<height; ++i)
        {
            for(int t = 0; t<width; ++t)
                printf("*");
            printf("\n");
        }
    }
    else
    {
        for(int i = 0; i<height; ++i)
        {
            for(int t = 0; t<height; ++t)
                printf("*");
            printf("\n");
        }
    }
}
