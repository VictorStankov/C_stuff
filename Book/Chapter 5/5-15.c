#define getline _getline
#define strcmp _strcmp
#include <stdio.h>
#include <string.h>
#undef getline
#undef strcmp
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
int (*comp)(void *, void *));
int strcmp(char *s, char *t);
int numcmp(char *, char *);

int reverse = 0;
int fold = 0;

/* sort input lines */
main(int argc, char *argv[])
{
    /* 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
       (decreasing) order. Be sure that -r works with -n.*/

    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    
    if (argc > 1)
    {
        for(int i=1; i<argc; ++i)
        {
            if(strcmp(*++argv, "-n") == 0)
                numeric = 1;
            if(strcmp(*argv, "-r") == 0)
                reverse = 1;
            if(strcmp(*argv, "-f") == 0)
                fold = 1;
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
    {
        qsort((void**) lineptr, 0, nlines-1,
        (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }

    else 
    {
        printf("input too big to sort\n");
        return 1;
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right,
int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right)/2);
    last = left;

    if(reverse)
    {
        for (i = left+1; i <= right; i++)
            if (fold ? (*comp)(v[i], v[left]) > 0 : (*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
    }
    else
    {
        for (i = left+1; i <= right; i++)
            if (fold ? (*comp)(v[i], v[left]) < 0 : (*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char* alloc(int n);

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

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t)
{
    /* 5-15. Add the option -f to fold upper and lower case together, so that case
       distinctions are not made during sorting; for example, a and A compare equal.*/

    int i;
    for (i = 0; fold ? tolower(s[i]) == tolower(t[i]) : s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
