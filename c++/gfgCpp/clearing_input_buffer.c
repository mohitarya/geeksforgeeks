#include <stdio.h>

int main()
{
    char str[100], ch;

    scanf("%s", str);

    while(getchar() != '\n');
    
    // fflush is not working in C
    //fflush(stdin);

    ch = getchar();

    printf("%s\n", str);

    printf("%c\n", ch);
}
