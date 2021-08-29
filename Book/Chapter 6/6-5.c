#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define HASHSIZE 101

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */
int undef(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

/* 6-5. Write a function undef that will remove a name and definition from the table
 * maintained by lookup and install.*/

int main()
{
    char c, name[100], defn[100];

    printf("I - install, L - lookup, U - undefine:\n");
    while((c = getchar()) != EOF)
    {
        switch (tolower(c))
        {
        case 'q':
            return 0;

        case 'i':
            getchar();
            printf("Enter name of variable: ");
            gets(name);
            printf("Enter definition: ");
            gets(defn);
            if(install(name, defn))
                printf("Successfully added entry!\n");
            else
                printf("Error adding entry!\n");
            break;

        case 'l':
            printf("Enter name of variable: ");
            getchar();
            gets(name);
            struct nlist* result = lookup(name);
            printf("%s\n", result ? result->defn : "Not found!");
            break;

        case 'u':
            printf("Enter name of variable: ");
            getchar();
            gets(name);
            printf("%s\n", undef(name) ? "Not found!" : "Entry successfully deleted");
            break;
        
        default:
            printf("Not understood!");
            break;
        }
    }
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

int undef(char *s)
{
    struct nlist *item = lookup(s);

    if(item == NULL)
        return -1;

    struct nlist* root = hashtab[hash(s)], *curr_item = root;
    if(item->next != NULL)
    {
        for(; curr_item != item; curr_item = curr_item->next);
            ;
        curr_item->next = NULL;
    }
    else
        root = NULL;
    hashtab[hash(s)] = root;
    
    free(item->name);
    free(item->defn);
    free(item);
    return 0;
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
