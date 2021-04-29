#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100
#define PI 3.14159265

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print();
void duplicate();
void swap();

/* reverse Polish calculator */
int main()
{
    int type;
    double op2, v;
    char s[MAXOP], arr[2];
    extern int sp;

    printf("Welcome to this really shabby reverse Polish notation calculator.\n");
    printf("You have basic functions such as subtraction, multiplication etc.\n");
    printf("p - print the last two entries, s - swap last two entries\nd - duplicate the whole stack, c - clear the stack, v - last printed number\n");
    printf("\nEntering the \"!\" character will give you access to additional functions:\n!sin\t!cos\t!exp\t!pow\n");
    printf("-------------------------------------------------------\n\n");

    while ((type = getop(s)) != EOF)
    {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
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
            case '\n':
                printf("\t%.8g\n", v = pop());
                break;

                /* 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
                   the modulus (%) operator and provisions for negative numbers.*/
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;

                /* 4-4. Add the commands to print the top elements of the stack without popping, to
                   duplicate it, and to swap the top two elements. Add a command to clear the stack.*/
            case 'p':
                print();
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'c':
                sp = 0;
                break;

                /* 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
                   with single-letter names.) Add a variable for the most recently printed value.*/
            case 'v':
                push(v);
                break;

                /* 4-5. Add access to library functions like sin, exp, and pow.*/
            case '!':
                for(int i=0; i<3; ++i)
                    arr[i] = getop(s);
                if(!strcmp(arr, "sin"))
                {
                    double radian = (double)PI / 180;
                    push(sin(pop()*radian));
                }
                if(!strcmp(arr, "cos"))
                {
                    double radian = (double)PI / 180;
                    push(cos(pop()*radian));
                }
                if(!strcmp(arr, "exp"))
                    push(exp(pop()));
                if(!strcmp(arr, "pow"))
                {
                    double power = pop();
                    push(pow(pop(), power));
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                    break;
        }
    }
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

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (c == '-' || isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (!strcmp(s, "-"))
        return '-';
    return NUMBER;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void print()
{
    printf("%f | %f\n", val[sp-2], val[sp-1]);
}

void duplicate()
{
    int temp = sp;
    for(int i=0; i<temp; ++i)
        push(val[i]);
}

void swap()
{
    double temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}
