#include <stdio.h>
#define MAX 100

char escape(char t[], char s[]);

int main()
{
    char primary[100] = "I'm a\nstring", secondary[100];
    escape(primary, secondary);
    printf("%s\t|\t%s\n", primary, secondary);
    return 0;
}

char escape(char t[], char s[])
{
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
    return s;
}
