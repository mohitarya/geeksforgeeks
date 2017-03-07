#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y, z) ((z = x), (x = y), (y = z))

int current_heap_size = -1;

void make_max_heap(int *heap)
{
  int root = current_heap_size, temp;
  while( current_heap_size != 0 ){
    if(root % 2 ){
      if(heap[root] > heap[(root - 1)/2]){
	SWAP(heap[root], heap[(root - 1)/2], temp);
	root = (root - 1) / 2;
      }else{
	break;
      }
    }else{
      if(heap[root] > heap[(root - 2)/2]){
	SWAP(heap[root], heap[(root - 2)/2], temp);
	root = (root - 2)/2;
    }else{
      break;
    }
    }
  }
}

void put_element(int *heap, int size, int element)
{
  heap[++current_heap_size] = element;
  if(current_heap_size != -1){
    make_max_heap(heap);
  }
}

int main()
{
  int *heap, i, ele;
  int num;
  printf("Input the number of elements present in the array\n");
  scanf("%d", &num);
  heap = (int *) malloc(sizeof(int) * num);
  for(i = 0; i < num; i++){
    printf("Input the element\n");
    scanf("%d", &ele);
    put_element(heap, num, ele);
  }
  return 0;
}
