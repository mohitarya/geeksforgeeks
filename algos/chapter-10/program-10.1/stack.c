#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRSIZE 50

int isstackfull(int top){
  if((top + 1) == ARRSIZE){
    return 1;
  }else{
    return 0;
  }
}
void push(int *arr, int num, int *top)
{
  int index;
  index = *top;
  // Before pushing to the top just checking if the stack is full
    if(isstackfull(index)){
    printf("Stack is full. Can not add the num %d\n", num);
    return;
  }
  index++;
  arr[index] = num;
  *top = index;
}

isstackempty(int index)
{
  if(index == -1){
    return 1;
  }else{
    return 0;
  }
}

void pop(int *arr, int *top)
{
  int index;
  index = *top;
  if(isstackempty(index)){
    printf("Stack is empty\n");
    return;
  }
  printf("Value in stack is %d\n" , arr[index]);
  index--;
  *top = index;
}

int main()
{
  //Initializing the stack array
  int arr[ARRSIZE];
  int input, num, top = -1, exit = 0;
  while(exit != 1){
    // Following Operations are supported n stack
    printf("1. Push to the stack\n"
	   "2. Pop From the stack\n"
	   "3. Current stack position\n"
	   "4. Print the stack\n"
	   "5. Exit\n");
    scanf("%d", &input);
    switch(input){
    case 1:
      printf("Input a number to push to the stack\n");
      scanf("%d", &num);
      push(arr, num, &top);
      break;
    case 2:
      pop(arr, &top);
      break;
    case 3:
      printf("Current stack position is %d\n", top);
      break;
    case 4:
      printf("Currently stack contains the following values\n");
      print(arr, top+1);
      break;
    case 5:
      printf("!! Bye Bye !!\n");
      exit = 1;
      break;
    default:
      printf("Not a valid input\n");
      break;
    }
  }
} 
