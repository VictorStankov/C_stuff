#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000

char *lineptr[10][MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[][MAXLINES], int nlines);
void writelines(char *lineptr[][MAXLINES], int nlines);
int getoneline(char s[],int lim);
void quicksort(void *lineptr[][MAXLINES], int left, int right,
           int (*comp)(void *, void *), int column);
int stringcmp(char *s, char *t);
int numcmp(char *, char *);
int sort(int numeric, int column, int nlines);

int reverse = 0;
int fold = 0;
int directory = 0;

/* sort input lines */
int main(int argc, char *argv[])
{
    /* 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
	 * (decreasing) order. Be sure that -r works with -n.*/
	
	/* 5-17. Add a field-searching capability, so sorting may bee done on fields within  lines, 
	 * each field sorted according to an independent set of options. (The index for this book 
	 * was sorted with -df for the index category and -n for the page numbers.)*/
    
	int nlines; /* number of input lines read */
	system("clear");

    if (argc > 1)
    {
		nlines = readlines(lineptr, MAXLINES);
        for(int i=1; i<argc; ++i)
        {
			int numeric = 0, column = 0; 
			reverse = 0;
			fold = 0;
			directory = 0;

			if((*++argv)[0] == '-')
			{
				column = (*argv)[1] - '0' - 1;
				for(int j=2; (*argv)[j]; ++j)
				{
					switch ((*argv)[j]) 
					{
					case 'n':
						numeric = 1;
						break;
					case 'r':
						reverse = 1;
						break;
					case 'f':
						fold = 1;
						break;
					case 'd':
						directory = 1;
						break;
					}
				}
				sort(numeric, column, nlines);
			}
        }
        writelines(lineptr, nlines);
    }
}

int sort(int numeric, int column, int nlines)
{
    if (nlines >= 0)
    {
        quicksort((void*) lineptr, 0, nlines-1,
              (int (*)(void*,void*))(numeric ? numcmp : stringcmp), column);
        return 0;
    }

    else
    {
        printf("input too big to sort\n");
        return 1;
    }

}

/* quicksort: sort v[left]...v[right] into increasing order */
void quicksort(void *v[][MAXLINES], int left, int right,
           int (*comp)(void *, void *), int column)
{
    int i, last;
    void swap(void *v[][MAXLINES], int, int, int);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right)/2, column);
    last = left;

    if(reverse)
    {
		printf("reverse\n");
        for (i = left+1; i <= right; i++)
            if (fold ? (*comp)(v[column][i], v[column][left]) > 0 : (*comp)(v[column][i], v[column][left]) > 0)
                swap(v, ++last, i, column);
    }
    else
    {
		printf("nonreverse\n");
        for (i = left+1; i <= right; i++)
            if (fold ? (*comp)(v[column][i], v[column][left]) < 0 : (*comp)(v[column][i], v[column][left]) < 0)
                swap(v, ++last, i, column);
    }

    swap(v, left, last, column);
    quicksort(v, left, last-1, comp, column);
    quicksort(v, last+1, right, comp, column);
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

void swap(void *v[][MAXLINES], int i, int j, int column)
{
    void *temp;
    temp = v[column][i];
    v[column][i] = v[column][j];
    v[column][j] = temp;
}

char* alloc(int n);

/* readlines: read input lines */
int readlines(char *lineptr[10][MAXLINES], int maxlines)
{
    int len, nlines = 0, i = -1, j = 0;
    char *p, line[MAXLEN], *string;  // Changed that, don't get lost
    nlines = 0;
    while ((len = getoneline(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else
        {
			nlines++;
			i++;
            line[len-1] = '\0'; /* delete newline */
			string = strdup(line);
			
			while((p = strsep(&string, ",")) != NULL)
				lineptr[j++][i] = p;
			
			j = 0;
        }
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[][MAXLINES], int nlines)
{
    int i;

	printf("\n");

    for (i = 0; i < nlines; i++)
	{
		for(int j = 0; lineptr[j][i]; ++j)
			printf((lineptr[j+1][i] != NULL) ? "%s | " : "%s\n", lineptr[j][i]);

	}
}
/* getoneline: read a line into s, return length */
int getoneline(char s[],int lim)
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

int symbol_check(char c);

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int stringcmp(char *s, char *t)
{
    /* 5-15. Add the option -f to fold upper and lower case together, so that case
       distinctions are not made during sorting; for example, a and A compare equal.*/

    /* 5-16. Add the -d (``directory order'') option, which makes comparisons only on
       letters, numbers and blanks. Make sure it works in conjunction with -f.*/

    int i, j;
    // int s_len = strlen(s), t_len = strlen(t);
    // int len = ((s_len - t_len) > 0) ? t_len : s_len;

    if(directory)
    {
        for (i = j = 0;; i++)
        {
            if(symbol_check(s[i]) == 0)
                continue;
            for(;symbol_check(t[j]) == 0;++j);

            if(fold ? tolower(s[i]) == tolower(t[j++]) : s[i] == t[j++])
            {
                if (s[i] == '\0')
                    return 0;
            }
            else
                return s[i] - t[i];
        }
    }
    else
    {
        for (i = 0; fold ? tolower(s[i]) == tolower(t[i]) : s[i] == t[i]; i++)
            if (s[i] == '\0')
                return 0;
    }
    return s[i] - t[i];
}

int symbol_check(char c)
{
    if(isalpha(c) || c == ' ' || isdigit(c) || c == '\0')
        return 1;
    return 0;
}
