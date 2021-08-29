#include <stdio.h>
#define ISLOWER(c) (c >= 'a' && c <= 'z') ? 1 : 0

/* 7-9. Functions like isupper can be implemented to save space or to save time.
 * Explore both possibilities.*/

/* No idea if that's what they wanted but this is what they get when they write
 * such cryptic descriptions.*/

int main()
{
    char c;
    printf("Enter a character: ");
    c = getchar();

    printf("%s", (ISLOWER(c)) ? "True" : "False");
    return 0;
}