#include <stdio.h>
#include <stdlib.h>

void insert_list_start(int);
void print_list(void);
struct node {
    int data;
    struct node *next;
};

struct node *head;

int main(void)
{
    int n, i;
    int element;
    head = NULL;
    printf("Input the number of elements to insert\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("Input the data to insert\n");
        scanf("%d", &element);
        insert_list_start(element);
    }
}
void insert_list_start(int element)
{
    //Create a node
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(!temp){
        printf("Not enough memory to create a node\n");
    }else{
        temp->data = element;
        temp->next = head;
        head = temp;
    }
    print_list();
}

void print_list(void)
{
    struct node *temp;
    temp = head;
    printf("List::\n");
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
