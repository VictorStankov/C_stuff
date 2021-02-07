#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main()
{
    char primary[]="a-z0-9", secondary[500];
    expand(primary, secondary);
    printf("%s\n%s\n", primary, secondary);
    return 0;
}

void expand(char s1[], char s2[])
{
    /* Write a function expand(s1,s2) that expands shorthand notations like a-z in
       the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
       case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
       that a leading or trailing - is taken literally.*/

    int start, end, t=0;
    for(int i=0; s1[i]; ++i)
    {
        if(s1[i+1] == '-' || s1[i-1] == '-')
            continue;
        if(s1[i] == '-')
        {
            if(i==0)
                start = 32;
            else start = s1[i-1];

            if(s1[i+1]=='\0')
                end = 255;
            else end = s1[i+1];

            for(int f=0; f<=end-start; ++f)
            {
                s2[t] = start+f;
                t++;
            }
        }
        else
        {
            s2[t] = s1[i];
            ++t;
        }
    }
    s2[t] = '\0';
}
