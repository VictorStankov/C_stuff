 #include <stdio.h>

 int main()
 {
     /* 1-6: Verify that the expression getchar() != EOF is 0 or 1.
        1-7: Write a program to print the value of EOF.*/
     int c = getchar();
     printf("\n%d", c != EOF);
     printf("\n\n%d", EOF);
     return 0;
 }
