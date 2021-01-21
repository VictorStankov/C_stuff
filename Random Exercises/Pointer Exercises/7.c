#include <stdio.h>

int main()
{
    int n;
    printf("How many elements in the array: ");
    scanf("%d", &n);
    int arr[n], *pt = arr;

    for(int i=0; i<n; ++i)
        scanf("%d", &arr[i]);

    printf("\n\n");

    for(;pt<&arr[n];++pt)
        printf("%d\n", *pt);
    return 0;
}
