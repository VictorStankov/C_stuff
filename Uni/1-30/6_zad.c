#include <stdio.h>

int main()
{
    int chislo_0, chislo_1;
    scanf("%d %d", &chislo_0, &chislo_1);
    for(int i = chislo_0 * chislo_1; ; --i)
    {
        if(chislo_0 % i == 0 && chislo_1 % i == 0)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
