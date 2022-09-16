#include <stdio.h>

int main()
{
    /* Write a program that prints its input one word per line.*/
    int c;
    while((c=getchar()) != EOF)
    {
        if(c == ' ' || c == '\t')
            printf("\n");
        else putchar(c);
    }
    return 0 ;
}
