#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char hex[]);

int main()
{
    char hex[] = "0x6D66614";
    printf("%d\n", htoi(hex));
    return 0;
}

int htoi(char hex[])
{
    /* Write a function htoi(s), which converts a string of hexadecimal digits
       (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
       through 9, a through f, and A through F.*/

    int length = strlen(hex), i = 0;
    if(hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
    {
        i = 2;
    }
    unsigned long long sum = 0;
    for(i; i<length; ++i)
    {
        if(hex[i]>= '0' && hex[i]<='9')
            sum+= (hex[i] - '0')*(powl(16, length-i-1));
        if(hex[i]>='A' && hex[i]<='F')
            sum += (hex[i] - 55)*(powl(16, length-i-1));
        if(hex[i]>='a' && hex[i]<='f')
            sum += (hex[i] - 87)*(powl(16, length-i-1));
    }
    return sum;
}
