#include <stdio.h>

int check_count(char test[], int symbol, int len);

int main()
{
    /* Write a program to check a C program for rudimentary syntax errors like
       parentheses, brackets and braces. Don't forget about quotes, both single and
       double, escape sequences, and comments. (This program is hard if you do it in full
       generality.)*/
    int c, braces, parenth, brackets, quotes, i;
    char test[1000];
    braces, parenth, brackets, quotes, i = 0;

    while((c = getchar()) != EOF)
    {
        if(c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}' || c=='"' || c=='\'')
        {
            test[i] = c;
            ++i;
        }

    }
    test[++i] = '\0';
    if(check_count(test, '(', i) != check_count(test, ')', i))
        printf("\nUnmatched parentheses\n");
    if(check_count(test, '[', i) != check_count(test, ']', i))
        printf("\nUnmatched braces\n");
    if(check_count(test, '{', i) != check_count(test, '}', i))
        printf("\nUnmatched brackets\n");
    if(check_count(test, '"', i) % 2 != 0)
        printf("\nUnmatched double quotes\n");
    if(check_count(test, '\'', i) % 2 != 0)
        printf("\nUnmatched single quotes\n");
    return 0;
}

int check_count(char test[], int symbol, int len)
{
    int iter = 0;
    for(int i = 0; i<= len; ++i)
    {
        if(test[i] == symbol)
        {
            ++iter;
        }
    }
    return iter;
}
