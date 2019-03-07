#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define m 3
#define n 4

void print2darray(int arr[m][n])
{
    int i, j;
    printf("ARRAY:::::\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[m][n] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    print2darray(arr);
}
