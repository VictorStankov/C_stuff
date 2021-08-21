#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
    char *word;
    int count;
} keytab[] = {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        /* ... */
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0
};

int getword(char *, int);

int binsearch(char *, struct key *, int);

int check_symbol(char c);

/* count C keywords */
int main() {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                   keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch:  find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/*Exercise 6-1. Our version of getword does not properly handle underscores, string constants,
 * comments, or preprocessor control lines. Write a better version.*/

/* getword:  get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()));
    if (c != EOF)
        *w++ = c;
    if (c == '_') {
        int g = getch();
        if (g != '_') {
            ungetch(g);
            *w = '\0';
            return c;
        }
        ungetch(g);
    } else if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            switch (check_symbol(*w)) {
                case 1:
                    w--;
                    continue;
                case 0:
                    continue;
                case -1:
                    ungetch(*w);
            }
            break;
        }
    *w = '\0';
    printf("%s\n", word);
    return word[0];
}

int bufp = 0;

int getch() /* get a (possibly pushed-back) character */
{
    int temp = bufp;
    bufp = 0;
    return (temp > 0) ? temp : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp != 0)
        printf("ungetch: too many characters\n");
    else
        bufp = c;
}

int check_symbol(char c) {
    switch (c) {
        case '_':
            return 0;
        case '"':
            return 1;
        case '/':
            return 1;
        case '*':
            return 1;
        default:
            return -1;
    }
}
