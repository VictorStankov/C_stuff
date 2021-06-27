#include <stdio.h>
#include <stdlib.h>

void entab(int N);
void detab(int N);

int main(int argc, char *argv[])
{
    /* 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
       accept a list of tab stops as arguments. Use the default tab settings if there are 
       no arguments.*/
    char functionality;
    int N = 4;
    
    if(argc == 1)
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
}

void entab(int N)
{
    /* 1-21. Write a program entab that replaces strings of blanks by the minimum
       number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
       When either a tab or a single blank would suffice to reach a tab stop, which should be given
       preference?*/

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
