 #include <stdio.h>

int main()
{
    float lower, upper, step, celsius;
    lower = 0;
    upper = 300;
    step = 10;
    printf("Fahr\tCelsius\n");

    while(lower<=upper)
    {
        celsius = 5.0/9.0*(lower - 32);
        printf("%3.0f\t%6.1f\n",lower,celsius);
        lower += step;
    }
}
