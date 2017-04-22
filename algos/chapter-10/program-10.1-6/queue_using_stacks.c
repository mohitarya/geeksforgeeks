#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZESTACK 10

int arr1[SIZESTACK], head1 = -1;
int arr2[SIZESTACK], head2 = -1;

printQ()
{
  int i;
  printf("Queue::\n\t\t");
  for(i = 0; i <= head1; i++){
    printf("%d\t", arr1[i]);
  }
  printf("\n");
}

pop(int *arr, int *h)
{
  int head = *h;
  if(head == -1){
    printf("Dequeue Failed, Empty Queue\n");
    return;
  }
  printf("Enqueued data is %d\n", arr[head]);
  head--;
  *h = head;
}

dequeue()
{
  int i;
  head2 = -1;
  for(i = head1; i >= 0; i--){
    push(arr2, arr1[i], &head2);
  }
  pop(arr2, &head2);
  head1 = -1;
  for(i = head2; i >= 0; i--){
    push(arr1, arr2[i], &head1);
  }
}

push(int *arr, int num, int *h)
{
  int head = *h;
  if((head + 1) >= SIZESTACK){
    printf("Failed to enqueue the data, Queue Full\n");
    return;
  }else{
    head++;
    arr[head] = num;
    *h = head;
  }
}

enqueue(int num)
{
  push(arr1, num, &head1);
}

int main()
{
  int choice, num, exit = 0;
  while(exit != 1){
    printf("1. Enqueue an number\n"
	   "2. Dequeue a number\n"
	   "3. Print Queue\n"
	   "4. Exit\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("Input a number to enqueue\n");
      scanf("%d", &num);
      enqueue(num);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      printQ();
      break;
    case 4:
      exit = 1;
      break;
    default:
      printf("Wrong Input\n");
      break;
    }
  }
}
