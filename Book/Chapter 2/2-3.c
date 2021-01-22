#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char hex[] = "0x6D66614";
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
    printf("%u", sum);
    return 0;
}
