#include <stdio.h>
#include <stdlib.h>
/* 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
   (Block structure will help.) */
#define SWAP(t,x,y) t temp = x; x = y; y = temp;

int main()
{
    int x=0, y=15;

    printf("%d %d\n", x, y);
    SWAP(int, x, y);
    printf("%d %d\n", x, y);
    
    return 0;
}