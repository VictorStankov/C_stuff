#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define HASHSIZE 101
#define MAXWORD 100

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

int bufp = 0;
static struct nlist *hashtab[HASHSIZE]; /* pointer table */
struct nlist *lookup(char *s);
int getword(char* word, int lim);
struct nlist *install(char *name, char *defn);

/* 6-6. Implement a simple version of the #define processor (i.e., no arguments)
 * suitable for use with C programs, based on the routines of this section. You may
 * also find getch and ungetch helpful.*/

int main()
{
    char word[MAXWORD], name[MAXWORD], defn[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
    {
        if(strcmp(word, "#define") == 0)
        {
            if(getword(name, MAXWORD) == EOF || getword(defn, MAXWORD) == EOF)
                return 0;
            printf("%s\n", install(strdup(name), strdup(defn)) ? "Successfully added entry!" : "Error adding entry!");
        }
    }
    return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));

        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

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

/* getword:  get next word or character from input */
int getword(char* word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char* w = word;

    while (isspace(c = getch()));
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '#')
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '#')
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}