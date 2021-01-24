#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned c = 0x9d;
    //printf("%d\n", rightrot(c, 3));
    printf("%d\n", rightrot(c, 3));
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int digit = 0;
    for(int i=0; i<n; ++i)
        digit += pow(2, i);
    unsigned temp = digit;
    temp = (x & temp) << 8-n;
    return (x >> n) | temp;
}
