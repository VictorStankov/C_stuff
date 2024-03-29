 #include <stdio.h>
 #define LOWER 0
 #define UPPER 300
 #define STEP 10

 int main()
 {
     /* Modify the temperature conversion program to print the table in reverse order,
        that is, from 300 degrees to 0.*/
     int fahr;
     printf("Fahr\tCelsius\n");

     for (fahr = UPPER; fahr>=LOWER; fahr -= STEP)
     {
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0*(fahr-32)));
     }
     return 0;
 }
