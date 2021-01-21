#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    while(1)
    {
        scanf("%s", &message);
        if(strcmp(message, "README") == 0)
            break;

    }
}
