#include <stdio.h>
#include <time.h>

int bitcount(unsigned x);
int bitcount_book(unsigned x);

int main()
{
    clock_t time_taken;
    unsigned c = 0xf0;

    time_taken = clock();
    for(int i = 0; i<1000000;++i)
        bitcount(c);
    time_taken = clock() - time_taken;
    printf("My bitcount took %lu clocks (%lu seconds)\n", (unsigned long) time_taken, (unsigned long) time_taken / CLOCKS_PER_SEC);

    time_taken = clock();
    for(int i = 0; i<1000000;++i)
        bitcount_book(c);
    time_taken = clock() - time_taken;
    printf("Book bitcount took %lu clocks (%lu seconds)\n", (unsigned long) time_taken, (unsigned long) time_taken / CLOCKS_PER_SEC);
    return 0;
}

int bitcount(unsigned x)
{
    /* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
       in x. Explain why. Use this observation to write a faster version of bitcount.*/
    int b;
    for (b = 0; x != 0; (x &=(x-1)))
            b++;
    return b;
}

int bitcount_book(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
