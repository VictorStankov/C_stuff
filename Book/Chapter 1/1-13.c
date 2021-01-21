#include <stdio.h>

int main()
{
    int c, iteration, loop;
    int length = 0;
    int word[10];
    int number;

    for(loop = 0; loop < 10; loop++)
        word[loop] = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            word[iteration] = length;
            length = 0;
            iteration = 0;
            for(loop = 0; loop < 10; loop++)
                {
                    if(word[loop] != 0)
                    {
                        printf("%2d: ", loop + 1);
                        for(number = word[loop]; number > 0; --number)
                        printf("#");
                        printf("\n");
                    }

                }
            for(loop = 0; loop < 10; loop++)
                word[loop] = 0;
            printf("\n");
        }

        else if(c != ' ' && c != '\t')
            ++length;
        else
        {
            word[iteration] = length;
            length = 0;
            ++iteration;
        }
    }
}
