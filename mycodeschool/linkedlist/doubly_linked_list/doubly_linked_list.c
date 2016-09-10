#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int insert_node_start(struct node **, int);
struct node *create_new_node(int);
void print_list(struct node *);
void print_list_rev(struct node *);

int main()
{
    int numofnodes, data_value, i;
    struct node *head = NULL;
    printf("Input Number of Node\n");
    scanf("%d", &numofnodes);
    for(i = 1; i <= numofnodes; i++){
        printf("Input data for node number = %d\n", i);
        scanf("%d", &data_value);
        insert_node_start(&head, data_value);
    }
    print_list_rev(head);
    return 0;
}

int insert_node_start(struct node **head, int data_value)
{
    struct node *new_node;
    new_node = create_new_node(data_value);
    if(!new_node){
        return 1;
    }
    if(!(*head)){
        *head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        print_list(*head);
        return 0;
    }else{
        new_node->next = *head;
        (*head)->prev = new_node;
        new_node->prev = NULL;
        *head = new_node;
    }
    print_list(*head);
    return 0;
}

void print_list(struct node *p)
{
    printf("LIST::\t");
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void print_list_rev(struct node *p)
{
    while(p->next != NULL){
        p = p->next;
    }
    printf("LIST::\t");
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->prev;
    }
    printf("\n");
}

struct node *create_new_node(int data_value)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if(!new_node){
        printf("System does not have enough memory, Failed to allocate memory to node\n");
        return NULL;
    }
    new_node->data = data_value;
    return new_node;
}
