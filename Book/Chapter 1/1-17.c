#include <stdio.h>
int input(char sentence[]);

int main()
{
    /* Write a program to print all input lines that are longer than 80 characters.*/
    char sentence[5000];
    int i = input(sentence);
    if(i > 80)
        printf("%s", sentence);
    return 0;
}

int input(char sentence[])
{
    int c;
    int i = 0;

    while((c = getchar()) != EOF)
    {
        sentence[i] = c;
        ++i;
    }
    return i;
}
