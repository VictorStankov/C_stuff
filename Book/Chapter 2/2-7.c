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
    /*Write a function invert(x,p,n) that returns x with the n bits that begin at
    position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

    unsigned temp = x;
    temp = (temp << 7-p & 0xff) >> 8-n <<p-n+1;
    x = x ^ temp;
    temp = ((~ temp) << 7-p & 0xff) >> 8-n << p-n+1;
    return x | temp;
}
