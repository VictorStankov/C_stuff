#include <stdio.h>

struct Fruit
{
    char name[15];
    char countryOfOrigin[15];
    char taste[15];
};

int main()
{
	struct Fruit Fruit_0;
	printf("Name of fruit: ");
	scanf("%s", Fruit_0.name);
	printf("Country of Origin: ");
	scanf("%s", Fruit_0.countryOfOrigin);
	printf("Taste: ");
	scanf("%s", Fruit_0.taste);

	printf("-------------------\n");

    printf("Name of fruit: %s\n", Fruit_0.name);
	printf("Country of Origin: %s\n", Fruit_0.countryOfOrigin);
	printf("Taste: %s\n", Fruit_0.taste);
	return 0;
}
