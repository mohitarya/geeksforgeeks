#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y, z) ((z = x), (x = y), (y = z))
#define LEFT(i) ((2 * i) + 1)
#define RIGHT(i) ((2 * i) + 2)
#define ROOT(x) ((x %2) ? (x/2) : ((x / 2) - 1))

void min_heapify(int *arr, int index, int size)
{
  int temp, l, r, smallest;
  l = LEFT(index);
  r = RIGHT(index);
  smallest = index;
  if(size >= l && arr[index] > arr[l]){
    smallest = l;
  }else if(size >= r && arr[index] > arr[r]){
    smallest = r;
  }
  if(smallest != index){
    SWAP(arr[index], arr[smallest], temp);
    min_heapify(arr, smallest, size);
  }
}

void max_heapify(int *arr, int index, int size)
{
  int temp, l, r, largest;
  l = LEFT(index);
  r = RIGHT(index);
  largest = index;
  if(size >= l && arr[index] < arr[l]){
    largest = l;
  }
  if (size >= r && arr[r] > arr[largest]){
    largest = r;
  }
  if(largest != index){
    SWAP(arr[index], arr[largest], temp);
    max_heapify(arr, largest, size);
  }
}

void max_heapify_itr(int *arr, int index, int size){
  int temp, l, r, largest;

  while(index < size){
    l = LEFT(index);
    r = RIGHT(index);
    largest = index;
    if(size >= l && arr[index] < arr[l]){
      largest = l;
    }
    if (size >= r && arr[r] > arr[largest]){
      largest = r;
    }
    if(largest != index){
      SWAP(arr[index], arr[largest], temp);
      index = largest;
    }else{
      break;
    }
  }
}

void build_max_heap(int *arr, int size)
{
  int start_index, i;
  start_index = ROOT(size);
  printf("Started from the index %d\n", start_index);
  for(i = start_index; i >= 0; i--){
    max_heapify(arr, i, size);
  }
}

void heap_sort(int *arr, int size)
{
  int temp, i;
  build_max_heap(arr, size);
  for(i = size; i >= 1; i--){
    SWAP(arr[0], arr[i], temp);
    max_heapify(arr, 0, i-1);
  }
}

int main()
{
  int arr[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
  int arr1[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
  int arr2[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
  int arr1_size = (sizeof(arr1)/sizeof(int));
  int arr2_size = (sizeof(arr1)/sizeof(int));
  int size = (sizeof(arr)/sizeof(int));
  int filled = size - 1;
  printf("Array After heapify\n\t\t");
  print(arr, size);
  //min_heapify(arr, 2, filled);
  //printf("Array After heapify\n\t\t");
  //print(arr, size);
  max_heapify_itr(arr, 2, filled);
  printf("Array After heapify itr \n\t\t");
  print(arr, size);
  build_max_heap(arr1, arr1_size-1);
  printf("Array after building as heap \n\t\t");
  print(arr1, arr1_size);
  heap_sort(arr2, arr2_size - 1);
  printf("Array after building as heap \n\t\t");
  print(arr2, arr2_size);
  return 0;
}
