#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* cat: concatenate files, version 1 */
int main(int argc, char *argv[])
{
    int fp;
    void filecopy(int, int);

    if(argc == 1) /* no args; copy standard input */
        filecopy(0, 1);
    else
        while(--argc > 0)
            if ((fp = open(*++argv, O_RDONLY)) == -1)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fp, 1);
                close(fp);
            }
    return 0;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(int ifp, int ofp)
{
    char c;

    while ((read(ifp, &c, sizeof(c))) == 1)
		if(write(ofp, &c, 1) == -1)
		{
			perror("Error writing");
			exit(1);
		}
}
