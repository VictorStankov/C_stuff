#include <stdio.h>
#include <string.h>

struct City
{
    int id, population, area;
    char name[30], date[15];
};
typedef struct City City;

struct List
{
    struct City City;
    struct List* next;
};
typedef struct List List;

List* root = NULL;

void createFile();
void readFromFile();

int main()
{
    //createFile();
    readFromFile();
    return 0;
}

void createFile()
{
    int n, population, area, length;
    char name[30], date[15];
    FILE* output = fopen("cities.bin", "wb");

    printf("How many cities are you going to enter: ");
    scanf("%d", &n);
    getchar();
    fwrite(&n, sizeof(int), 1, output);

    for(int i=0; i<n; ++i)
    {
        printf("\n%d) Name: ", i+1);
        gets(name);
        printf("Population: ");
        scanf("%d", &population);
        printf("Area: ");
        scanf("%d", &area);
        getchar();
        printf("Founding Date: ");
        gets(date);

        fwrite(&i, sizeof(int), 1, output);
        length = strlen(name);
        fwrite(&length, sizeof(int), 1, output);
        fwrite(name, sizeof(char), length, output);
        fwrite(&population, sizeof(int), 1, output);
        fwrite(&area, sizeof(int), 1, output);
        length = strlen(date);
        fwrite(&length, sizeof(int), 1, output);
        fwrite(date, sizeof(char), length, output);
    }

    int distance, quality, rating;

    for(int i=0; i<n; ++i)
        for(int j=i; j<n; ++j)
        {
            if(i == j)
            {
                distance = 0;
                quality = -1;
                rating = -1;
            }
            else
            {
                printf("%d-%d:\nDistance: ", i + 1, j + 1);
                scanf("%d", &distance);
                printf("Quality: ");
                scanf("%d", &quality);
                printf("Rating: ");
                scanf("%d", &rating);
            }
            
            fwrite(&i, sizeof(int), 1, output);
            fwrite(&j, sizeof(int), 1, output);
            fwrite(&distance, sizeof(int), 1, output);
            fwrite(&quality, sizeof(int), 1, output);
            fwrite(&rating, sizeof(int), 1, output);
        }

    fclose(output);
}

void readFromFile()
{
    int n, length;

    List* curr_item = root;
    FILE* input = fopen("cities.bin", "rb");
    fread(&n, sizeof(int), 1, input);

    for(int i=0; i<n; ++i)
    {
        List* new_item = (List*)malloc(sizeof(List));
        fread(&new_item->City.id, sizeof(int), 1, input);
        fread(&length, sizeof(int), 1, input);
        fread(new_item->City.name, sizeof(char), length, input);
        new_item->City.name[length] = '\0';
        fread(&new_item->City.population, sizeof(int), 1, input);
        fread(&new_item->City.area, sizeof(int), 1, input);
        fread(&length, sizeof(int), 1, input);
        fread(new_item->City.date, sizeof(char), length, input);
        new_item->City.date[length] = '\0';
        new_item->next = NULL;

        printf("%d %s %d %d %s\n", new_item->City.id, new_item->City.name, new_item->City.population, new_item->City.area, new_item->City.date);

        if(root == NULL)
        {
            root = new_item;
        }
        else
        {
            List* curr_item = root;
            while(curr_item->next != NULL)
                curr_item = curr_item->next;  // Scroll to the last node.
            curr_item->next = new_item;
        }
    }
    int*** A = (int***)malloc(n * sizeof(int**));
 
    if (A == NULL)
        exit(0);
 
    for (int i = 0; i < n; i++)
    {
        A[i] = (int**)malloc(n * sizeof(int*));
 
        if (A[i] == NULL)
            exit(i);
 
        for (int j = 0; j < n; j++)
        {
            A[i][j] = (int*)malloc(3 * sizeof(int));
            if (A[i][j] == NULL)
                exit(0);
        }
    }

    int i, j, distance, quality, rating;
    while(feof(input) == 0)
    {
        fread(&i, sizeof(int), 1, input);
        fread(&j, sizeof(int), 1, input);
        fread(&distance, sizeof(int), 1, input);
        fread(&quality, sizeof(int), 1, input);
        fread(&rating, sizeof(int), 1, input);
        // printf("[%d] [%d] %d %d %d\n", i, j, distance, quality, rating);
        A[i][j][0] = A[j][i][0] = distance;
        A[i][j][1] = A[j][i][1] = quality;
        A[i][j][2] = A[j][i][2] = rating;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++) {
                printf("%d ", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
