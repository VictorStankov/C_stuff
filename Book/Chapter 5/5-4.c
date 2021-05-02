#include <stdio.h>

int strend(char* s, char* t);

int main()
{
    double a = 5;
    printf("%d\n, %lf\n", strend("asddsa", "dsa"), a);
    return 0;
}

/* 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
   end of the string s, and zero otherwise.*/
int strend(char* s, char* t)
{
    char* temp_s = s,* temp_t = t;
    int s_len = 0, t_len = 0;

    while(*temp_t++)
        t_len++;

    while(*temp_s++)
        s_len++;

    while(s_len-- != t_len)
        s++;

    for(int i = 0; i < t_len; ++i)
        if(*s++ != *t++)
            return 0;

    return 1;
}