#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_list_start(struct node **, int);
void print_list(struct node *);
int insert_node_n_position(struct node **, int , int );
void print_list_rec(struct node *);
void print_list_rec_reverse(struct node *);
void reverse_list_rec(struct node *, struct node **);

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
    //insert_node_n_position(&head, 50, 1);
    //insert_node_n_position(&head, 12, 3);
    //insert_node_n_position(&head, 55, 7);
    //delete_node_n_position(&head, 1);
    //delete_node_n_position(&head, 3);
    //reverse_iterative(&head);
    //print_list(head);
    //printf("Print List using recurrsion, LIST:::\t");
    //print_list_rec(head);
    //printf("\n");
    //printf("Print List reverse order using recurrsion, LIST:::\t");
    //print_list_rec_reverse(head);
    //printf("\n");
    reverse_list_rec(head, &head);
    print_list(head);
}

void reverse_list_rec(struct node *p, struct node **head)
{
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverse_list_rec(p->next, head);
    struct node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void print_list_rec(struct node *p)
{
    if(p == NULL){
        return;
    }
    printf("%d\t", p->data);
    print_list_rec(p->next);
}

void print_list_rec_reverse(struct node *p)
{
    if(p == NULL){
        return;
    }
    print_list_rec_reverse(p->next);
    printf("%d\t", p->data);
}
int reverse_iterative(struct node **head)
{
    struct node *current, *prev, *next;
    if(*head == NULL || (*head)->next == NULL){
        return;
    }
    current = *head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int insert_node_n_position(struct node **head, int element, int position)
{
    struct node *new_node;
    int i = 1;
    struct node *temp = *head;
    // Create a new Node
    new_node = (struct node *) malloc(sizeof(struct node));
    if(!new_node){
        printf("Not enough memory to create a node\n");
        return 1;
    }
    new_node->data = element;
    // If node need to be inserted at position 1
    if(position == 1){
        new_node->next = *head;
        *head = new_node;
        print_list(*head);
        return 0;
    }
    // Node need to be inserted at any position
    for(i = 1; i < (position - 1); i++){
        if(temp == NULL){
            break;
        }
        temp = temp->next;
    }
    if(temp){
        new_node->next = temp->next;
        temp->next = new_node;
        print_list(*head);
        return 0;
    }else
        printf("position %d is out of scope\n", position);
        return -1;
}

int delete_node_n_position(struct node **head, int position)
{
    struct node *temp = *head, *temp1;
    int i;
    if(position == 1){
        *head = temp->next;
        free(temp);
    }else{
        for(i = 1; i < (position - 1); i++){
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
    print_list(*head);
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
