#include <stdio.h>

int main()
{
    int m = 10, n, o, *z = &m;
    printf("Here is m=10, n and o are two integer variable and *z is an integer\n");
    printf("z stores the address of m = %x\n", z);
    printf("*z stores the value of m = %d\n", *z);
    printf("&m is the address of m = %x\n", &m);
    printf("&n stores the address of n = %x\n", &n);
    printf("&o  stores the address of o = %x\n", &o);
    printf("&z stores the address of z = %x\n", &z);
    return 0;
}
