#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    void *data;
    struct node *next;
};

void print_list(struct node *);
void add_front(struct node **, void *);

int main()
{
    struct node *node1, *node2, *node3, *head;
    void *newdata;
    int size;

    node1 = (struct node *) malloc(sizeof(struct node));
    node2 = (struct node *) malloc(sizeof(struct node));
    node3 = (struct node *) malloc(sizeof(struct node));
    node1->data = (int *) malloc(sizeof(int));
    node2->data = (int *) malloc(sizeof(int));
    node3->data = (int *) malloc(sizeof(int));

    head = node1;

    *(int *)(node1->data) = 1;
    node1->next = node2;

    *(int *)(node2->data) = 2;
    node2->next = node3;

    *(int *)(node3->data) = 3;
    node3->next = NULL;


    newdata = (int *)malloc(sizeof(int));
    *(int *)newdata = 0;
    add_front(&head, newdata);
    print_list(head);

    return 0; 
}

void print_list(struct node *head)
{
    struct node *temp = head;
    printf("Nodes data in the list:\n\t");
    while(temp){
        printf("%d\t", *(int *)(temp->data));
        temp = temp->next;
    }
    printf("\n");
}

void add_front(struct node **head, void *data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    new_node->next = *head ;
    *head = new_node;
}
