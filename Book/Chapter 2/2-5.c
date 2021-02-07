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
    /* Write the function any(s1,s2), which returns the first location in a string s1
       where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
       (The standard library function strpbrk does the same job but returns a pointer to the
       location.)*/

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
