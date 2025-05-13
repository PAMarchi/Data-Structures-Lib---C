#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/* Struct defining the node type 
   Represents the elements of the list */
typedef struct node{

  int value;
  struct node *next;
} Node;

/* Struct that defines the List
   as having a head and a tail */
typedef struct{

  Node *head;
  Node *tail;
} List;

/* Function to initialize the list with NULL (empty list)
   It receives a reference to the list */
void List_init_empty(List *list);

/* Function to find the first node with a specific value
   It returns a pointer to the node found, or NULL in case of not finding
   It receives a reference to the list and the value of the node to find */
Node *List_find(List *list, int value_of_node);

/* Function to free the list
   It receives a reference to the list to free */
void List_free(List *list);

/* Function to append a item in the list
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value to append */
int List_push_back(List *list, int value);

/* Function to push an item to the front of the list (item will be the new head)
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value to push */
int List_push_front(List *list, int value);

/* Function to insert an item in the middle of the list
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list, the value of the node to insert after and the value to assign to the new node */
int List_insert_after(List *list, int value_to_insert_after, int value_of_new_node);

/* Function to delete the first ocurrence of a node with node_value in the list
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value of the node to delete */
int List_remove(List *list, int node_value);

/* Function to delete the first ocurrence of a node with node_value in the list and everything before
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value of the node to delete */
int List_truncate_before(List *list, int node_value);

/* Function to delete the first ocurrence of a node with node_value in the list and everything after
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value of the node to delete */
int List_truncate_after(List *list, int node_value);

/* Function to print the list
   It receives a reference to the list */
void List_print(List *list);

/* Function to tell whether the list is empty or not
   It returns 0 if is not empty and 1 if it is empty
   It receives a reference to the list */
int List_is_empty(List *list);

#endif