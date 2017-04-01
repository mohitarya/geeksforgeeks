#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Counting Sort algo
int *counting_sort(int *arr, int max_element, int size_arr)
{
  int *B, *C, i;
  B = (int *) malloc(sizeof(int) * (max_element + 1));
  C = (int *) malloc(sizeof(int) * size_arr);
  if(B == NULL || C == NULL){
    printf("Failed to allocate the memory\n");
    return NULL;
  }
  memset(B, 0x0, (sizeof(int) * (max_element + 1)));
  memset(C, 0x0, (sizeof(int) * size_arr));
  for(i = 0; i < size_arr; i++){
    B[arr[i]] += 1;
  }
  for(i = 1; i <= max_element; i++){
    B[i] = B[i] + B[i - 1];
  }
  for(i = (size_arr - 1); i >= 0; i--){
    C[B[arr[i]] - 1] = arr[i];
    B[arr[i]] -= 1;
  }
  return C;
}

int main()
{
  // Array Which needs to be sorted
  int arr[] = {0, 6, 7, 2, 3, 5, 4, 4, 0};
  // COnsidering the value in the array will not be more then 7
  int *C;
  int arr_size, max_element;
  arr_size = sizeof(arr)/sizeof(int);
  max_element = 7;
  printf("Array before sorting\n");
  print(arr, arr_size);
  C = counting_sort(arr, max_element, arr_size);
  printf("Array after sorting\n");
  print(C, arr_size);
}
