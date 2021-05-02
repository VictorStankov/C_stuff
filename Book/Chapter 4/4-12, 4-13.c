#include <stdio.h>
#include <string.h>

int main()
{
    char s[10];
    itoa(s, -12345);
    puts(s);
    
    reverse(s);
    puts(s);

    return 0;
}

/* 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
   an integer into a string by calling a recursive routine.*/
void itoa(char s[], int num)
{
    static int i = 0;
    static int flag = 0;
    if(num<0)
    {
        flag = 1;
        num *= -1;
    }
    s[i++] = num % 10 + '0';
    if(num / 10)
        itoa(s, num/10);
    else
    {
        if(flag)
            s[i++] = '-';
        s[i] = '\0';
    }
}

/* 4-13. Write a recursive version of the function reverse(s), which reverses the
   string s in place.*/
void reverse(char s[])
{
    static int i = 0;
    int length = strlen(s) - 1, temp;
    temp = s[i];
    s[i] = s[length - i];
    s[length - i] = temp;
    i++;
    if(i <= length/2)
        reverse(s);
}
