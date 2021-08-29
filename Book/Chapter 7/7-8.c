#include <stdio.h>
#define MAXLINE 1000

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Too few arguments!");
        return 0;
    }

    while(--argc)
    {
        int lineno = 0;
        char line[MAXLINE];

        FILE* text = fopen(*(++argv), "r");
        if(text == NULL)
        {
            fprintf(stderr, "File(s) not found!\n");
            exit(1);
        }

        printf("\n\t\t%s\n\n", *(argv));
        while(fgets(line, MAXLINE, text))
            printf("%2d\t%s", ++lineno, line);
        
        if(argc > 1)
            printf("\n-----------------------------------------\n");
    }
    return 0;
}
