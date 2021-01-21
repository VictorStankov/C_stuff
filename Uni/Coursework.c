#include <stdio.h>

int main()
{
    int iterations = 0;
    float mean_errors = 0;

    while(1)
    {
        char text[5000];
        int t=-1;
        int punctuation[] = {'.', ',', '!', '?', ';'};
        int c, space_flag = 0, error_counter = 0, new_line_flag = 1, punctuation_flag = 0, capital_flag=1, length = (int)(sizeof(punctuation)/sizeof(punctuation[0]));

        ++iterations;
        printf("Waiting for text #%d\n\n", iterations);

        while((c = getchar()) != EOF)
        {
            if(space_flag && c == ' ')  // Checks for next whitespace
            {
                ++error_counter;
                printf("Space error");
                continue;
            }
            else
                space_flag=0;

            if(c == ' ')  // Checks for whitespace
                space_flag=1;

            ++t;
            if(new_line_flag && c!='\t'&& c!='\n')  // Checks for indentation after new paragraph
            {
                text[t] = '\t';
                ++t;
                ++error_counter;
                printf("New Line Error");
                new_line_flag=0;
            }
            else if(new_line_flag && c=='\t')
                new_line_flag=0;

            if(punctuation_flag && c!=' ' && c!='\n')
            {
                text[t] = ' ';
                ++t;
                ++error_counter;
                printf("Punctuation Error");
                punctuation_flag = 0;
            }
            else if(punctuation_flag && (c==' ' || c=='\n'))
                punctuation_flag = 0;

            if(c=='(' && text[t-1]!=' ')
            {
                ++error_counter;
                text[t] = ' ';
                printf("Muy mal");
                ++t;
            }

            if(c=='.' || c=='?' || c=='!')
                capital_flag = 1;

            if(capital_flag && c>='a' && c<='z')
            {
                text[t] = c - ('a' - 'A');
                ++error_counter;
                capital_flag = 0;
                continue;
            }
            else if(capital_flag && c>='A' && c<='z')
                capital_flag = 0;

            for(int i = 0; i< length; ++i)
            {
                if(c==punctuation[i])
                {
                    punctuation_flag=1;
                    break;
                }
            }

            if(c=='\n')  // Check for new paragraph
                new_line_flag = 1;

            if(c>=32 && c <= 127){  // Filters out non-standard symbols
                text[t]=c;
                putchar(text[t]);}
            else
            {
                ++error_counter;
                continue;
            }
            text[t+1] = '\0';
            //printf("\n%d", t);
        }
        text[t+1] = '\0';
        printf("\n");
        for(int i=0; i<=40; ++i)
            printf("-");
        if(mean_errors==0)
            printf("\nCorrected text:\n\n%s\n\nNumber of mistakes:\t%d\nPercentage error:\t%.2f%%\n", text, error_counter, (float)error_counter*100);
        else
            printf("\nCorrected text:\n\n%s\n\nNumber of mistakes:\t%d\nPercentage error:\t%.2f%%\n", text, error_counter, error_counter/mean_errors*100);
        for(int i=0; i<=40; ++i)
            printf("-");
        printf("\n\n");
        mean_errors = (mean_errors*(iterations-1) + error_counter)/iterations;
    }
    return 0;
}
