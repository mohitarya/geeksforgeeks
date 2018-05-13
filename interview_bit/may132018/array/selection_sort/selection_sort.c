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
    int arr[] = {2, 3, 9, 6, 3, 8, 0};
    int size = sizeof(arr)/sizeof(int);
    int i, j, temp, key;
    print_arr(arr, size);
    for(i = 0; i < size - 1; i++){
        key = i;
        for(j = (i + 1); j < size; j++){
            if(arr[key] > arr[j]){
                key = j;
            }
        }
        SWAP(arr[i], arr[key], temp);
    }
    print_arr(arr, size);
    return 0;
}
