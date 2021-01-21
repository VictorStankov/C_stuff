#include <stdio.h>

int main()
{
    int c, comment; // Comment is a flag
    comment = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '/' && comment != 1) // Checks for the first slash
        {
            if((c = getchar()) == '/') // Checks if the next character is also a slash
                comment = 1; // If it is, the flag is set to True
            else // If not, it puts the slash and the appropriate character
            {
                putchar('/');
                putchar(c);
                continue;
            }
        }
        if(comment == 1 && c != '\n') // Skips the contents of the comment
        {
            continue;
        }
        else if(comment == 1 && c == '\n') // Waits for the end of the comment/line
        {
            comment = 0;
            putchar(c);
        }
        else putchar(c); // If all other conditions fail, it prints the character
    }
    return 0;
}
