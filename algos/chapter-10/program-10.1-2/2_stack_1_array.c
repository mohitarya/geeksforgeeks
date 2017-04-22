#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 10

int arr[STACKSIZE];
int ptr1 = -1, ptr2 = STACKSIZE;

print()
{
  int i;
  printf("Stack-1 is::\n\t\t");
  for(i = 0; i <= ptr1; i++){
    printf("%d\t", arr[i]);
  }
  printf("\n");
  printf("Stack-2 is::\n\t\t");
  for(i = (STACKSIZE - 1); i >= ptr2; i--){
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

pop2()
{
  if(ptr2 == STACKSIZE){
    printf("POP Failed, Stack is Empty\n");
    return;
  }else{
    printf("Value is %d\n", arr[ptr2]);
    ptr2++;
  }
}

pop1()
{
  if(ptr1 == -1){
    printf("POP failed, Stack is empty\n");
    return;
  }else{
    printf("Poped value is %d\n", arr[ptr1]);
    ptr1--;
  }
}

push2(int num)
{
  if((ptr2 - 1) == ptr1){
    printf("PUSH Failed, STack is Full\n");
    return;
  }else{
    ptr2--;
    arr[ptr2] == num;
  }
}

push1(int num)
{
  // Stack one must not over ride the stack 2
  if((ptr1 + 1) == ptr2){
    printf("PUSH failed, Stack is Full\n");
    return;
  }else{
    ptr1++;
    arr[ptr1] = num;
  }
}

int main()
{
  int choice, num, exit = 0;
  while(exit != 1){
    printf("1. Input to stack-1\n"
	   "2. Input to stack-2\n"
	   "3. POP from stack-1\n"
	   "4. POO from stack-2\n"
	   "5. Print Stacks\n"
	   "6. Exit\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("Input a number to add to the stack\n");
      scanf("%d", &num);
      push1(num);
      break;
    case 2:
      printf("Input a number to add to the stack\n");
      scanf("%d", &num);
      push2(num);
      break;
    case 3:
      pop1();
      break;
    case 4:
      pop2();
      break;
    case 5:
      print();
      break;
    case 6:
      exit = 1;
      break;
    default:
      printf("Not a valid choice, Try Again!!\n");
      break;
    }
  }
}
