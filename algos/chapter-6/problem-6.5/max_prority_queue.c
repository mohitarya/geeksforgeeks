#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISHEAPFULL(x, y) ((x == (y - 1)) ? 1 : 0)
#define ROOT(x) ((x % 2) ? ((x / 2)) : ((x / 2) - 1))
#define SWAP(x, y, z) ((z = x), (x = y), (y = z))
#define LEFT(x) (((x * 2) + 1))
#define RIGHT(x) (((x * 2) + 2))

max_heapify(int *heap, int heap_size, int index)
{
  int largest, temp;
  while(RIGHT(index) <= heap_size){
    if(heap[LEFT(index)] > heap[index]){
      largest = LEFT(index);
    }else{
      largest = index;
    }
    if(heap[RIGHT(index)] > heap[largest]){
      largest = RIGHT(index);
    }
    if(index != largest){
      SWAP(heap[index], heap[largest], temp);
      index = largest;
    }else{
      break;
    }
  }
  return 0;
}

int heap_increase_key(int *heap, int index, int num)
{
  int root, child, temp;
  if(heap[index] > num){
    printf("Error key is smaller then current key\n");
    return -1;
  }
  heap[index] = num;
  child = index;
  while(child != 0){
    root = ROOT(child);
    if(heap[child] > heap[root]){
      SWAP(heap[child], heap[root], temp);
      child = root;
    }else{
      break;
    }
  }
  return 0;
}

insert(int *heap, int *heap_size, int num)
{
  int ret_val, index;
  index = (*heap_size) + 1;
  heap[index] = num;
  *heap_size = index;
  if(*heap_size != 0){
    ret_val = heap_increase_key(heap, *heap_size, num);
    if(ret_val != 0){
      printf("Error While inserting the Key\n");
      *heap_size = (*heap_size) - 1;
      return -1;
    }
  }
  printf("Heap after inserting num %d\t\t\n", num);
  print(heap, (*heap_size) + 1);
  return 0;
}

int main()
{
  int choice, heap_size, arr_size, num, quit = 0, temp, key, value;
  int arr[100];
  heap_size = -1;
  arr_size = 100;
  while(1){
    printf("1. Insert an element (Max elements can be 100)\n"
	   "2. Get MAximum\n"
	   "3. Extarct Maximum\n"
	   "4. Increase a key Value\n"
	   "5. Print the Queue\n"
	   "6. Exit\n"
	   "Insert Number (e.g. 1) as a choice::\t");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("Input an element\n");
      scanf("%d", &num);
      if(!(ISHEAPFULL(heap_size, arr_size))){
	if((insert(arr, &heap_size, num))){
	  printf("Failed to insert element %d into heap. Try Again!!\n", num);
	}
      }else{
	printf("Heap is Full retry\n");
	break;
      }
      break;
    case 2:
      printf("The maximum is %d\n", arr[0]);
      break;
    case 3:
      // Saving the maximum in a temp variable
      temp = arr[0];
      arr[0] = arr[heap_size];
      if(max_heapify(arr, heap_size - 1, 0)){
	printf("Failed to extract the maximum\n");
      }else{
	heap_size--;
	printf("Maximum is %d\n", temp);
      }
      break;
    case 4:
      printf("Input the key::");
      scanf("%d", &key);
      printf("Input the value against key %d::", key);
      scanf("%d", &value);
      if(key > heap_size){
	printf("Key %d is greater then current heap size %d\n", key, heap_size);
	break;
      }else if(arr[key] >= value){
	printf("Value %d against key %d, must be greater then cuurent value\n", key, value);
	break;
      }
      if(heap_increase_key(arr, key, value)){
	printf("Failed to increase the key value\n");
	break;
      }
      printf("New prority Queue is\n");
      print(arr, heap_size + 1);
      break;
    case 5:
      printf("The current Queue is:::\n\t\t");
      print(arr, heap_size + 1);
      break;
    case 6:
      printf("Current Queue is\n");
      print(arr, heap_size + 1);
      printf("Bye Bye !!\n");
      quit = 1;
      break;
    default:
      printf("Please Input the correct choice\n");
      break;
    }
    if(quit == 1){
      break;
    }
  }
  return 0;
}
