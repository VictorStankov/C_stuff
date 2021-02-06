#include <stdio.h>

int main()
{
    int input_day, num_days, output_day;

    printf("Enter the current day: ");
    scanf("%d", &input_day);

    printf("Enter number of days: ");
    scanf("%d", &num_days);

    output_day = input_day + num_days;
    if(output_day < 7)
        printf("\n%d", output_day);
    else
        printf("\n%d", output_day%7);

    return 0;
}
