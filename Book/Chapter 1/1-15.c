#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */

int main()
{
    /* Rewrite the temperature conversion program of Section 1.2 to use a function
       for conversion.*/
    int fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    while (fahr <= upper)
    {
        printf("%d\t%d\n", fahr, F_to_C(fahr));
        fahr = fahr + step;
    }
    return 0;
}

int F_to_C(int fahr)
{
    return 5 * (fahr-32) / 9;
}
