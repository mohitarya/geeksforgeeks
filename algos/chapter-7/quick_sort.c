#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SWAP(x, y, z) ((z = x), (x = y), (y = z))

int partition(int *arr, int p, int r)
{
  int pivot, i, j, temp;
  pivot = arr[r];
  i = p - 1;
  for(j = p; j < r; j++){
    if(arr[j] <= pivot){
      i++;
      SWAP(arr[i], arr[j], temp);
    }
  }
  i++;
  SWAP(arr[i], arr[r], temp);
  printf("Return i is %d\n", i);
  return i;
}

quick_sort(int *arr, int p, int r)
{
  int q;
  if(p < r){
    q = partition(arr, p, r);
    quick_sort(arr, p, (q - 1));
    quick_sort(arr, (q + 1), r);
  }
}

int main()
{
  // Initializing the array
  int arr[] = {6, 2, 8, 7, 3, 1, 0, 5, 4};
  int size;
  size = sizeof(arr)/sizeof(int);
  printf("Input array is::\n\t\t");
  print(arr, size);
  quick_sort(arr, 0, (size - 1));
  printf("After Quick Sort Input array is\n\t\t");
  print(arr, size);
}
