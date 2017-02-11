#include <stdio.h>

void print(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void sort(int *arr, int size){
    int i = size - 2;
    int key = arr[size - 1];
    while(i >= 0){
        if(arr[i] > key){
            arr[i + 1] = arr[i];
            i--;
        }else{
            break;
        }
    }
    arr[i + 1] = key;
}

void insertion_sort_via_rec(int *arr, int size)
{
    if(size == 1){
        return;
    }else{
        insertion_sort_via_rec(arr, size-1);
        sort(arr, size);
    }
}

int main()
{
    int arr[] = {0, 5, 3, 1, 8, 6, 2, 1};

    int size = sizeof(arr)/sizeof(int);
    printf("Array is::\n\t\t");
    print(arr, size);

    insertion_sort_via_rec(arr, size);

    printf("Sorted Array is::\n\t\t");
    print(arr, size);
    
    return 0;
}
