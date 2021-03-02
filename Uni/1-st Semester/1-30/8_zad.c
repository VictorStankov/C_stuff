#include <stdio.h>
#include <math.h>

int main()
{
    double start_num, end_num;
    int i = 0, int_num, float_check = 0;
    end_num = 0;
    printf("Enter a number: ");
    scanf("%lf", &start_num);
    while(1)
    {
        if(start_num != round(start_num) && start_num / 10000 <= 1)
        {
            ++i;
            start_num *=10;
        }
        else break;
        float_check = 1;
    }

    int_num = start_num;
    while (int_num != 0)
    {
        end_num = end_num * 10;
        end_num = end_num + int_num%10;
        int_num = int_num/10;
    }
    if(float_check == 1)
        printf("\n%.2f", end_num/(pow(10, i)));
    else printf("\n%d", (int)end_num);
    return 0;
}
