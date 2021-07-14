#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void entab(int M, int N);
void detab(int M, int N);

int main(int argc, char *argv[])
{
    /* 5-12. Extend entab and detab to accept the shorthand
       entab -m +n
       to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
       default behavior.*/

    char functionality;
    int N, M;

    if(argc == 1)
    {
        printf("Enter a parameter \"-e\" or \"-d\" for en/ detabbing. Also you can specify -m (starting column) and +n (stop column).\n");
        exit(0);
    }

    for(int i=1; i<argc; ++i)
    {
        if((*++argv)[0] == '-')
            if(isdigit((*argv)[1]))
                M = (*argv)[1] - '0';
            else
                functionality = (*argv)[1];
        else if((*argv)[0] == '+')
            N = (*argv)[1] - '0';
    }

    switch(functionality)
    {
        case 'e':
            entab(M, N);
            break;
        case 'd':
            detab(M, N);
            break;
        default:
            printf("Unrecognised parameter!\n");
    }
    return 0;
}

void detab(int M, int N)
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
            for(int i = 0; i <= N - M - letters % N; ++i)
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
}

void entab(int M, int N)
{
    /* 1-21. Write a program entab that replaces strings of blanks by the minimum
       number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
       When either a tab or a single blank would suffice to reach a tab stop, which should be given
       preference?*/

    int c;
    int i = 0 - M;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            if(i < 0)
                putchar('b');
            ++i;
        }
        if(i == N)
        {
            i = 0;
            for(int t = 0; t < N; ++t)
                putchar('B');
            continue;
        }
        if(i > 0 && c != ' ')
        {
            for(int t = 0; t < i; ++t)
                putchar('b');
            i = 0 - M;
            putchar(c);
        }
        else if(c != ' ')
        {
            putchar(c);
            i = 0 - M;
        }
    }
}
