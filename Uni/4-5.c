#include <stdio.h>
#include <string.h>

int main()
{
    char arr[20]= "12345";
    int number;
    for(int i = 0; i<strlen(arr); ++i)
    {
        number += (arr[i] - '0') * pow(10, (strlen(arr)-i-1));
    }
    printf("%d", number);
    return 0;
}
