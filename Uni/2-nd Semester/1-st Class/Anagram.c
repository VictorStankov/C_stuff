#include <stdio.h>
#include <string.h>

int check_anagram(char s1[], char s2[]);

int main()
{
	printf("%d\n", check_anagram("asddadsd", "dssdaadd"));
	return 0;
}

int check_anagram(char s1[], char s2[])
{
    char temp[strlen(s2)];
    strcpy(temp, s2);
    for(int i=0; s1[i]; ++i)
    {
        if((strchr(temp, s1[i])) != NULL)
        {
            *strchr(temp, s1[i]) = 1;
            continue;
        }
        else return 0;
    }
    for(int t=0; temp[t]; ++t)
        if(temp[t] != 1)
            return 0;
    return 1;
}
