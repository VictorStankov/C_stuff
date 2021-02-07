#include <stdio.h>

int input(char sentence[]);
void remove_blanks(char sentence[], int len, char output_sentence[]);

int main()
{
    /* Write a program to remove trailing blanks and tabs from each line of input,
       and to delete entirely blank lines.*/
    char sentence[100];
    char output_sentence[100];
    int i = input(sentence);
    remove_blanks(sentence, i, output_sentence);
    printf("%ss", output_sentence);
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

void remove_blanks(char sentence[], int len, char output_sentence[])
{
    for(len; ; len--)
    {
        if(sentence[len] != ' ' && sentence[len] != '\0' && sentence[len] != '\n' && sentence[len] !='\t')
        {
            for(int i = 0; i<=len; i++)
            {
                output_sentence[i] = sentence[i];
            }
            output_sentence[len+1] = '\0';
            break;
        }
    }
}
