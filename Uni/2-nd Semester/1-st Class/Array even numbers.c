#include <stdio.h>

void double_evens(int s[], int length);

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = 8;
	double_evens(arr, length);
	for(int t=0; t < length; ++t)
        printf("%d, ", arr[t]);
	return 0;
}

void double_evens(int s[], int length)
{
    for(int i=0; i<length; ++i)
        if(s[i] % 2 == 0)
            s[i] *= 2;
}
