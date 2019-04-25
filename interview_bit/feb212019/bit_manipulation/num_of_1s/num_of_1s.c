#include <stdio.h>

int main()
{
    int x = 500;

    int y = x;
    int count = 0;
    while(y)
    {
        if((y & 1) == 1)
        {
            count++;
        }
        y >>= 1;
    }
    printf("%d\n", count);
}
