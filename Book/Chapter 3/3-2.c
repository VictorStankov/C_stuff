#include <stdio.h>
#define MAX 100

void escape(char t[], char s[]);

int main()
{
    char primary[100] = "I'm a\nstring", secondary[100];
    escape(primary, secondary);
    printf("%s\n------\n%s\n", primary, secondary);
    return 0;
}

void escape(char t[], char s[])
{
    /* Write a function escape(s,t) that converts characters like newline and tab
       into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
       a function for the other direction as well, converting escape sequences into the real characters.*/
    int i=0, f=0;
    for(i, f; t[i]; ++i)
    {
        switch (t[i])
        {
        case '\n':
            s[f] = '\\';
            s[++f] = 'n';
            ++f;
            break;
        case '\t':
            s[f] = '\\';
            s[++f] = 't';
            ++f;
            break;
        default:
            s[f] = t[i];
            ++f;
            break;
        }
    }
    s[f] = '\0';
}
