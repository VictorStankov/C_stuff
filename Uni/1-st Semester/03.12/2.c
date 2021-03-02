#include <stdio.h>
#define N 7

int main()
{
    int arr[N], largest = 0;
    for(int i = 0; i<N; ++i)
        scanf("%d", &arr[i]);
    for(int i = 0; i<N; ++i)
        if(arr[i]>largest)
            largest = arr[i];

    printf("\n%d\n", largest);
    return 0;
}
