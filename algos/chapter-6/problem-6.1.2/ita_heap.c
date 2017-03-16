#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y, z) ((z = x), (x = y), (y = z))
#define LEFT(i) ((2 * i) + 1)
#define RIGHT(i) ((2 * i) + 2)
#define ROOT(x) (x / 2) - 1

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
  }else if (size >= r && arr[index] < arr[r]){
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
    }else if (size >= r && arr[index] < arr[r]){
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

int main()
{
  int arr[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
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
  return 0;
}
