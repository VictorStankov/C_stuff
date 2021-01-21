 #include <stdio.h>


 int main()
 {
 float lower, upper, step, fahr;
 lower = 0;
 upper = 300;
 step = 10;
 printf("Celsius\t  Fahr\n");

 while(lower<=upper)
 {
     fahr = (9.0 / 5.0 * lower) + 32;
     printf("%3.0f\t%6.0f\n",lower,fahr);
     lower += step;
 }
 }
