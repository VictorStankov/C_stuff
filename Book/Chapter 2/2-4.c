#include <stdio.h>
#include <ctype.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char sentence[] = "Hello, I am your neighbour.";
    char letters_to_remove[] = "hel";
    squeeze(sentence, letters_to_remove);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    /*Write an alternative version of squeeze(s1,s2) that deletes each character in
    s1 that matches any character in the string s2.*/

    int i, j, letter_flag = 0;
    for(i = j = 0; s1[i]; ++i)
    {
        for(int t = 0; s2[t]; ++t)
        {
            if(tolower(s2[t]) == tolower(s1[i]))
                letter_flag = 1;
        }
        if(!letter_flag)
            s1[j++] = s1[i];
        else letter_flag = 0;
    }
    s1[j] = '\0';
    printf("%s", s1);
}
