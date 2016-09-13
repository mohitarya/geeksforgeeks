#include <stdio.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

int arr_stack[MAX_SIZE];
int top = -1;

void push_to_stack(int);
int is_stack_empty();
int is_stack_full();
void print_stack();
void pop_from_stack();
int top_of_stack();

int main(void)
{
    int ret_val = -1;
    push_to_stack(5);
    pop_from_stack();
    ret_val = top_of_stack();
    printf("top = %d\n", ret_val);
    return 0;
}

int top_of_stack()
{
    if(is_stack_empty()){
        printf("Stack is empty\n");
    }else{
        return arr_stack[top];
    }
    return -1;
}

void pop_from_stack()
{
    if(is_stack_empty()){
        printf("Cannot POP as the stack is empty");
        return;
    }
    else{
        printf("Value is %d\n", arr_stack[top]);
        top--;
    }
    print_stack();
}

void print_stack()
{
    int i;
    printf("Stack::\t");
    for(i = 0; i <= top; i++){
        printf("%d\t", arr_stack[i]);
    }
    printf("\n");
}

int is_stack_full()
{
    if(top == MAX_SIZE){
        return TRUE;
    }else{
        return FALSE;
    }
}

void push_to_stack(int data)
{
    if(is_stack_full()){
        printf("Error Can not add more item to stack, it is full\n");
        return;
    }
    if(is_stack_empty()){
        top = 0;
    }else {
        top++;
    }
    arr_stack[top] = data;
    print_stack();
}

int is_stack_empty()
{
    if(top == -1){
        return TRUE;
    }else{
        return FALSE;
    }
}
