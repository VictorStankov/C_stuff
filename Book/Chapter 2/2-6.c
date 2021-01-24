#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned c = 0x66;
    printf("%d\n", setbits(c, 6, 3, 0x25));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
    position p set to the rightmost n bits of y, leaving the other bits unchanged.*/

    unsigned temp = x;
    temp = (temp << (7-p) & 0xff) >> 8-n <<p-n+1;
    y = (y << 8-n & 0xff) >> 10-p-n;
    return (x ^ temp) | y;
}
