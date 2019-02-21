#include <stdio.h>

#define SWAP(x, y, z) ((z=x), (x = y), (y = z))

void print_arr(int *arr, int start, int size)
{
            int i = start;
                    printf("arr:::\n\t\t\t");
                                for(; i <= size; i++){
                                                            printf("%d\t", *(arr + i));
                                                                                        }
                                            printf("\n");
}

int sort_pivot_last(int *arr, int arr_start, int arr_end)
{
    int temp, i;
    // Setting pivot as last element in the array Pivot 
    int pivot = arr[arr_end];
    int pivot_pos = arr_start;
    for(i = arr_start; i < arr_end; i++){
        if(arr[i] <= pivot ){
            SWAP(arr[pivot_pos], arr[i], temp);
            pivot_pos++;
        }
    }
    SWAP(arr[pivot_pos], arr[arr_end], temp);
    return pivot_pos;
}

// Quick Sort
void quick_sort(int *arr, int arr_start, int arr_end)
{
    int pivot_pos;
    if(arr_start == arr_end ){
        return;
    }
    pivot_pos = sort_pivot_last(arr, arr_start, arr_end);
    // Recurrsive calling for left side array
    if(pivot_pos != arr_start){
        quick_sort(arr, arr_start, pivot_pos-1);
    }
    // Recurrsive calling for Right side array
    if(pivot_pos != arr_end){
        quick_sort(arr, pivot_pos + 1, arr_end);
    }
}

int main()
{
    int arr[] = {9, 4, 2, 8};
    int size = sizeof(arr)/sizeof(int);
    print_arr(arr, 0, size-1);
    quick_sort(arr, 0, size-1);
    print_arr(arr, 0, size-1);
}
