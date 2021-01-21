#include <stdio.h>

int main()
{
    int m = 29, *ab = &m;
    printf("Address of m: %x\nValue of m: %d\n\n", &m, m);
    printf("Now ab is assigned with the address of m.\n");
    printf("Address of pointer ab: %x\nContent of pointer ab: %d\n\n", ab, *ab);
    m = 34;
    printf("The value of m assigned to 34 now.\n");
    printf("Address of pointer ab: %x\nContent of pointer ab: %d\n\n", ab, *ab);
    *ab = 7;
    printf("The pointer variable ab is assigned with the value 7 now.\n");
    printf("Address of m: %x\nValue of m: %d\n\n", &m, m);
    return 0;
}
