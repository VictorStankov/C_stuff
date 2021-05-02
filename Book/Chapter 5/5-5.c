void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

int main()
{
    char s[20] = "123", t[] = "asddsad";
    strncat(s, t, 10);
    puts(s);
    strncpy(s, t, 3);
    puts(s);
    printf("%d | %d\n", strncmp(s, t, 5), strncmp("1234", "1235", 4));
    return 0;
}

/* 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
   operate on at most the first n characters of their argument strings. For example,
   strncpy(s,t,n) copies at most n characters of t to s.*/

void strncpy(char *s, char *t, int n)
{
    for(int i = 0; i < n && *t; ++i)
    {
        if(*t)
            *s++ = *t++;
        else
            *s++ = '\0';
    }
    *s = '\0';
}

void strncat(char *s, char *t, int n)
{
    while(*s++ != '\0')
        ;
    s--;
    for(int i = 0; i < n; ++i)
    {
        if(*t)
            *s++ = *t++;
        else
            *s++ = '\0';
    }
    *s = '\0';
}

int strncmp(char *s, char *t, int n)
{
    int i;
    while(n--)
    {
        if(i = *s++ - *t++)
            return i;
    }
    return 0;
}
