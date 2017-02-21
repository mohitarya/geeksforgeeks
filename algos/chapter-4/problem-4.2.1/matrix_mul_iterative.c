#include <stdio.h>
#include <stdlib.h>
#include <string.h>

print_2D(int row, int column, int arr[row][column])
{
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
print_2DD(int row, int column, int **arr)
{
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void mul(int row, int column, int A[row][column], int **B, int C[row][column])
{
    int i, j, k;
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            C[i][j] = 0;
            for(k = 0; k < row; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int A[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9,};
    int **B, i, j, val=0;
    int C[3][3];
    B = (int **)malloc(sizeof(int *) * 3);
    for(i = 0; i < 3; i++){
        B[i] = (int *)malloc(sizeof(int) * 3);
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            B[i][j] = ++val;
        }
    }
    printf("Matrix A is::\n");
    print_2D(3, 3, A);
    printf("Matrix B is::\n");
    print_2DD(3, 3, B);
    mul(3, 3, A, B, C);
    printf("Matrix C is::\n");
    print_2D(3, 3, C);
    return 0;
}
