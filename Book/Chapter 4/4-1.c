#include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
    printf("%d\n", strindex("abcabcabcfdsa", "fdsa"));
    return 0;
}

int strindex(char s[], char t[])
{
    /* Write the function strindex(s,t) which returns the position of the rightmost
       occurrence of t in s, or -1 if there is none.*/
    for(int i=0; s[i]; ++i)
    {
        for(int f=0, g=i;; ++f, ++g)
        {
            if(t[f]==0)
                return i;
            else if(t[f]==s[g])
                continue;
            else break;
        }
    }
    return -1;
}
