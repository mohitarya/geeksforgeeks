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
    int size, key;

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

    add_listend(&head, newdata);

    add_in_list(&head, 50, newdata);

    print_list(head);

    key = 0;

    delete_node(&head, key);

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

add_listend(struct node **head, void *data)
{
    struct node *temp = *head;
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;   
}

add_in_list(struct node **head, int node_no, void *data)
{
    //if node number is 0 then add node at the front of the list
    //if node number is last node or beyond the list then add the node at the last
    //if node number is elsewhere then add the node after the specified number

    struct node *temp = *head;
    struct node *newnode;
    int i=1, flag = 0;

    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    if (node_no == 0){
        add_front(head, data);
    } else {
        while(i != node_no){
            if(temp->next == NULL){
                temp->next = newnode;
                newnode->next == NULL;
                flag = 1;
                break;
            }else {
                temp = temp->next;
                i++;
            }
        }
        if(flag != 1){
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

delete_node(struct node **head, int key)
{
    struct node *temp = *head, *temp_prev = *head;
    while(temp){
        if(*(int *)(temp->data) == key){
            if(temp == *head){
                *head = (*head)->next;
            }else {
                temp_prev->next = temp->next;
            }
            goto free;
        }else {
            temp_prev = temp;
            temp = temp->next;
        }
    }
    printf("Key is not present in the list\n");

free:
    if(temp){
        if(temp->data){
            free(temp->data);
            temp->data = NULL;
        }
        temp->next = NULL;
    }
}
