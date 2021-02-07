#include <stdio.h>
#include <string.h>

char itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char number[100];
    itob(12525, number, 16);
    return 0;
}

char itob(int n, char s[], int b)
{
    /* Write the function itob(n,s,b) that converts the integer n into a base b
       character representation in the string s. In particular, itob(n,s,16) formats s as a
       hexadecimal integer in s. */

    int i = 0, temp;
    do
    {
        temp = n % b;
        if(temp >= 0 && temp <= 9)
            temp += '0';
        else temp += 'A' - 10;
        s[i++] = temp;
    }
    while((n /= b) != 0);
    reverse(s);
    puts(s);
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
