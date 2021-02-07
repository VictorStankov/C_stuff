#include <stdio.h>

int lower(int c);

int main()
{
    printf("%c", lower('F'));
}

int lower(int c)
{
    /* Rewrite the function lower, which converts upper case letters to lower case,
       with a conditional expression instead of if-else.*/
    return (c>='A' && c<='Z') ? c + ('a' - 'A') : c;
}
