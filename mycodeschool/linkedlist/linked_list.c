#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_list_start(struct node **, int);
void print_list(struct node *);

int main(void)
{
    int n, i;
    int element;
    struct node *head = NULL;
    printf("Input the number of elements to insert\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        printf("Input the data to insert\n");
        scanf("%d", &element);
        insert_list_start(&head, element);
    }
}
void insert_list_start(struct node **head, int element)
{
    //Create a node
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(!temp){
        printf("Not enough memory to create a node\n");
    }else{
        temp->data = element;
        temp->next = *head;
        *head = temp;
    }
    print_list(*head);
}

void print_list(struct node *head)
{
    printf("List::\t");
    while(head != NULL){
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}
