#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned c = 0x66;
    printf("%d\n", invert(c, 6, 3));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned temp = x;
    temp = (temp << 7-p & 0xff) >> 8-n <<p-n+1;
    x = x ^ temp;
    temp = ((~ temp) << 7-p & 0xff) >> 8-n << p-n+1;
    return x | temp;
}
