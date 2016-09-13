#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_new_node(int);
void push_to_stack(int);
void print_stack();
void pop_from_stack();

struct node *head = NULL;

int main()
{
    pop_from_stack();
    push_to_stack(5);
    push_to_stack(10);
    pop_from_stack();
}

void print_stack()
{
    struct node *temp;
    temp = head;
    printf("Stack::\t");
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void pop_from_stack()
{
    int data;
    struct node *temp = head;
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    data = temp->data;
    head = temp->next;
    temp->next = NULL;
    free(temp);
    printf("Poped data is %d\n", data);
    print_stack();
}

void push_to_stack(int val)
{
    struct node *new_node;
    new_node = create_new_node(val);
    new_node->next = head;
    head = new_node;
    print_stack();
}

struct node *create_new_node(int val)
{
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    if(!new_node){
        return NULL;
    }else{
        new_node->data = val;
        return new_node;
    }
}
