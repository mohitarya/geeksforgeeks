#include <stdio.h>
#include <stdlib.h>

void print_arr(int **, int, int);
void print_arr_circular(int **, int, int);

int main()
{
    int **arr;
    int rows, columns, i, j, number = 0, ret;
    printf("Input Number of rows\t");
    scanf("%d", &rows);
    printf("Input Number of column\t");
    scanf("%d", &columns);
    arr = (int **) malloc(sizeof(int *) * rows);
    if (!arr) {
        printf("Error in allocating the memory\n");
        ret = -1;
        goto error;
    }
    for(i = 0; i < rows; i++){
        *(arr + i) = (int * ) malloc(sizeof(int) * columns);
        if(!(*(arr + i))){
            ret = -1;
            goto error;
        }
    }
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++){
            *(*(arr + i) + j) = number++;
        }
    }
    print_arr_circular(arr, rows, columns);

    print_arr(arr, rows, columns);
    ret = 0;

error:
    if(arr){
        for(i = 0; i < rows; i++){
            if(*(arr + i)){
                free(*(arr + i));
            }
        }
        free(arr);
    }
return 0;
}

void print_arr(int **arr, int rows, int columns)
{
    int i, j;
    printf("Two D Array is:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

void print_arr_circular(int **arr, int rows, int columns)
{
    int i, j;
    int l_row_up, l_row_down, l_column_left, l_column_right;
    l_row_up = 0;
    l_row_down = rows - 1;
    l_column_left = 0;
    l_column_right = columns - 1;
    //loop when i is constant and j is varying
    while(l_column_left <= l_column_right){
        i = l_row_up;
        j = l_column_left;
        printf("i = %d, j = %d, l_row_up = %d, l_row_down = %d, l_column_left = %d, l_column_right = %d\n", i, j, l_row_up, l_row_down, l_column_left, l_column_right);
        while(j < l_column_right){
            printf("%d\t", *(*(arr + i) + j));
            printf("aaaaa\n");
            j++;
        }
        while(i <  l_row_down){
            printf("%d\t", *(*(arr + i) + j));
            printf("bbbbb\n");
            i++;
        }
        while(j > l_column_left){
            printf("%d\t", *(*(arr + i) + j));
            printf("cccc\n");
            j--;
        }
        while(i > l_row_up){
            printf("%d\t", *(*(arr + i) + j));
            printf("dddd\n");
            i--;
        }
        l_row_up++;
        l_row_down--;
        l_column_left++;
        l_column_right--;
        printf("\n");
    } 
    printf("\n");
}
