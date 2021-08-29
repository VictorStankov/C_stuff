#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

/* 7-3. Revise minprintf to handle more of the other facilities of printf.*/

int main()
{
    minprintf("%x %c", 123, 'G');
    return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;

            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;

            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;

            case 'x':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;

            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            
            case 'c':
                ival = va_arg(ap, int);
                printf("%c", ival);
                break;

            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}