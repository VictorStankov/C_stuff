#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int main()
{
    printf("\t\t\tMin\t\tMax\n");
    printf("Char:\n\tSigned:\t\t%d\t\t%d\n\tUnsigned:\t%d\t\t%d\n\n", SCHAR_MIN, SCHAR_MAX, 0, UCHAR_MAX);
    printf("Short:\n\tSigned:\t\t%d\t\t%d\n\tUnsigned:\t%d\t\t%d\n\n", SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
    printf("Int:\n\tSigned:\t\t%d\t%d\n\tUnsigned:\t%d\t\t%u\n\n", INT_MIN, INT_MAX, 0, UINT_MAX);
    printf("Long:\n\tSigned:\t\t%d\t%d\n\tUnsigned:\t%d\t\t%u\n\n", LONG_MIN, LONG_MAX, 0, ULONG_MAX);

    int c = 0;
    while(1)
    {
        if(c != abs(c))
        {
            printf("%d\t", c);
            printf("%d", abs(c + 1));
            break;
        }
        ++c;
    }
}
