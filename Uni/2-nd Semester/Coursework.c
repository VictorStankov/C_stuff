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

List* root = NULL;  // Define root list entry.

void createFile();
int readFromFile();
int*** createArray(int size);
void copyArray(int*** source, int*** destination, int n);
void deleteArray(int*** array, int size);
void addNewCity(int size);
void deleteCity(int id, int size);
void calculateDistance();

int main()
{
    char c;
    int cities = readFromFile();  // Reads from the file and returns the number of cities read from the file.
    List* curr_item = root;
    while(1)
    {
        for(int i=1; i<=cities; ++i)  // Displays the cities on the screen with their IDs.
        {
            if(i % 3 == 0 && i !=0 && i != cities)  // Limits only 3 cities on a row.
                printf("%d) %s\n", i, curr_item->City.name);

            else if(strlen(curr_item->City.name) < 5)  // Fixes tab characters based on the city's name's length.
                printf("%d) %s\t\t", i, curr_item->City.name);

            else
                printf("%d) %s\t", i, curr_item->City.name);

            curr_item = curr_item->next;
        }
        printf("\n\nA - Add a New City; C - Calculate Distance; D - Delete a city; Q - Quit\nEnter a character: ");
        c = getchar();  // Awaits user input.
        while(c == '\n')  // Consumes any leftover newline characters.
            c = getchar();
        if(c == 'A' || c == 'a')
            addNewCity(cities++);  // Adds a new city and modifies the counter after that.
        else if(c == 'C' || c == 'c')
            calculateDistance();
        else if(c == 'D' || c == 'd')
        {
            int id;
            printf("Which city do you want to delete (ID): ");
            scanf("%d", &id);
            deleteCity(id-1, cities--);  // Removes the selected city and modifies the counter after that.
        }
        else if(c == 'Q' || c == 'q')
            break;  // Kills the program.
        else
            printf("Invalid Character!\n");  // Scolds the user for not following simple commands.
        curr_item = root;  // Resets the current item for the next loop.
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
    getchar();  // Used to consume the excess \n character.
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

    for(int i=0; i<n; ++i)  // Loop that gets the distances between cities.
        for(int j=i; j<n; ++j)
        {
            if(i == j)  // Check if the city is the same.
            {
                distance = 0;
                quality = -1;
                rating = -1;
            }
            else
            {
                printf("\n%d-%d:\nDistance: ", i + 1, j + 1);
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
    if(input == NULL)  // If file opening fails, a new file is created.
    {
        printf("File not found, creating new one...\n\n");
        createFile();
    }

    input = fopen("cities.bin", "rb");
    if(input == NULL)  // If it fails again, exit the program.
    {
        printf("Couldn't open file. Exiting...\n");
        exit(0);
    }
    fread(&n, sizeof(int), 1, input);  // Read how many cities are to be read.

    for(int i=0; i<n; ++i)
    {
        List* new_item = (List*)malloc(sizeof(List));  // Create a new list item.
        fread(&new_item->City.id, sizeof(int), 1, input);
        fread(&length, sizeof(int), 1, input);
        fread(new_item->City.name, sizeof(char), length, input);
        new_item->City.name[length] = '\0';  // Put a terminating character just in case.
        fread(&new_item->City.population, sizeof(int), 1, input);
        fread(&new_item->City.area, sizeof(int), 1, input);
        fread(&length, sizeof(int), 1, input);
        fread(new_item->City.date, sizeof(char), length, input);
        new_item->City.date[length] = '\0';  // Same here.
        new_item->next = NULL;  // Set the next pointer to NULL to avoid problems.

        if(root == NULL)  // Check if the root item has no values and assigns it the new item.
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
    A = createArray(n);  // Creates a 3D (N x N x 3) array.

    int i, j, distance, quality, rating;
    while(feof(input) == 0)  // Reads from the file and fills in the array.
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
    List* new_item = (List*)malloc(sizeof(List));  // Create new list item.
    List* curr_item = root;

    new_item->City.id = size + 1;  // Set the ID based on the size of the array.
    getchar();  // Used to consume the excess \n character.
    printf("\nName of new city: ");
    gets(new_item->City.name);
    printf("Population: ");
    scanf("%d", &new_item->City.population);
    printf("Area: ");
    scanf("%d", &new_item->City.area);
    getchar();  // Same here.
    printf("Founding Date: ");
    gets(new_item->City.date);
    new_item->next = NULL;  // Set the next pointer to NULL to avoid problems.

    while(curr_item->next != NULL)  // Scroll to the last node.
        curr_item = curr_item->next;
    curr_item->next = new_item;  // Assign the new city/item.

    int*** temp = createArray(size + 1);  // Temp array that's bigger than the original one.
    copyArray(A, temp, size);  // Copy the contents of the original array to the temp one.
    deleteArray(A, size);  // Free the memory occupied from the old array.
    A = temp;  // Set A to point to the temporary array (which isn't temporary anymore).

    int distance, quality, rating;
    for(int i=0; i <= size; ++i)  // Define distances between the new city and the rest.
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

    while(prev_item->next->City.id == id-1)  // Scroll to the item before the one we want to remove.
        prev_item = prev_item->next;
    
    List* del_item = prev_item->next;  // Save the to-be-deleted item in a new variable.
    prev_item->next = prev_item->next->next;  // Set the previous item's "next" to point to the one after the deleted item.
    free(del_item);  // Free the memory.

    while(prev_item = prev_item->next)  // Adjust following cities' IDs 
        prev_item->City.id -= 1;
    
    for(int i=0; i<size; ++i)  // Deletes the row of data of the city.
        for(int j = id; j<size-1; ++j)
            for(int k=0; k<3; ++k)
                A[j][i][k] = A[j+1][i][k];

    for(int i=0; i<size; ++i)  // Deletes the column of data of the city.
        for(int j = id; j<size-1; ++j)
            for(int k=0; k<3; ++k)
                A[i][j][k] = A[i][j+1][k];
    
    int*** temp = createArray(size-1);  // Create a smaller temporary array.
    copyArray(A, temp, size-1);  // Copy the contents of the adjusted array to the temporary one (for cleanliness).
    deleteArray(A, size);  // Free the memory occupied from the old array.
    A = temp;  // Set A to point to the temporary array (which isn't temporary anymore).
}

void calculateDistance()
{
    int id, prev_id, distance = 0, rating=0, n=0;
    printf("Enter the same ID twice to stop.\n\n");
    printf("ID of starting city: ");
    scanf("%d", &prev_id);  // Get the starting city's ID.
    while(1)
    {
        printf("Enter city ID: ");
        scanf("%d", &id);  // Get following cities' IDs
        if(prev_id == id)  // If it's the same with the previous ID, stop and display results.
            break;
        distance += A[prev_id - 1][id - 1][0];
        rating += A[prev_id - 1][id - 1][2];
        n++;  // Used for averaging the ratings.
        prev_id = id;
    }
    printf("\nTotal distance: %d\nAverage Rating: %.2f\n\n", distance, (float)rating / n);
}

int*** createArray(int size)  // Creates a 3D (N x N x 3) array.
{
    int*** array = (int***)malloc(size * sizeof(int**));  // Create a triple int pointer.

    if (array == NULL)
        exit(0);
    for (int i = 0; i < size; i++)
    {
        array[i] = (int**)malloc(size * sizeof(int*));  // Fill every item of the triple pointer with a double int pointer.

        if (array[i] == NULL)
            exit(i);

        for (int j = 0; j < size; j++)
        {
            array[i][j] = (int*)malloc(3 * sizeof(int));  // Fill every item of the double pointer with 3 int pointers.
            if (array[i][j] == NULL)
                exit(0);
        }
    }

    return array;
}

void copyArray(int*** source, int*** destination, int size)  // Copies the contents from one array to another based on given size.
{
    for(int i=0; i<size; ++i)
        for(int j=0; j<size; ++j)
            for(int k=0; k<3; ++k)
                destination[i][j][k] = source[i][j][k];
}

void deleteArray(int*** array, int size)  // Free the memory occupied from an array.
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
