#include <stdio.h>
#define SIZE 15

struct Fruit
{
    char name[15];
    char countryOfOrigin[15];
    char taste[15];
};

int main()
{
	struct Fruit fruits[SIZE];
	for(int i=0; i<SIZE; ++i)
    {
        for(int t=0; t<=i; ++t)
        {
            fruits[i].name[t] = t + 65;
        }
        fruits[i].name[i+1] = '\0';
    }
    for(int i=SIZE-1; i>=0; --i)
    {
        printf("%2d. %s\n", i, fruits[i].name);
    }
	return 0;
}
