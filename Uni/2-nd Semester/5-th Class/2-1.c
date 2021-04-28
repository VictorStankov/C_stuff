#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile();
void readFromFile();

int main()
{
	createFile();
	readFromFile();

	return 0;
}

void createFile()
{
    long ID = 0;
    int length;
    char productName[30], companyName[15], description[20];
    double price, weight;

    printf("Set ID to 0 to stop\n");

    FILE* file = fopen("2-1.bin", "wb");
    if(file == NULL)
        exit(1);

    while(1)
    {
        printf("ID: ");
        scanf("%d", &ID);
        if(ID == 0)
            break;
        printf("Product Name: ");
        scanf("%s", productName);
        printf("Company Name: ");
        scanf("%s", companyName);
        printf("Price: ");
        scanf("%lf", &price);
        printf("Weight: ");
        scanf("%lf", &weight);
        printf("Description: ");
        scanf("%s", description);

        fwrite(&ID, sizeof(long), 1, file);

        length = strlen(productName);
        printf("\n%d | %s | %s | %f | %f | %s\n", ID, productName, companyName, price, weight, description);
        fwrite(&length, sizeof(int), 1, file);
        fwrite(productName, 1, strlen(productName), file);

        length = strlen(companyName);
        fwrite(&length, sizeof(int), 1, file);
        fwrite(companyName, 1, strlen(companyName), file);

        fwrite(&price, sizeof(double), 1, file);

        fwrite(&weight, sizeof(double), 1, file);

        length = strlen(description);
        fwrite(&length, sizeof(int), 1, file);
        fwrite(description, 1, strlen(description), file);
    }
    fclose(file);
}

void readFromFile()
{
    long ID, length;
    char searchedCompany[15];
    double price=0, weight=0;

    FILE* binary = fopen("2-1.bin", "rb");
    if(binary == NULL)
        exit(2);
    FILE* text = fopen("2-1.txt", "w");
    if(text == NULL)
        exit(3);

    printf("Search for products by company name: ");
    scanf("%s", searchedCompany);

    while(feof(binary) == 0)
    {
        fread(&ID, sizeof(long), 1, binary);

        fread(&length, sizeof(int), 1, binary);
        char* productName = (char*) malloc(length);
        fread(productName, sizeof(char), length, binary);

        fread(&length, sizeof(int), 1, binary);
        char* companyName = (char*) malloc(length);
        fread(companyName, sizeof(char), length, binary);

        fread(&price, sizeof(double), 1, binary);
        fread(&weight, sizeof(double), 1, binary);

        fread(&length, sizeof(int), 1, binary);
        char* description = (char*) malloc(length);
        fread(description, sizeof(char), length, binary);

        printf("\n%d | %s | %s | %f | %f | %s\n", ID, productName, companyName, price, weight, description);
        printf("%d\n", strcmp(companyName, searchedCompany));
        if(strcmp(companyName, searchedCompany) == 0)
            fprintf(text, "%d, %s, %s, %f, %f, %s\n", ID, productName, companyName, price, weight, description);
        printf("%d", feof(binary));
        printf("%d", feof(binary));

        free(productName);
        free(companyName);
        free(description);
    }
    fclose(binary);
    fclose(text);
}
