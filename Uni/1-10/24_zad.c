#include <stdio.h>
#include <math.h>

void circle();
void rectangle();
int type;

int main()
{
    extern int type;
    printf("1- Circle, 2- Rectangle, 3- Square\nPlease enter a number: ");
    scanf("%d", &type);
    if(type == 1)
        circle();
    else if(type == 2 || type == 3)
        rectangle();
    return 0;
}

void circle()
{
    int radius;
    printf("Enter radius: ");
    scanf("%d", &radius);
    printf("Circumference: %.2f", 2*M_PI*radius);
}

void rectangle()
{
    extern int type;
    int height;
    printf("Enter height: ");
    scanf("%d", &height);
    if(type==2)
    {
        int width;
        printf("Enter width: ");
        scanf("%d", &width);
        printf("Circumference: %d", (height+width)*2);
    }
    else printf("Circumference: %d", height*4);
}
