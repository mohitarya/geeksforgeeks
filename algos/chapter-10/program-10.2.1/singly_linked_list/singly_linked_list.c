#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "singly_linked_list.h"

/*
 * Function: add_before_node
 * ..........................
 * Insert the node before the node when key matches
 *
 * head: pointer to head pointer
 * node: pointer to node need to add
 * key: pointer to before node need to add
 *
 * return: 0 on success
 *         Not 0 if Error
 */
int add_before_node(Node **head, Node *node, void *key)
{
  Node *temp = (*head);
  Node *prev = NULL;
  if(temp == NULL){
    printf("Failed to add new node to list, List is not initialized\n");
    return -1;
  }
  while(temp != NULL){
    if(*((int *)temp->data) == *((int *)key)){
      if(prev != NULL){
	prev->next = node;
	node->next = temp;
      }else{
	node->next = temp;
	*head = node;
      }
      return 0;
    }
    prev = temp;
    temp = temp->next;
  }
  return -1;
}

/*
 * Function: add_after_node
 * ..........................
 * Insert the node after the whose key match with key
 *
 * head: pointer to head pointer
 * node: pointer to node need to add
 * key: pointer to after node need to add
 *
 * return: 0 on success
 *         Not 0 if Error
 */

int add_after_node(Node **head, Node *node, void *key)
{
  Node *temp = (*head);
  if(temp == NULL){
    printf("Linked list is not initialized, Can not add\n");
    return -1;
  }
  while(temp != NULL){
    if(*((int *)temp->data) == *((int *)key)){
      node->next = temp->next;
      temp->next = node;
      return 0;
    }
    temp = temp->next;
  }
  return -1;
}
/*
 * Function: end_of_list
 * ..........................
 * Insert the node at end of list
 *
 * head: pointer to head pointer
 * node: pointer to node need to add
 *
 * return: 0 on success
 *         Not 0 if Error
 */
int end_of_list(Node **head, Node *node)
{
  Node *temp = (*head);
  // When the List is empty
  if(temp == NULL){
    temp = node;
    *head = temp;
    return 0;
  }
  // Traversing till the last node
  while(temp->next != NULL){
    temp = temp->next;
  }
  // Now pointer at the last node
  temp->next = node;
  return 0;
}

/*
 * Function: front_of_list
 * ..........................
 * Insert the node at front of the list
 *
 * head: pointer to head pointer
 * node: pointer to node need to add
 *
 * return: 0 on success
 *         Not 0 if Error
 */

int front_of_list(Node **head, Node *node)
{
  Node *temp = (*head);
  if(temp){
    // new node next will point to the current head;
    node->next = temp;
  }
  temp = node;
  *head = temp;
  return 0;
}

/*
 * Function: create_node
 * ..........................
 * Create a new node
 *
 * data: pointer to data
 *
 * return: Success - Pointer to new node
 *         Failed - NULL
 */
Node *create_node(void *data)
{
  Node *new_node;
  new_node = (Node *) malloc(sizeof(Node));
  if(!new_node){
    printf("Out of memory\n");
    return NULL;
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

/*
 * Function: insert
 * ..........................
 * Insert the node to the linked list Following are the
 * options available
 * - front: Insert front of the list
 * - end: Insert at end of list
 * - after_node: Insert node after the key node
 * - before_node: Insert node before the key node
 * - point: Insert node a perticular position
 * 
 * return: 0 on success
 *         Not 0 if Error
 */

insert(Node **head, int option, void *key, void *data)
{
  int ret, ret_val = 0;
  Node *new_node;
  
  // Create a new node to add
  new_node = create_node(data);
  if(new_node == NULL){
    printf("Failed to create a Node\n");
    ret_val = ENOMEM;
    goto error; 
  }

  switch(option){
  case front:
    ret = front_of_list(head, new_node);
    break;
  case end:
    ret = end_of_list(head, new_node);
    break;
  case after_node:
    ret = add_after_node(head, new_node, key);
    break;
  case before_node:
    ret = add_before_node(head, new_node, key);
    break;
  case point:
    break;
  default:
    printf("Wrong Input Option\n");
    ret_val = EPERM;
    break;
  }
  if(ret != 0){
    printf("Failed to add to the list\n");
    ret_val = ret;
    goto error;
  }
  
  return ret_val;
 
 error:
  if(new_node){
    free(new_node);
    new_node = NULL;
  }
  return ret_val;
}

/*
 * Function: print
 * ..........................
 * print the current list 
 *
 * head: pointer to head
 *
 */
void print(Node *head)
{
  Node *temp = head;
  printf("Current List is\n\t\t");
  while(temp != NULL){
    printf("%d\n\t\t", *(int *)(temp->data));
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  Node *head = NULL;
  int *data1, *data2, *data3, *data4, *data5, *data6, *data7;
  data1 = (int *) malloc(sizeof(int));
  data2 = (int *) malloc(sizeof(int));
  data3 = (int *) malloc(sizeof(int));
  data4 = (int *) malloc(sizeof(int));
  data5 = (int *) malloc(sizeof(int));
  data6 = (int *) malloc(sizeof(int));
  data7 = (int *) malloc(sizeof(int));
  *data1 = 5;
  *data2 = 10;
  *data3 = 15;
  *data4 = 20;
  *data5 = 25;
  *data6 = 50;
  // Calling to add the Node in the list
  insert(&head, front, NULL, data1);
  insert(&head, front, NULL, data2);
  insert(&head, end, NULL, data3);
  insert(&head, end, NULL, data4);
  *data7 = 10;
  //insert(&head, after_node, data7, data5);
  insert(&head, before_node, data7, data5);
  *data7 = 20;
  //insert(&head, after_node, data7, data6);
  insert(&head, before_node, data7, data6);
  print(head);
  return 0;
} 
