#define getline _getline
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#undef getline
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

/* sort input lines */
int main(int argc, char* argv[])
{
    long long N;
    if(argc == 1)
        N = 10;
    else if(argc == 2)
        if((*++argv)[0] == '-')
            N = (*argv)[1] - '0';
    if(argc > 2)
    {
        printf("Too many arguments!\n");
        exit(0);
    }

    /* 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
       calling alloc to maintain storage. How much faster is the program?*/
    long long nlines; /* number of input lines read */
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        if(nlines > N)
            nlines = N;
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

char* alloc(int n)
{
    return (char*)malloc(sizeof(char)*n);
}
