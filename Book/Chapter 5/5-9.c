int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int month, day;
    printf("Days: %d\n", day_of_year(2000, 12, 31));
    month_day(2000, 366, &month, &day);
    printf("Month: %d\tDay: %d\n", month, day);
    return 0;
}


static char year_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[] = {year_days, leap_days};

/* 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.*/

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(daytab[leap][month] < day)
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(leap ? yearday > 366 : yearday > 365)
    {
        *pmonth = 0;
        *pday = 0;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}
