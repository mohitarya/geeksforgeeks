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

int partition(int *arr, int start_index, int end_index)
{
    int pivot, i, temp_index, temp;

    pivot = end_index;
    temp_index = start_index;
    for(i = start_index; i < end_index; i++)
    {
        if(*(arr + i) < *(arr + pivot ))
        {
                SWAP(*(arr + i), *(arr + temp_index), temp);
                temp_index++;
        }
    }
    SWAP(*(arr + pivot), *(arr + temp_index), temp);
    return temp_index;
}

void quick_sort(int *arr, int start_index, int end_index)
{
    int partitioned_index;
    
    if(start_index == end_index)
    {
        return;
    }

    partitioned_index = partition(arr, start_index, end_index);

    quick_sort(arr, start_index, partitioned_index - 1);

    if (partitioned_index == end_index)
    {
        return;
    }

    quick_sort(arr, partitioned_index + 1, end_index);
}

int main()
{
    int arr[6] = {6, 3, 0, 1, 40, 2};
    int arr_size = sizeof(arr)/sizeof(int);
    int key, i, j, temp;
    printarr(arr, arr_size);
    quick_sort(arr, 0, arr_size - 1);
    printarr(arr, arr_size);

    return 0;
}
