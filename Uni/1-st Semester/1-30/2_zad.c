#include <stdio.h>
#include <stdlib.h>

int main()
{
    char days[][12]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int year, base_year;
    base_year = 2013;
    int day = 6;
    printf("Enter a year: ");
    scanf("%d", &year);
    if(year > base_year)
        for(base_year += 1; base_year<=year; ++base_year)
        {
            if(base_year%4==0)
                day += 2;

            else ++day;

            if(day >= 7)
                day -= 7;
        }
    else
        for(base_year; base_year>year; --base_year)
        {
            if(base_year%4==0)
                day -= 2;

            else --day;

            if(day < 0)
                day += 7;
        }

    printf("\n%s", days[day]);
    return 0;
}
