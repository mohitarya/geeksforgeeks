#ifndef __SINGLY_LINKED_LIST__
#define __SINGLY_LINKED_LIST__

// Singly list Node structure for a node
typedef struct node {
  void *data;
  struct node *next;
} Node;

// Defining an Enum for insert operations

enum insert {
  front,
  end,
  after_node,
  before_node,
  point,
};

enum delete {
  del_front,
  del_end,
  del_node,
};

#endif
