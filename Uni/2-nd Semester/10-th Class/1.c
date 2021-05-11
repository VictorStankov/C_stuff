#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cage
{
    char type[10], id[10];
    int age;
};
typedef struct Cage Cage;

struct QueueNode
{
    struct Cage node;
    struct QueueNode* next;
};
typedef struct QueueNode QueueNode;

struct StackNode
{
    struct Cage node;
    struct StackNode *next;
};
typedef struct StackNode StackNode;

void createFile();
void loadNewcomers(QueueNode** root);
int animalTypeCount(QueueNode* root, char *animalType);
StackNode* deworming(QueueNode* root);
void storeAnimals(FILE *fp, StackNode* root);

int main()
{
    QueueNode* root = NULL;  // Define queue root.
    //createFile();  // Simple function to create a binary file.
    loadNewcomers(&root);  // Pass a pointer to root so we can change its value.
    printf("%d\n", animalTypeCount(root, "cat"));
    StackNode* stack_root = deworming(root);

    FILE* txt = fopen("deworming.txt", "w");
    if(txt == NULL)
        exit(3);
    
    storeAnimals(txt, stack_root);
    return 0;
}

void createFile()
{
    int n, age, length;
    char type[10], id[10];
    FILE* output = fopen("newcomers.bin", "wb");

    if(output == NULL)
        exit(1);

    printf("How many animals are you going to enter: ");
    scanf("%d", &n);
    getchar();  // Used for consuming the newline character the scanf pushes back to the input.
    fwrite(&n, sizeof(int), 1, output);

    for(int i=0; i<n; ++i)
    {
        printf("\nID of the animal: ");
        gets(id);
        printf("Type: ");
        gets(type);
        printf("Age: ");
        scanf("%d", &age);
        getchar();  // Same here.

        length = strlen(id);
        fwrite(&length, sizeof(int), 1, output);
        fwrite(id, sizeof(char), length, output);
        length = strlen(type);
        fwrite(&length, sizeof(int), 1, output);
        fwrite(type, sizeof(char), length, output);
        fwrite(&age, sizeof(int), 1, output);
    }
    fclose(output);
}

void loadNewcomers(QueueNode** root)
{
    int n, length;

    FILE* input = fopen("newcomers.bin", "rb");

    if(input == NULL)
        exit(2);
    
    fread(&n, sizeof(int), 1, input);

    for(int i=0; i<n; ++i)
    {
        QueueNode* new_item = (QueueNode *)malloc(sizeof(QueueNode));  // Create new queue nodes for every new item.

        fread(&length, sizeof(int), 1, input);
        fread(&new_item->node.id, sizeof(char), length, input);
        new_item->node.id[length] = '\0';  // Set terminating characters because for some reason it doesn't do it automatically.
        fread(&length, sizeof(int), 1, input);
        fread(&new_item->node.type, sizeof(char), length, input);
        new_item->node.type[length] = '\0';
        fread(&new_item->node.age, sizeof(int), 1, input);

        if(*root == NULL)  // This runs only once to set the value of the root node.
        {
            *root = new_item;
            (*root)->next = NULL;
        }
        else
        {
            QueueNode* curr_item = *root;
            while(curr_item->next != NULL)
                curr_item = curr_item->next;  // Scroll to the last node.
            curr_item->next = new_item;
            curr_item->next->next = NULL;
        }
    }
    fclose(input);
}

int animalTypeCount(QueueNode* root, char *animalType)
{
    int count = 0;

    QueueNode* curr_item = root;
    while(curr_item != NULL)  // Scroll through the nodes.
    {
        if(!strcmp(curr_item->node.type, animalType))  // If they're the same, count++.
            count++;
        curr_item = curr_item->next;
    }
    return count;
}

StackNode* deworming(QueueNode* root)
{
    int i=-1;
    Cage* cage_list = (Cage*)malloc(10 * sizeof(Cage));  // Define a dynamic array of Cage structures with size - 10.

    QueueNode* curr_item = root;
    while(curr_item != NULL)  // Start scrolling through the Queue, while keeping track of how many times it has looped.
    {
        if(++i % 10 == 0 && i != 0)  // If there are more queue items than the Cage array, reallocate more memory to it.
            cage_list = realloc(cage_list, sizeof(Cage) * (i+10));
        cage_list[i] = curr_item->node;
        curr_item = curr_item->next;
    }

    int cmpfunc (const void * a, const void * b);  // Define a comparing function for sorting.
    qsort(cage_list, i+1, sizeof(Cage), cmpfunc);  // Function from <stdlib.h> that does all the heavy lifting.
    
    StackNode *stack_root = NULL;
    for(int t = 0; t <= i; ++t)  // Create our stack.
    {
        StackNode* curr_stack_item = (StackNode *)malloc(sizeof(StackNode));
        curr_stack_item->node = cage_list[t];
        curr_stack_item->next = stack_root;
        stack_root = curr_stack_item;
    }
    return stack_root;
}

int cmpfunc (const void * a, const void * b) 
{
    Cage *e1 = (Cage *)a;
    Cage *e2 = (Cage *)b;
    return e2->age - e1->age;  // Sort by age.
}

void storeAnimals(FILE *fp, StackNode* root)
{
    StackNode* curr_item = root;
    while(curr_item != NULL)
    {
        fprintf(fp, "ID: %s; Type: %s; Age: %d\n", curr_item->node.id, curr_item->node.type, curr_item->node.age);
        curr_item = curr_item->next;
    }
}
