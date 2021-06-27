#include <stdio.h>
#define N 4

int main()
{
    /* 1-20. Write a program detab that replaces tabs in the input with the proper number
       of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
       Should n be a variable or a symbolic parameter?*/
    int c, letters = 0;

    while((c = getchar()) != EOF)
    {
        letters++;
        if(c == '\t')
        {
            for(int i = 0; i <= N - letters % N; ++i)
                putchar(' ');
            letters = 0;
        }
        else if(c == '\n')
        {
            putchar(c);
            letters = 0;
        }
        else
            putchar(c);
    }
    return 0;
}
