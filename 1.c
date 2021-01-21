#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int body_length[n], wing_length[n];
    float body_width[n];
    for(int i=0; i<n; ++i)
    {
        scanf("%d%f%d", &body_length[i], &body_width[i], &wing_length[i]);
        printf("Phoenix %d\nBody Length: %d\nBody Width: %.2f\nLength of one wing: %d\n", i + 1, body_length[i], body_width[i], wing_length[i]);
        printf("Total Years: %.2f\n", (body_length[i]*body_length[i])*(body_width[i] + 2*wing_length[i]));
    }
    return 0;
}
