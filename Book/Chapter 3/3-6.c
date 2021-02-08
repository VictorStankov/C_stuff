#include <stdio.h>
#include <string.h>
#include <math.h>

void itoa(int n, char s[], int min_width);
void reverse(char s[]);

int main()
{
    char number[100];
    itoa(-123, number, 10);
    return 0;
}

void itoa(int n, char s[], int min_width)
{
    /* Write a version of itoa that accepts three arguments instead of two. The third
       argument is a minimum field width; the converted number must be padded with blanks on the
       left if necessary to make it wide enough.*/
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
    }
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    if(i<min_width)
        for(i; i<min_width; ++i)
            s[i] = ' ';
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
