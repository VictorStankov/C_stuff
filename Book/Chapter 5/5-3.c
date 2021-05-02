#include <stdio.h>

void strcat(char* s, char* t);

int main()
{
    char s[] = "Hello", t[] = "world";
    strcat(s, t);
    printf("%s\n", s);
    return 0;
}

/* 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s,t) copies the string t to the end of s.*/
void strcat(char* s, char* t)
{
    while (*++s != '\0') /* find end of s */
        ;
    while ((*s++ = *t++) != '\0') /* copy t */
        ;
}
