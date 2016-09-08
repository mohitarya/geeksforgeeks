#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_list_start(struct node **, int);
void print_list(struct node *);
int insert_node_n_position(struct node **, int , int );

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
    insert_node_n_position(&head, 50, 1);
    insert_node_n_position(&head, 12, 3);
    insert_node_n_position(&head, 55, 7);
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
