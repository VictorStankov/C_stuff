#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Phone
{
    char brand[30], model[30];
    int length_brand, length_model, number;
    double price;
};
typedef struct Phone Phone;

struct List
{
    Phone Phone;
    struct List* next;
};
typedef struct List List;

List* root = NULL;

void createFile();
void sortFile();

int main()
{
    createFile();
    sortFile();
	return 0;
}

void createFile()
{
    int length_brand, length_model, number=-1;
    char brand[30], model[30];
    double price;

    printf("Set any of the parameters to 0 to stop\n");

    FILE* file = fopen("phones.bin", "wb");
    if(file == NULL)
        exit(1);

    while(1)
    {
        printf("\nID: %d\n", ++number);
        printf("Brand Name: ");
        scanf("%s", brand);
        if(!strcmp(brand, "0"))
            break;
        printf("Model Name: ");
        scanf("%s", model);
        if(!strcmp(model, "0"))
            break;
        printf("Price: ");
        scanf("%lf", &price);
        if(price == 0)
            break;


        length_brand = strlen(brand);
        fwrite(&length_brand, sizeof(int), 1, file);
        fwrite(brand, 1, strlen(brand), file);

        length_model = strlen(model);
        fwrite(&length_model, sizeof(int), 1, file);
        fwrite(model, 1, strlen(model), file);

        fwrite(&number, sizeof(int), 1, file);

        fwrite(&price, sizeof(double), 1, file);
    }
    fclose(file);
}

void sortFile()
{
    int i=0;
    float prices = 0;
    FILE* input = fopen("phones.bin", "rb");
    if(input == NULL)
        exit(2);

    FILE* output = fopen("sony.bin", "wb");
    if(output == NULL)
        exit(3);

    while(!feof(input))
    {
        if(i == 2)
            break;

        ++i;
        List *new_item = (List *)malloc(sizeof(List));

        fread(&new_item->Phone.length_brand, sizeof(int), 1, input);
        fread(&new_item->Phone.brand, sizeof(char), new_item->Phone.length_brand, input);

        fread(&new_item->Phone.length_model, sizeof(int), 1, input);
        fread(&new_item->Phone.model, sizeof(char), new_item->Phone.length_model, input);

        fread(&new_item->Phone.number, sizeof(int), 1, input);
        fread(&new_item->Phone.price, sizeof(double), 1, input);
        prices += new_item->Phone.price;
        new_item->Phone.brand[new_item->Phone.length_brand] = '\0';
        new_item->Phone.model[new_item->Phone.length_model] = '\0';
        printf("\n%d | %s | %d | %s | %d | %f\n", new_item->Phone.length_brand, new_item->Phone.brand, new_item->Phone.length_model, new_item->Phone.model, new_item->Phone.number, new_item->Phone.price);


        if(root == NULL)
            root = new_item;
        else
        {
            List *curr_item = root;
            while(curr_item->next != NULL)
                curr_item = curr_item->next;
            curr_item->next = new_item;
        }
    }
    double average_price = prices/i;
    List *curr_item = root;
    while(curr_item != NULL)
    {
        if(curr_item->Phone.price<average_price && !strcmp(curr_item->Phone.brand, "sony"))
        {
            fwrite(&curr_item->Phone.price, sizeof(double), 1, output);
            fwrite(&curr_item->Phone.number, sizeof(int), 1, output);
            fwrite(&curr_item->Phone.length_brand, sizeof(int), 1, output);
            fwrite(&curr_item->Phone.brand, 1, curr_item->Phone.length_brand, output);
            fwrite(&curr_item->Phone.length_model, sizeof(int), 1, output);
            fwrite(&curr_item->Phone.model, 1, curr_item->Phone.length_model, output);
        }
        curr_item = curr_item->next;
    }
}
