#include <stdio.h>
#include <stdlib.h>

void entab(int N);
void detab(int N);

int main(int argc, char *argv[])
{
    /* 1-20. Write a program detab that replaces tabs in the input with the proper number
       of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
       Should n be a variable or a symbolic parameter?*/

    char functionality;
    int N;
    
    if(argc != 3)
    {
        printf("Please provide a single number for N columns and \"-e\" or \"-d\" for en/detabbing respectively.\n");
        exit(0);
    }
    for(int i=0; i<2; ++i)
    {
        if((*++argv)[0] == '-')
            functionality = (*argv)[1];
        else
            N = atoi(*argv);
    }

    switch(functionality)
    {
        case 'e':
            entab(N);
            break;
        case 'd':
            detab(N);
            break;
        default:
            printf("Unrecognised parameter!\n");
    }
    return 0;
}

void detab(int N)
{
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
}

void entab(int N)
{
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            ++i;
        if(i == N)
        {
            i = 0;
            printf("aaaa");
            continue;
        }
        if(i > 0 && c != ' ')
        {
            for(int t = 0; t < i; ++t)
                putchar('b');
            i = 0;
            putchar(c);
        }
        else if(c != ' ')
            putchar(c);
    }
}
