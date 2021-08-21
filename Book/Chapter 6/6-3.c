#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode              /* the tree node: */
{
    char* word;           /* points to the text */
    int lines[100];            /* number of occurrences */
    struct tnode* left;   /* left child */
    struct tnode* right;  /* right child */
};

struct tnode* addtree(struct tnode*, char*);
void treeprint(struct tnode*);
int getword(char*, int);
int checknoise(char*);
void strlower(char**);
struct tnode* talloc(void);
char* strdUp(char*);

int bufp = 0;
int line_number = 1;

/* 6-3. Write a cross-referencer that prints a list of all words in a document, and for each word,
 * a list of the line numbers on which it occurs. Remove noise words like ``the,'' ``and,''
 * and so on.*/
int main()
{
    struct tnode* root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) && checknoise(word))
            root = addtree(root, word);
    treeprint(root);
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
        p->lines[0] = line_number;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
    {
        int i = 0;
        for (; i < 100 && p->lines[i]; ++i)
            if (p->lines[i] == line_number)
                return p;

        p->lines[i] = line_number;
    } else if (cond < 0)   /* less than into left subtree */
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
        printf("%s\t{", p->word);
        for (int i = 0; i < 100 && p->lines[i]; ++i)
            p->lines[i + 1] ? printf("%d, ", p->lines[i]) : printf("%d}\n", p->lines[i]);
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
    struct tnode* temp = (struct tnode*) malloc(sizeof(struct tnode));
    for (int i = 0; i < 100; ++i)
        temp->lines[i] = 0;
    return temp;
}

int getch() /* get a (possibly pushed-back) character */
{
    int temp = bufp;
    bufp = 0;
    if (temp > 0)
        return temp;
    else
    {
        char c = getchar();
        if (c == '\n')
            line_number++;
        return c;
    }
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

int checknoise(char* word)
{
    char words[][10] = {"a", "the", "and", "an", "as", "for", "from", "if", "of", "on", "or"};

    strlower(&word);
    for (int i = 0; i < 11; ++i)
        if (strcmp(words[i], word) == 0)
            return 0;
    return 1;
}

void strlower(char** word)
{
    for (int i = 0; (*word)[i]; ++i)
        (*word)[i] = tolower((*word)[i]);
}
