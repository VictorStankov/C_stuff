#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* 7-7. Modify the pattern finding program of Chapter 5 to take its input from a set of
 * named files or, if no files are named as arguments, from the standard input. Should the file
 * name be printed when a matching line is found?*/

int getLine(char *line, int max);
/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE], pattern[MAXLINE];
    long lineno = 0;
    int found = 0;

    if (--argc == 0)
        printf("Usage: find \"pattern\" (files)\n");
    else
    {
        strcpy(pattern, *(++argv));
        if(argc == 1)
            while (getLine(line, MAXLINE) > 0)
            {
                lineno++;
                if ((strstr(line, pattern) != NULL) != 1)
                {
                    printf("%ld: %s", lineno, line);
                    found++;
                }
            }
        else
        {
            while(--argc)
            {
                lineno = 0;
                FILE* text = fopen(*(++argv), "r");
                if(text == NULL)
                {
                    fprintf(stderr, "File(s) not found!\n");
                    exit(1);
                }
                while(fgets(line, MAXLINE, text) != NULL)
                {
                    lineno++;
                    if(strstr(line, pattern) != NULL)
                    {
                        printf("%s: #%ld %s\n", *argv, lineno, line);
                        found++;
                    }
                }
            }
        }
    }
    return found;
}

/* getline: read a line into s, return length */
int getLine(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if(i==(lim-1))
    {
        while((c=getchar())!='\n')
            ++i;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
