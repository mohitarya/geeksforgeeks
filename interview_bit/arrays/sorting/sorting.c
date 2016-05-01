#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);

int main()
{
    int *arr, n, i;
    printf("Input the number of elements in the array\n"); 
    scanf("%d", &n);
    if(n <= 0){
        printf("Error:: Interger list should be greater then 0\n");
        return -1;
    }
    arr = (int *) malloc(sizeof(int) * n);
    if(arr == NULL){
        printf("Error:: Out of memory\n");
        return -1;
    }
    printf("Info:: Randomly generated array list is\n\t");
    for(i = 0; i < n; i++){
        *(arr + i) = rand()/1000000;
        printf("%d ", *(arr + i));
    }
    printf("\n");
    insertion_sort(arr, n);
    return 0;
}

void insertion_sort(int *arr, int n)
{
    int i, key, index, j;
    for(i = 1; i < n; i++){
        key = *(arr + i);
        index = i;
        while((index >= 0) && (*(arr + (index - 1)) > key)){
            *(arr + index) = *(arr + (index - 1));
            index--;
        }
        *(arr + index) = key;
    }
    printf("Info:: Sorted via insersion sort, array list is\n\t");
    for(j = 0; j < n; j++){
        printf("%d ", *(arr + j));
    }
    printf("\n");

}
