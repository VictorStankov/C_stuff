#include <stdio.h>
#include <string.h>

int getLine(char *s, int lim);
int atoi(char *s);
void itoa(char *s, int num);
void reverse(char *s);

int main()
{
    char s[20];
    getLine(s, 10);
    puts(s);
    printf("%d\n", atoi(s));
    itoa(s, 13543);
    reverse(s);
    puts(s);
    return 0;
}

/* 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
   instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
   and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
   (Chapter 4).*/

/* getline: read a line into s, return length */
int getLine(char *s, int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        *s++ = c;
    if (c == '\n') 
        *s++ = c;
    *s = '\0';
    return i;
}

/* atoi: convert s to integer */
int atoi(char *s)
{
    int i, n;
    n = 0;
    for (i = 0; *s >= '0' && *s <= '9'; ++i)
        n = 10 * n + (*s++ - '0');
    return n;
}

/* itoa: convert n to characters in s */
void itoa(char *s, int num)
{
    //static int i = 0;
    static int flag = 0;
    if(num<0)
    {
        flag = 1;
        num *= -1;
    }
    *s++ = num % 10 + '0';
    if(num / 10)
        itoa(s, num/10);
    else
    {
        if(flag)
            *s++ = '-';
        *s = '\0';
    }
    // reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
    static int i = 0;
    int length = strlen(s) - 1, temp;
    
    temp = *(s + i);
    *(s + i) = *(s + length - i);
    *(s + length - i) = temp;
    i++;
    if(i <= length/2)
        reverse(s);
}
