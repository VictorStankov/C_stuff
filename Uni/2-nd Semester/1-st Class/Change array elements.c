#include <stdio.h>

void change_lower_elements(int arr[], int length, int n);

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	change_lower_elements(arr, 10, 5);
	for(int t=0; t < 10; ++t)
        printf("%d, ", arr[t]);
	return 0;
}

void change_lower_elements(int arr[], int length, int n)
{
    for(int i = 0; i<length; ++i)
        if(arr[i] < n)
            arr[i] = 0;
}
