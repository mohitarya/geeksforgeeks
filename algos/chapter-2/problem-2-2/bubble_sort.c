/*
 * Bubblesort is a popular, but inefficient, sorting algorithm. It works by repeatedly
 * swapping adjacent elements that are out of order.
 * BUBBLESORT.A/
 * 1 for i D 1 to A:length  1
 * 2 for j D A:length downto i C 1
 * 3 if AOEj  < AOEj  1
 * 4 exchange AOEj  with AOEj  1
 * 
 * Note - Build the static or dynamic Lib from common and use while compiling
 * */

#include <stdio.h>

#define SWAP(x,y,z) ((z = x), (x = y), (y = z))

void bubble_sort(int *arr, int size)
{
    int i,j, temp;
    for(i = 0; i < size-1; i++){
        for(j = size-1; j > i; j--){
            if(arr[j] < arr[j-1]){
                SWAP(arr[j], arr[j -1], temp);
            }
        }
    }
}

int main()
{
    int arr[] = {0, 2, 1, 8, 5, 4, 0};
    int size = sizeof(arr)/sizeof(int);
    printf("Before Sort::\n\t\t");

    print(arr, size);
    
    bubble_sort(arr, size);
    printf("After Sort::\n\t\t");

    print(arr, size);
}
