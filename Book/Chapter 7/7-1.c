#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* 7-1. Write a program that converts upper case to lower or lower case to upper,
 * depending on the name it is invoked with, as found in argv[0].*/

int main(int argc, char* argv[])
{
    char c, *file = strrchr(argv[0], '\\');

    if(strncmp(++file, "toupper", 7) == 0)
    {
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
        return 0;
    }
    if(strncmp(file, "tolower", 7) == 0)
    {
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
        return 0;
    }

    printf("Rename file to 'toupper' or 'tolower'!\n");
    return 0;
}