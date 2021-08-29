#include <stdio.h>
#include <string.h>
#define LENGTH 100

int compare(FILE* first, FILE* second);

/* 7-6. Write a program to compare two files, printing the first line where they differ.*/

int main()
{
    FILE *file_0 = fopen("first.txt", "r"), *file_1 = fopen("second.txt", "r");
    if(file_0 == NULL || file_1 == NULL)
    {
        fprintf(stderr, "File(s) not found!\n");
        exit(1);
    }

    if(compare(file_0, file_1) == 0)
        printf("Files are identical.\n");
    
    return 0;
}

int compare(FILE* first, FILE* second)
{
    int i = 0;
    char input_0[LENGTH], input_1[LENGTH];
    while(fgets(input_0, LENGTH, first) && fgets(input_1, LENGTH, second))
    {
        ++i;
        if(strcmp(input_0, input_1) != 0)
        {
            printf("Line %d:\n", i);
            puts(input_0);
            puts(input_1);
            return 1;
        }
    }
    return 0;
}