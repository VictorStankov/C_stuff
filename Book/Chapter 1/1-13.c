#include <stdio.h>

int main()
{
    /* Write a program to print a histogram of the lengths of words in its input. It is
       easy to draw the histogram with the bars horizontal; a vertical orientation is more
       challenging.*/
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
    return 0;
}
