#include <stdio.h>

void print_arr(int *ptr, int size)
{
    int i;
    printf("Array is:::\n\t\t");

    for(i = 0; i < size; i++){
        printf("%d\t", *(ptr + i));
    }
    printf("\n");
}

// Insertion sort descending order
void insertion_sort_desc(int *ptr, int size)
{
    int i, j, key;
    for(i = 1; i < size; i++){
        key = *(ptr + i);
        for(j = i - 1; j >= 0; j--){
            if(*(ptr + j) < key){
                *(ptr + j + 1) = *(ptr + j);
            }else{
                break;
            }
        }
        *(ptr + j + 1) = key;
    }
    printf("Sorted descending order ");
    print_arr(ptr, size);
}

// Insertion sort ascending order
void insertion_sort(int *ptr, int size)
{
    int i, j, key;
    for(i = 1; i < size; i++)
    {
        key = *(ptr + i);
        for(j = i - 1; j >= 0; j--){
            if(*(ptr + j) > key){
                *(ptr + j + 1) = *(ptr + j);
                continue;
            }else{
                break;
            }
        }
        *(ptr + j + 1) = key;
    }
    printf("Sorted ");
    print_arr(ptr, size);
}

int main()
{
    int arr[] = {7, 2, 0, 1, 8, 3};
    int arr_size = sizeof(arr)/sizeof(int);
    print_arr(arr, arr_size);
    insertion_sort(arr, arr_size);
    insertion_sort_desc(arr, arr_size);
}
