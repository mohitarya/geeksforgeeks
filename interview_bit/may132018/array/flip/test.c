#include <stdio.h>
#include <stdlib.h>

#define STRTOINT(x) (((int) (*(x) - '0') == 1) ? -1 : 1)

int main()
{
    char a[] = "101";
    printf("%d\n",STRTOINT(a)); 
    printf("%d\n", STRTOINT(a + 1));
    printf("%d\n", STRTOINT(a + 2));
}
