#include <stdio.h>
#include <string.h>

int main()
{
    int plane[5]=, position, steps, direction_num, damage=1;
    char direction[5];
    scanf("%d%d%d%d%d%d", &plane[0], &plane[1], &plane[2], &plane[3], &plane[4], &position);
    while(1)
    {
        printf("Direction: ");
        scanf("%s", &direction);
        if(strcmp(direction, "Supernova") == 0)
            break;
        printf("Steps: ");
        scanf("%d", &steps);
        if(strcmp(direction, "left") == 0)
            direction_num = -1;
        else direction_num = 1;
        for(int i=0; i< steps; ++i)
        {
            position += direction_num;
            if(position<0)
            {
                position = 4;
                damage += 1;
            }
            else if(position>4)
            {
               position = 0;
               damage += 1;
            }
            plane[position] -= damage;
        }
    }
    for(int t=0; t<5; ++t)
        printf("%d, ", plane[t]);
    return 0;
}
