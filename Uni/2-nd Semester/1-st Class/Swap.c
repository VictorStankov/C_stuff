#include <stdio.h>

void swap(int* a, int* b);

int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	printf("%d\t%d", a, b);
	return 0;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
