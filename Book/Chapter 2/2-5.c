#include <stdio.h>
#include <ctype.h>

int any(char s1[], char s2[]);

int main()
{
    char sentence[] = "Hello, I am your neighbour.";
    char letters_to_check[] = "hel";
    char a = any(sentence, letters_to_check);
    printf("%d\n", a);
    return 0;
}

int any(char s1[], char s2[])
{
    for(int i = 0; s1[i]; ++i)
    {
        for(int t = 0; s2[t]; ++t)
        {
            if(tolower(s1[i]) == tolower(s2[t]))
                return i;
        }
    }
    return -1;
}
