#include <stdio.h>
#include <math.h>

float distance(int x_point, int y_point);
int area();
int x_0, x_1, x_2, x_R, y_0, y_1, y_2, y_R, R;

int main()
{
    extern int x_0, x_1, x_2, x_R, y_0, y_1, y_2, y_R, R;
    printf("Enter the coordinates of the triangle:\n");
    scanf("%d%d%d%d%d%d", &x_0, &y_0, &x_1, &y_1, &x_2, &y_2);
    printf("Enter the coordinates of the circle:\n");
    scanf("%d%d", &x_R, &y_R);
    printf("Enter the radius of the circle:\n");
    scanf("%d", &R);
    if((R < distance(x_0, y_0) && R < distance(x_1, y_1) && R < distance(x_2, y_2)) || (R > distance(x_0, y_0) && R > distance(x_1, y_1) && R > distance(x_2, y_2)))
        printf("\nne se presichat");
    else if(R == distance(x_0, y_0) && R == distance(x_1, y_1) && R == distance(x_2, y_2))
        printf("\nokryjnostta e opisana");
    area();

    return 0;
}

float distance(int x_point, int y_point)
{
    int x_distance, y_distance;
    extern int x_R, y_R;
    x_distance = abs(x_point - x_R);
    y_distance = abs(y_point - y_R);
    return pow((pow(x_distance, 2) + pow(y_distance, 2)), 0.5);
}

int area()
{
    extern int x_0, x_1, x_2, y_0, y_1, y_2, R;
    float distance_0, distance_1, distance_2, perimeter, area;
    distance_0=pow((pow(abs(x_0 - x_1), 2) + pow(abs(y_0 - y_1), 2)), 0.5);
    distance_1=pow((pow(abs(x_1 - x_2), 2) + pow(abs(y_1 - y_2), 2)), 0.5);
    distance_2=pow((pow(abs(x_0 - x_2), 2) + pow(abs(y_0 - y_2), 2)), 0.5);
    perimeter = (distance_0 + distance_1 + distance_2)/2;
    area = pow(perimeter*(perimeter-distance_0)*(perimeter-distance_1)*(perimeter-distance_2), 0.5);
    printf("\n\n%f", area);
}
