#include <stdio.h>
#include <math.h>

int main()
{
    int x_0, x_1, y_0, y_1, x_distance, y_distance;
    printf("Enter the coordinates of the first point: ");
    scanf("%d%d", &x_0, &y_0);
    printf("Enter the coordinates of the second point: ");
    scanf("%d%d", &x_1, &y_1);
    x_distance = abs(x_0 - x_1);
    y_distance = abs(y_0 - y_1);
    printf("\n%.2f", pow((pow(x_distance, 2) + pow(y_distance, 2)), 0.5));
    return 0;
}
