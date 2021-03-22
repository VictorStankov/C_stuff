#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(char brand[], char model[], double engine_V, double price, char registered);
void readFromFile();

int main()
{
	char brand[] = "Mercedes", model[5] = "CLS", registered = 'Y';
	double engine_V = 150.50, price = 2026.15;

	writeToFile(brand, model, engine_V, price, registered);
	readFromFile();

	return 0;
}

void writeToFile(char brand[], char model[], double engine_V, double price, char registered)
{
    unsigned int sizeOfString;
    FILE* binary = fopen("3.bin", "wb");
    if(binary == NULL)
        exit(1);
    FILE* text = fopen("3.txt", "w");
    if(text == NULL)
        exit(2);

    // Disgusting amount of ugly code
    sizeOfString = strlen(brand) + 1;
    fwrite(&sizeOfString, sizeof(unsigned int), 1, binary);
    fwrite(brand, sizeof(char), sizeOfString, binary);

    sizeOfString = strlen(model) + 1;
    fwrite(&sizeOfString, sizeof(unsigned int), 1, binary);
    fwrite(model, sizeof(char), sizeOfString, binary);

    fwrite(&engine_V, sizeof(double), 1, binary);
    fwrite(&price, sizeof(double), 1, binary);
    fwrite(&registered, sizeof(char), 1, binary);

    fprintf(text, "%s, %s, %f, %f, %c\n", brand, model, engine_V, price, registered);

    fclose(binary);
    fclose(text);
}

void readFromFile()
{
    unsigned int sizeOfString;
    char brand[10], model[5], registered;
	double engine_V, price;
    char everything[100];
    int i = 0;

    FILE* binary = fopen("3.bin", "rb");
    if(binary == NULL)
        exit(3);
    FILE* text = fopen("3.txt", "r");
    if(text == NULL)
        exit(4);

    // Same here
    fread(&sizeOfString, sizeof(unsigned int), 1, binary);
    fread(brand, sizeof(char), sizeOfString, binary);

    fread(&sizeOfString, sizeof(unsigned int), 1, binary);
    fread(model, sizeof(char), sizeOfString, binary);

    fread(&engine_V, sizeof(double), 1, binary);
    fread(&price, sizeof(double), 1, binary);
    fread(&registered, sizeof(char), 1, binary);

    printf("Binary: %s, %s, %f, %f, %c\n", brand, model, engine_V, price, registered);

    fgets(everything, 100, text);
    printf("TEXT: %s\n", everything);

    fclose(binary);
    fclose(text);
}
