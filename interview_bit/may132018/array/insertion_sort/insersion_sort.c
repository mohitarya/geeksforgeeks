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
    int arr[] = {6, 5, 7, 9, 2, 1, 0};
    int size = sizeof(arr)/sizeof(int);
    int key, temp, i, j;
    print_arr(arr, size);
    for(i = 1; i < size; i++){
        key = i;
        for(j = (i - 1); j >= 0; j-- ){
            // If array at key is smaller then its previous element then interchange
            // else continue
            if(arr[key] > arr[key - 1]){
                SWAP(arr[key], arr[key - 1], temp);
                key--;
            }else{
                break;
            }
        }
    }
    print_arr(arr, size);
    return 0;
}


