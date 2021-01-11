#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int i;
    for(i=0;i<2;i++)
    {
        fork();
        printf("-");
	fflush(stdout);
    }
    return 0;
}
//i=0: f - ff1 -
//i=1: f - ff1 - fff1 - ff2 - 


