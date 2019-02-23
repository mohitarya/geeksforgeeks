#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void merge(int *arr, int start_index, int mid_index, int end_index)
{
    int temp_arr_size = (end_index - start_index) + 1;
    int temp_arr[temp_arr_size]; 
    int i, j, k, right_sub_array_completion_flag = 0;
    // Start with the left side
    // Compare each element with the right side
    // Fill the new array
    
    memset(temp_arr, 0x0, temp_arr_size);
    i = start_index;
    j = mid_index + 1;
    k = 0;
    while(i <= mid_index)
    {
        if(*(arr + i) <= *(arr + j))
        {
            *(temp_arr + k) = *(arr + i);
            i++;
        }
        else
        {
            *(temp_arr + k) = *(arr + j);
            j++;
        }
        k++;
        if(j > end_index)
        {
            right_sub_array_completion_flag = 1;
            break;
        }
    }
    if(right_sub_array_completion_flag == 1)
    {
        while(i <= mid_index)
        {
            *(temp_arr + k) = *(arr + i);
            i++;
            k++;
        }
    }
    else
    {
        while(j <= end_index)
        {
            *(temp_arr + k) = *(arr + j);
            j++;
            k++;
        }
    }
    for(i = 0, j = start_index; i < temp_arr_size; i++, j++)
    {
        *(arr + j) = *(temp_arr + i);
    }
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
    merge(arr, start_index, mid_index, end_index);
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
