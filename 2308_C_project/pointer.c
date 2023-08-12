#include <stdio.h>
#include <string.h>


char dst[30];

int main()
{
    char src[30] = "Python I love Language";
    

    strncpy(dst, src + 7, 6);
    printf("dst : %s\n", dst);
    return 0;
}