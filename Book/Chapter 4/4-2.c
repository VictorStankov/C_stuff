#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
    printf("%f\n", atof("123.123e-3"));
	return 0;
}

double atof(char s[])
{
    /* Extend atof to handle scientific notation of the form
       123.45e-6
       where a floating-point number may be followed by e or E and an optionally signed exponent.*/

    double val, power, degree = 1;
    int i, sign, sci_sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;

    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if(s[i] == '.')
        i++;

    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if(s[i] == 'e' || s[i] == 'E')
    {
        sci_sign = (s[++i] == '-') ? -1 : 1;
        for(int t=0; t < (s[i+1] - '0'); ++t)
            degree = (sci_sign == -1) ? degree / 10 : degree * 10;
        power /= degree;
    }
    return sign * val / power;
}
