#include<stdio.h>

#define SWAP(x, y, z) ((temp = x), (x = y), (y = temp))

void print_arr(int *arr, int size)
{
        int i = 0;
            for(; i < size; i++){
                        printf("arr[%d] = %d\n", i, *(arr + i));
                            }
}


int main()
{
    int arr[] = {1, 6, 9, 4, 0, 0, 8, 5};
    int size = sizeof(arr)/sizeof(int);
    int i, j, temp, key;
    print_arr(arr, size);
    for(i = 0; i < size; i++){
        key = 0;
        for(j = 1; j < (size - i); j++){
            if(arr[key] > arr[j]){
                SWAP(arr[key], arr[j], temp);
            }
            key++;
        }
    }
    print_arr(arr, size);
    return 0;
}
