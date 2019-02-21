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

int main()
{
    int arr[6] = {6, 3, 0, 1, 40, 2};
    int arr_size = sizeof(arr)/sizeof(int);
    int key, i, j, temp;
    printarr(arr, arr_size);

    for(i = 1; i < arr_size; i++)
    {
        key = i;
        for(j = (i - 1); j >= 0; j--)
        {
            if(*(arr + key) < *(arr + j))
            {
                SWAP(*(arr + key), *(arr + j), temp);
                key = j;
            }
        }
    }
    printarr(arr, arr_size);

    return 0;
}
