#include <stdio.h>
#include <stdlib.h>

#define SWAP(ele1, ele2, temp) ((temp = ele1), (ele1 = ele2), (ele2 = temp))

void printarr(int *arr, int size)
{
    int i;
    printf("Array is::::\n");
    for(i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

void merge_sort(int *arr, int start_index, int end_index)
{
    int mid_index;
    if(start_index == end_index)
    {
        return;
    }
    mid_index = ((end_index - start_index) / 2) + start_index;

    merge_sort(arr, start_index, mid_index);
    merge_sort(arr, mid_index + 1, end_index);

    // Merge two sorted List
}

int main()
{
    int arr[8] = {14,7,3,12,9,11,6,2};
    int arr_size = sizeof(arr)/sizeof(int);
    printarr(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    printarr(arr, arr_size);

    return 0;
}
