#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEQ 10

int arr1[SIZEQ], arr2[SIZEQ];
int head1, tail1, head2, tail2;

print()
{
  int i;
  printf("Current Stack is\n\t\t");
  for(i = 0; i <= tail1; i++){
    printf("%d\t", arr1[i]);
  }
  printf("\n");
}

int enqueue(int *arr, int num, int *t, int *h)
{
  int tail = *t;
  if((tail + 1) == SIZEQ){
    printf("Queue Full\n");
    return -1;
  }
  tail++;
  arr[tail] = num;
  *t = tail;
  if((*h) == -1){
    (*h) = 0;
  }
  return 0;
}

push(int num)
{
  int ret;
  ret = enqueue(arr1, num, &tail1, &head1);
  if(ret){
    printf("Failed to push data\n");
    return;
  }
}

int dequeue(int *arr, int *tail, int *head)
{
  int h = *head;
  if(h == -1 && *tail == -1){
    printf("Queue is empty\n");
    return -1;
  }
  printf("Data is %d\n", arr[h]);
  h++;
  if((h - 1) == *tail){
    h = (*tail) = -1;
  }
  *head = h;
  return 0;
}

pop()
{
  int i, ret;
  head2 = tail2 = -1;
  for(i = tail1; i >= 0; i--){
    enqueue(arr2, arr1[i], &tail2, &head2);
  }
  ret = dequeue(arr2, &tail2, &head2);
  if(ret){  
    printf("Failed to POP\n");
    return;
  }
  head1 = tail1 = -1;
  for(i = tail2; (i >=head2) && (i != -1); i--){
    enqueue(arr1, arr2[i], &tail1, &head1);
  }
}

int main()
{
  int choice, num, exit = 0;
  head1 = tail1 = head2 = tail2 = -1;
  while(exit != 1){
    printf("1. PUSH to stack\n"
	   "2. POP From stack\n"
	   "3. Print Stack\n"
	   "4. Exit\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("Input a number to push to stack\n");
      scanf("%d", &num);
      push(num);
      break;
    case 2:
      pop();
      break;
    case 3:
      print();
      break;
    case 4:
      printf("Exiting the Program. !!Bye Bye!!\n");
      exit = 1;
      break;
    default:
      printf("Invalid Entry\n");			
      break;
    }
  }
  return 0;
}
