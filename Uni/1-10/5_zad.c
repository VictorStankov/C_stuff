#include <stdio.h>

int main()
{
    int chislo_0, chislo_1;
    scanf("%d %d", &chislo_0, &chislo_1);
    for(int i = chislo_0; i <= chislo_0 * chislo_1; i++)
    {
        if(i % chislo_0 == 0 && i % chislo_1 == 0)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
