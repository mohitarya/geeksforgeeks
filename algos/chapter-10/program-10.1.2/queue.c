#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define QSIZE 10

int arr[QSIZE], head, tail;

dequeue()
{
  // Checking if Queue is empty
  // Queue is not initialized
  if(head == -1 && tail == -1){
    printf("Dequeue Failed, Queue is empty");
    return;
  }
  // Current head pointer have some data;
  printf("Dequeued data is %d\n", arr[head]);
  // Increament the head pointer
  head++;
  // Checking the head pointer validation
  if(head == QSIZE){
    head = 0;
  }
  // before increamrnting head if it equals to tail then Queue is empty
  // Reinitializing the Queue
  if((head - 1) == tail){
    tail = head = -1;
  }
}

enqueue(int num)
{
  // First Checking if the queue is full
  // Below is the case when head is at starting and tail covered the full queue
  // Second case tail is one point ahead of head
  if((tail == (QSIZE -1) && head == 0) || (tail + 1 == head)){
    printf("Enqueue Error, Queue is Full\n");
    return;
  }
  // Checking if the tail at the end of the queue and head should not be at 0
  if(tail == (QSIZE - 1) && head != 0){
    tail = -1;
  }
  // Increament the tail
  tail++;
  arr[tail] = num;
  // Now Queue have some value so make head as 0
  if(head == -1){
    head = 0;
  }
}

int main()
{
  int  choice, num, exit;
  head = tail = -1;
  while (exit != 1){
    printf("1. Enqueue\n"
	   "2. Dequeue\n"
	   "3. Exit From\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("Input the num to enqueue\n");
      scanf("%d", &num);
      enqueue(num);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      exit = 1;
      break;
    default:
      printf("Invalid Input\n");
      break;
    }
  }
  return 0;
}
