#include <stdio.h>
#define N 7

int main()
{
    int arr[N] = {24, 89, -123, 45, 196, 1204, 0, 112};
    for(int i = 0; i<N; ++i)
    {
        printf("\n%4d:\t", arr[i]);
        for(int t = 2; t<arr[i]; ++t)
            if(arr[i]%t==0)
                printf("%d, ", t);
    }
    printf("\n");
    return 0;
}
