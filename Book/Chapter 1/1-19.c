#include <stdio.h>
#include <stdlib.h>

int input(char sentence[]);
void reverse_order(char sentence[], char output_sentence[], int len);

int main()
{
    char sentence[100];
    char output_sentence[100];
    int i = input(sentence);
    reverse_order(sentence, output_sentence, i);
    printf("%s", output_sentence);
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

void reverse_order(char sentence[], char output_sentence[], int len)
{
    --len;
    printf("Length: %d\n", len);
    for(int i = 0; i <= len; ++i)
    {
        printf("%d\n", abs(i - len));
        output_sentence[abs(i - len)] = sentence[i];
    }
    output_sentence[len + 1] = '\0';
}
