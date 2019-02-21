#include <stdio.h>

void print_arr(int *arr, int start, int size)
{
        int i = start;
        printf("arr:::\n\t\t\t"); 
            for(; i <= size; i++){
                        printf("%d\t", *(arr + i));
                            }
            printf("\n");
}

void merge(int *arr, int arr_start, int mid, int arr_end)
{
    int temp_size = arr_end - arr_start + 1;
    int temp[temp_size], k = 0;
    int i = arr_start, j = arr_start + mid + 1;
    // Sorting the array
    while(i <= (arr_start + mid) && j <= arr_end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }else if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
        }else{
            temp[k++] = arr[i++];
            temp[k++] = arr[j++];
        }
    }
    if(i > (arr_start + mid)){
        while(j <= arr_end){
            temp[k++] = arr[j++];
        }
    }else{
        while(i <= (arr_start + mid)){
            temp[k++] = arr[i++];
        }
    }
    for(i = arr_start; i < temp_size; i++){
        arr[arr_start + i] = temp[i];
    }
}

void merge_sort(int *arr, int arr_start, int arr_end)
{
    if(arr_start == arr_end)
        return;
    int mid = (arr_end - arr_start) / 2;
    // Terminating Condition
    // For left side of the array
    merge_sort(arr, arr_start, (arr_start + mid));

    // For right side of the array
    merge_sort(arr, (arr_start + mid + 1), arr_end);
    
    // Merging of two array in sorted order
    merge(arr, arr_start, mid, arr_end);
}


int main()
{
    //int arr[] = {12, 9, 5, 1, 4, 3, 0, 5, 9, 20, 19};
    int arr[] = {12, 9, 5, 1, 19};
    int size = sizeof(arr)/sizeof(int);
    print_arr(arr, 0, size-1);
    merge_sort(arr, 0, (size -1));
    print_arr(arr, 0, size-1);

}
