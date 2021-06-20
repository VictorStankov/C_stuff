#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXVAL 100

void push(double f);
double pop(void);

/* 5-10. Write the program expr, which evaluates a reverse Polish expression from the
   command line, where each operator or operand is a separate argument.*/

int main(int argc, char *argv[])
{
    double op2;
    int c;
    while(--argc > 0 && ++argv)
    {
        c = *argv[0];
        if(isdigit(c))
            push(atof(*argv));

        else
        {
            switch (c)
            {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
            }
        }
    }

    printf("%lf\n", pop());
    return 0;
}

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
