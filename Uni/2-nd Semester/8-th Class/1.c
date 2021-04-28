#include <stdio.h>
#include <stdlib.h>

struct Artist
{
    char name[30], nationality[30];
    int age;
    float income;
};
typedef struct Artist Artist;

struct List
{
    Artist Artist;
    struct List* next;
};
typedef struct List List;

void addNewArtist(List* root);

int main()
{
    List* root = NULL;
	addNewArtist(root);
	printf("%x\n", root);
	printf("%s, %d, %s, %f\n", root->Artist.name, root->Artist.age, root->Artist.nationality, root->Artist.income);
	return 0;
}

void addNewArtist(List* root)
{
    List *curr_item = root;
    if(root != NULL)
    {
        while(curr_item->next != NULL)
            curr_item = curr_item->next;
    }

    List *new_item = NULL;
    struct Artist Artist;
    new_item = (List *)malloc(sizeof(List));
    scanf("%s", &Artist.name);
    scanf("%d", &Artist.age);
    scanf("%s", &Artist.nationality);
    scanf("%f", &Artist.income);
    new_item->Artist = Artist;
    new_item->next = NULL;
    printf("%s, %d, %s, %f\n", new_item->Artist.name, new_item->Artist.age, new_item->Artist.nationality, new_item->Artist.income);
    if(root == NULL)
    {
        root = new_item;
        printf("%x\n", root);
    }
    else curr_item->next = new_item;
}
