#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode              /* the tree node: */
{
    char* word;           /* points to the text */
    int count;            /* number of occurrences */
    struct tnode* left;   /* left child */
    struct tnode* right;  /* right child */
};

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char*, int);
int getvariable(char* word, int lim);
struct tnode* talloc(void);
char* strdUp(char*);

int bufp = 0;

/* 6-2. Write a program that reads a C program and prints in alphabetical order each 
 * group of variable names that are identical in the first 6 characters, but different 
 * somewhere thereafter. Don't count words within strings and comments. Make 6 a parameter 
 * that can be set from the command line*/

/* word frequency count */
int main(int argc, char* argv[])
{
    struct tnode* root, * groups[100];
    char word[MAXWORD];
    int delimiter = 6;

    if (argc == 2 && (*++argv)[0] == '-')
        delimiter = atoi(*argv) * -1;

    for (int i = 0; i < 100; ++i)
        groups[i] = NULL;

    while (getvariable(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            for (int i = 0; i < 100; ++i)
            {
                if (groups[i] == NULL || strncmp(groups[i]->word, word, delimiter) == 0)
                {
                    groups[i] = addtree(groups[i], word);
                    break;
                }
            }
    for (int i = 0; i < 100 && groups[i]; ++i)
    {
        treeprint(groups[i]);
        printf("\n");
    }
    return 0;
}

/* addtree:  add a node with w, at or below p */
struct tnode* addtree(struct tnode* p, char* w)
{
    int cond;

    if (p == NULL)
    {     /* a new word has arrived */
        p = talloc();    /* make a new node */
        p->word = strdUp(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;      /* repeated word */
    else if (cond < 0)   /* less than into left subtree */
        p->left = addtree(p->left, w);
    else             /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint:  in-order print of tree p */
void treeprint(struct tnode* p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
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
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

/* talloc:  make a tnode */
struct tnode* talloc(void)
{
    return (struct tnode*) malloc(sizeof(struct tnode));
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

char* strdUp(char* s)   /* make a duplicate of s */
{
    char* p;

    p = (char*) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getvariable(char* word, int lim)
{
    char words[][10] = {"void", "int", "double", "float", "char", "struct"};
    while (getword(word, lim) != EOF)
    {
        for (int i = 0; i < 6; ++i)
            if (strcmp(word, words[i]) == 0)
            {
                getword(word, lim);
                if (isalpha(word[0]))
                    return word[0];
            }
    }
    return EOF;
}
