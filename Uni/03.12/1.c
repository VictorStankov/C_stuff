#include <stdio.h>
#define N 7

int main()
{
    int arr[N], sum = 0;
    for(int i = 0; i<N; ++i)
        scanf("%d", &arr[i]);
    for(int i = 0; i<N; ++i)
        sum += arr[i];

    printf("\n%d\n", sum);
    return 0;
}
