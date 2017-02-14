#include <stdio.h>

void inverse(int *arr, int size)
{
    int i, j, key;
    for(i = 0; i < (size - 1); i++){
        key = arr[i];
        for(j = (i+1); j < size; j++){
            if(key > arr[j]){
                printf("Inverse are %d, %d\n", key, arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {2, 3, 8, 6, 1};
    int size = sizeof(arr)/sizeof(int);
    printf("Input array is\n");
    print(arr, size);
    
    inverse(arr, size);
}
