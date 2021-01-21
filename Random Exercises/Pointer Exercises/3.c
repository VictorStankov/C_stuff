#include <stdio.h>

int main()
{
    int m = 300, *pt_0 = &m;
    double fx = 300.600006, *pt_1 = &fx;
    char cht[] = {"z"}, *pt_2 = cht;

    printf("Using & operator:\n-----------------\n");
    printf("address of m = %x\naddress of fx = %x\naddress of cht = %x\n\n", &m, &fx, cht);
    printf("Using & and * operators:\n------------------------\n");
    printf("value at address of m = %d\nvalue at address of fx = %f\nvalue at address of cht = %s\n\n", *&m, *&fx, *&cht);
    printf("Using only pointer variable:\n----------------------------\n");
    printf("address of m = %x\naddress of fx = %x\naddress of cht = %x\n\n", pt_0, pt_1, pt_2);
    printf("Using only pointer operator:\n----------------------------\n");
    printf("value at address of m = %d\nvalue at address of fx = %f\nvalue at address of cht = %c\n\n", *pt_0, *pt_1, *pt_2);
    return 0;
}
