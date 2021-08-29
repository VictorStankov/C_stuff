#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

/* 7-4. Write a private version of scanf analogous to minprintf from the previous
 * section.*/

int main()
{
    int i;
    char j[10];
    minscanf("%d %s", &i, &j);
    printf("%d %s", i, j);
    return 0;
}

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int *ival;
    double *dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            continue;
        }
        switch (*++p)
        {
            case 'd':
                ival = va_arg(ap, int*);
                scanf("%d", ival);
                break;

            case 'f':
                dval = va_arg(ap, double*);
                scanf("%f", dval);
                break;

            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;

            case 'x':
                ival = va_arg(ap, int*);
                scanf("%x", ival);
                break;

            case 'o':
                ival = va_arg(ap, int*);
                scanf("%o", ival);
                break;
            
            case 'c':
                sval = va_arg(ap, char*);
                scanf("%c", sval);
                break;

            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}