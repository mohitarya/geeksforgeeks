#include <stdio.h>
#include <stdlib.h>


struct node {
    void *data;
    struct node *next;
};

void print_list(struct node *);

int main()
{
    struct node *node1, *node2, *node3, *head;

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
