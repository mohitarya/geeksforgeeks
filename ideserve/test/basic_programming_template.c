#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int fun(char *);

int main()
{
    char **abc;
    int index = -1;
    char *str = "Hello huafh";
    abc = (char **) malloc(sizeof(char *) * 50);
    *(abc + (++index)) = str;
    printf("%ld\n", abc);
    printf("%ld\n", *abc);
    printf("%ld\n", str);
    printf("%s\n", *abc);
    printf("%ld\n", *(abc + (++index)));
}
