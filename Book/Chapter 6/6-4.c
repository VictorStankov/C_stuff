#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct entry              /* the tree node: */
{
    char* word;           /* points to the text */
    int occurrences;       /* number of occurrences */
};

int getword(char*, int);
void addword(char* word);
int checknoise(char*);
void strlower(char**);
char* strdUp(char*);

struct entry* root;
int f = 0, bufp = 0;

/* 6-3. Write a cross-referencer that prints a list of all words in a document, and for each word,
 * a list of the line numbers on which it occurs. Remove noise words like "the", "and"
 * and so on.*/
int main()
{
    char word[MAXWORD];
	struct entry** words = (struct entry**)malloc(100 * sizeof(struct entry));

    //for (int i = 0; i < 100; i++)
        //words[i] = NULL;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) && checknoise(word))
            addword(word);

    int sort(const void* a, const void* b);
    qsort(words, f, sizeof(struct entry), sort);
    for (int k = 0; k < f; ++k)
        printf("%s\t%d\n", words[k]->word, words[k]->occurrences);
    return 0;
}

void addword(char* word)
{
	extern struct entry** words;
    if (f != 0 && f % 100 == 0)
    {
        words = realloc(words, (f + 100) * sizeof(struct entry));
        for (int i = f; i < f + 100; ++i)
            words[i] = NULL;
    }
    for (int j = 0; j < f; ++j)
        if (strcmp(word, words[j]->word) == 0)
        {
            words[j]->occurrences++;
            return;
        }

    words[f] = (struct entry*)malloc(sizeof(struct entry));
    if (words[f] == NULL)
        exit(1);
    words[f]->word = strdUp(word);
    words[f++]->occurrences = 1;
}

int sort(const void* a, const void* b)
{
    struct entry* first = (struct entry*)a;
    struct entry* second = (struct entry*)b;
    printf("%s %d | %s %d\n", first->word, first->occurrences, second->word, second->occurrences);
	return first->occurrences - second->occurrences;
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

int checknoise(char* word)
{
    char words[][10] = {
            "a", "the", "and", "an", "as", "for", "from", "if", "of", "on", "or"
    };

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
