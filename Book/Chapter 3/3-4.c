#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    char number[100];
    int n = -2147483648;
    itoa(n, number);
    return 0;
}

void itoa(int n, char s[])
{
    /* In a two's complement number representation, our version of itoa does not
    handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
    not. Modify it to print that value correctly, regardless of the machine on which it runs.*/

    /* Answer: the absolute values of negative values that a data type can hold are always with 1 more
    than the positive ones. That's why without any code to check for that, the script can't convert it
    to a positive number*/

    int i, sign, negative_flag = 0;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    if(n < 0)  // Modified part
    {
        negative_flag = 1;
        n += 1;
        n = -n;
    }
    do {
        if(negative_flag)  // Modified part
        {
            s[i++] = abs(n % 10) + '1';
            negative_flag = 0;
        }
        else
            s[i++] = abs(n % 10) + '0';
        s[i+1] = '\0';
    }
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    printf("%s\n", s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
