#include <stdio.h>
#include <stdlib.h>
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
int readFromFile();
int*** createArray(int size);
void copyArray(int*** source, int*** destination, int n);
void deleteArray(int*** array, int size);
void addNewCity(int size);
void deleteCity(int id, int size);

int main()
{
    char c;
    //createFile();
    int cities = readFromFile();
    List* curr_item = root;
    while(1)
    {
        for(int i=1; i<=cities; ++i)
        {
            if(i % 3 == 0 && i !=0 && i != cities)
                printf("%d) %s\n", i, curr_item->City.name);

            else if(strlen(curr_item->City.name) < 5)
                printf("%d) %s\t\t", i, curr_item->City.name);

            else
                printf("%d) %s\t", i, curr_item->City.name);

            curr_item = curr_item->next;
        }
        printf("\n\nA - Add a New City; C - Calculate Distance; D - Delete a city; Q - Quit\nEnter a character: ");
        c = getchar();
        while(c == '\n')
            c = getchar();
        if(c == 'A' || c == 'a')
            addNewCity(cities++);
        if(c == 'D' || c == 'd')
        {
            int id;
            printf("Which city do you want to delete (ID): ");
            scanf("%d", &id);
            deleteCity(id-1, cities--);
        }
        else if(c == 'Q' || c == 'q')
            break;
        curr_item = root;
    }
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

int*** A = NULL;

int readFromFile()
{
    int n, length;

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
    A = createArray(n);

    int i, j, distance, quality, rating;
    while(feof(input) == 0)
    {
        fread(&i, sizeof(int), 1, input);
        fread(&j, sizeof(int), 1, input);
        fread(&distance, sizeof(int), 1, input);
        fread(&quality, sizeof(int), 1, input);
        fread(&rating, sizeof(int), 1, input);

        A[i][j][0] = A[j][i][0] = distance;
        A[i][j][1] = A[j][i][1] = quality;
        A[i][j][2] = A[j][i][2] = rating;
    }
    return n;
}

void addNewCity(int size)
{
    List* new_item = (List*)malloc(sizeof(List));
    List* curr_item = root;

    new_item->City.id = size + 1;
    getchar();
    printf("\nName of new city: ");
    gets(new_item->City.name);
    printf("Population: ");
    scanf("%d", &new_item->City.population);
    printf("Area: ");
    scanf("%d", &new_item->City.area);
    getchar();
    printf("Founding Date: ");
    gets(new_item->City.date);
    new_item->next = NULL;

    while(curr_item->next != NULL)
        curr_item = curr_item->next;
    curr_item->next = new_item;

    int*** temp = createArray(size + 1);
    copyArray(A, temp, size);
    deleteArray(A, size);
    A = temp;

    int distance, quality, rating;
    for(int i=0; i <= size; ++i)
    {
        if(i != size)
        {
            printf("\n%d-%d:\nDistance: ", size + 1, i + 1);
            scanf("%d", &distance);
            printf("Quality: ");
            scanf("%d", &quality);
            printf("Rating: ");
            scanf("%d", &rating);
        }
        else
        {
            distance = 0;
            quality = rating = -1;
        }
        A[i][size][0] = A[size][i][0] = distance;
        A[i][size][1] = A[size][i][1] = quality;
        A[i][size][2] = A[size][i][2] = rating;
    }

    printf("\n");
}

void deleteCity(int id, int size)
{
    List* prev_item = root;
    while(prev_item->next->City.id == id-1)
        prev_item = prev_item->next;
    prev_item->next = prev_item->next->next;
    while(prev_item = prev_item->next)
        prev_item->City.id -= 1;
    
    for(int i=0; i<size; ++i)
        for(int j = id; j<size-1; ++j)
            for(int k=0; k<3; ++k)
                A[j][i][k] = A[j+1][i][k];

    for(int i=0; i<size; ++i)
        for(int j = id; j<size-1; ++j)
            for(int k=0; k<3; ++k)
                A[i][j][k] = A[i][j+1][k];
    
    int*** temp = createArray(size-1);
    copyArray(A, temp, size-1);
    deleteArray(A, size);
    A = temp;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            for (int k = 0; k < 3; k++) {
                printf("%3d ", A[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int*** createArray(int size)
{
    int*** array = (int***)malloc(size * sizeof(int**));

    if (array == NULL)
        exit(0);
    for (int i = 0; i < size; i++)
    {
        array[i] = (int**)malloc(size * sizeof(int*));

        if (array[i] == NULL)
            exit(i);

        for (int j = 0; j < size; j++)
        {
            array[i][j] = (int*)malloc(3 * sizeof(int));
            if (array[i][j] == NULL)
                exit(0);
        }
    }

    return array;
}

void copyArray(int*** source, int*** destination, int size)
{
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            for(int k=0; k<3; ++k)
                destination[i][j][k] = source[i][j][k];
}

void deleteArray(int*** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            free(array[i][j]);
        }
        free(array[i]);
    }
    free(array);
}
