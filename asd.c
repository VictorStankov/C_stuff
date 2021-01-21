#include <stdio.h>

int main()
{
int a, j, k, i1, i2;
int x = 6, y = 5;
unsigned int l, m;
float f;

a = 1; j = 2; k = a += j *= 4; printf("\n1: %d  %d  %d", a, j, k);
a = 2; j = 5; k = 3;  printf("\n 2:  %d", ((a + 5)*j + 6)*k);
a = 8; j = 1; f = (a % 5) / (j + 5.0); printf("\n 3: %f", f);
f = 4; l = 1; k = -2; printf("\n 4 : %f", (float)l + (float)k + f);
a = 0;
if (a = 3) printf("\n 5: %d", a);

else printf("\n 6: %d", a);

for (a = 0, j = 5; (a += 2) < ++j;)
    {
        printf("\n 7: %d %d", a, j);
    }
a = 5; do {
printf("\n 8 : %d\n", a);
} while (a > 5);

for (a = j = 1; j++<3;){ a = j; }

printf("9: %d  %d\n", a, j);

i1 = i2 = 4; a = i1; k = i2; printf("11: %d %d  %d %d\n", a, k, x, y);

printf("12: %d %d %\n", i1, i2);



return 0;



}
