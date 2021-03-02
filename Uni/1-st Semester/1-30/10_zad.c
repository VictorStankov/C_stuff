#include <stdio.h>

int main()
{
    int day, month, days;
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the month: ");
    scanf("%d", &month);
    for(int i = month; i >0; --i)
    {
        if(i == month)
            days += day;
        else
        {
            if(i<=7 && i%2==1 || i>=8 && i%2==0)
                days += 31;
            else if(i == 2)
                days += 28;
            else days += 30;
        }
    }
    printf("\nWeek number: %d", days/7 + 1);
    return 0;
}
