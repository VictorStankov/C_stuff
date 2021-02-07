 #include <stdio.h>

 int main()
 {
     /* 1-3: Modify the temperature conversion program to print a heading above the table.
        1-4: Write a program to print the corresponding Celsius to Fahrenheit table.*/
     float lower, upper, step, fahr;
     lower = 0;
     upper = 300;
     step = 10;
     printf("Celsius\t  Fahr\n");

     while(lower<=upper)
     {
         fahr = (9.0 / 5.0 * lower) + 32;
         printf("%3.0f\t%6.0f\n", lower, fahr);
         lower += step;
     }
     return 0;
 }
