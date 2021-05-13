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
    City;
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
        for(int j=0; j<n; ++j)
        {
            if(i == j)
            {
                distance = -1;
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
    int n, id, population, area, length;
    char name[30], date[15];

    List* curr_item = root;
    FILE* input = fopen("cities.bin", "rb");
    fread(&n, sizeof(int), 1, input);
    printf("%d\n", n);
    for(int i=0; i<n; ++i)
    {
        fread(&id, sizeof(int), 1, input);
        fread(&length, sizeof(int), 1, input);
        fread(name, sizeof(char), length, input);
        fread(&population, sizeof(int), 1, input);
        fread(&area, sizeof(int), 1, input);
        fread(&length, sizeof(int), 1, input);
        fread(date, sizeof(char), length, input);
        printf("%d %s %d %d %s\n", id, name, population, area, date);
        if(!root)
        {
            
        }
    }
}