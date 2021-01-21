#include <stdio.h>

int main()
{
    long long number;
    scanf("%lld", &number);
    while (number != 0)
    {
        if((number%10) != 0 && number%10 != ((number%10)/2)*2)
            printf("%d", number%10);
        number = number/10;
    }
    return 0;
}
