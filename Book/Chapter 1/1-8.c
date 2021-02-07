#include <stdio.h>

int main()
{
    /* Write a program to count blanks, tabs, and newlines.*/
    double blanks, tabs, newlines;
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            ++blanks;
        if(c == '\t')
            ++tabs;
        if(c == 'n')
            ++newlines;
        printf("%.0f\t%.0f\t%.0f\n", blanks, tabs, newlines);
    }
    return 0;
}
