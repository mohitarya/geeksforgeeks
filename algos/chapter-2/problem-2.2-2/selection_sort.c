#include <stdio.h>

#define MOVE(x,y,z) ((temp = x), (x = y), (y = temp))

void selection_sort(int *arr, int size)
{
    int i, j, key, temp;
    for(i = 0; i < size - 1; i++){
        key = i;
        for(j = i + 1; j < size; j++){
            if(*(arr + j) < *(arr + key)){
                key = j;
            }
        }
        MOVE(*(arr + i), *(arr + key), temp);
    }
}

void print(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}
int main()
{
    int arr[] = {7,2,0,4,1,9,3,5};
    int size = sizeof(arr)/sizeof(int);
    printf("Array before sorting is:::\n\t\t");
    print(arr, size);
    selection_sort(arr, size);
    printf("Array after sorting is:::\n\t\t");
    print(arr, size);
    return 0;
}
