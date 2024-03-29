#include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
    printf("%d\n", strindex("fdsaabcafdsabcabcfdsa", "fdsa"));
    return 0;
}

int strindex(char s[], char t[])
{
    int index = 0;
    /* Write the function strindex(s,t) which returns the position of the rightmost
       occurrence of t in s, or -1 if there is none.*/
    for(int i=0; s[i]; ++i)
    {
        for(int f=0, g=i;; ++f, ++g)
        {
            if(t[f]==0)
                index = i;
            else if(t[f]==s[g])
                continue;
            else break;
        }
    }
    if(index)
        return index;
    return -1;
}
