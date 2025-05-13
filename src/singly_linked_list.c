#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

/* Local functions prototypes */
static Node *List_node_create(int value);

/* Function to initialize the list with NULL (empty list)
   It receives a reference to the list */
void List_init_empty(List *list){
  
  if(list==NULL)
    return;

  list->head = list->tail = NULL;
}

/* Function to print the list
   It receives a reference to the list */
void List_print(List *list){

  if(list==NULL)
    return;

  if(List_is_empty(list)){
    return;
  }
  
  Node *tmp = list->head;

  printf("List = ");
  while(tmp!=NULL){
    if(tmp->next!=NULL)
      printf("%d - ", tmp->value);
    else
      printf("%d\n", tmp->value);
    tmp = tmp->next;
  }
}

/* Function to find the first node with a specific value
   It returns a pointer to the node found, or NULL in case of not finding
   It receives a reference to the list and the value of the node to find */
Node *List_find(List *list, int value_of_node){

  if(list==NULL)
    return NULL;

  Node *node = list->head;

  while(node!=NULL){
    
    if(node->value==value_of_node)
      return node;

    node = node->next;
  }

  return node; // Will be NULL
}

/* Function to tell whether the list is empty or not
   It returns 0 if is not empty and 1 if it is empty
   It receives a reference to the list */
int List_is_empty(List *list){

  if(list==NULL)
    return 1;

  return list->head == NULL;
}

/* Function to create a new node
   It returns a pointer to the new node
   It receives the value to assign to the new node */
static Node *List_node_create(int value){

  Node *new_node = malloc(sizeof(Node));
  if(new_node==NULL)
    return NULL;

  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

/* Function to free the list
   It receives a reference to the list to free */
void List_free(List *list){

  if(list==NULL)
    return;

  if(List_is_empty(list)){
    return;
  }
  
  Node *tmp = list->head;

  while(list->head!=NULL){
    list->head = (list->head)->next;
    free(tmp);
    tmp = list->head;
  }

  list->head = NULL;
  list->tail = NULL;
}

/* Function to delete the first ocurrence of a node with node_value in the list
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value of the node to delete */
int List_remove(List *list, int node_value){

  if(list==NULL)
    return 1;

  // Case empty list
  if(List_is_empty(list)){
    return 1;
  }

  Node *node_to_delete = List_find(list, node_value);
  if(node_to_delete==NULL) // If the node doesnt exist
    return 1;

  Node *tmp = list->head;

  // If the node to delete is the head and there is more nodes than the head
  if(node_to_delete==list->head && (list->head)->next!=NULL){
    tmp = (list->head)->next;
    free(list->head);
    list->head = tmp;
    return 0;
  }
  // If the node to delete is the head and only it
  else if(node_to_delete==list->head && (list->head)->next==NULL){
    free(list->head);
    list->head = list->tail = NULL;
    return 0;
  }

  // Find the previous node to the one that will be deleted
  while(tmp->next!=node_to_delete){
    tmp = tmp->next;
  }

  // If the node to delete is the tail
  if(node_to_delete==list->tail){
    tmp->next = NULL;
    list->tail = tmp;
    free(node_to_delete);
    return 0;
  }

  tmp->next = node_to_delete->next;
  free(node_to_delete);
  
  return 0;
}

/* Function to delete the first ocurrence of a node with node_value in the list and everything before
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value of the node to delete */
int List_truncate_before(List *list, int node_value){

  if(list==NULL)
    return 1;

  // Case empty list
  if(List_is_empty(list)){
    return 1;
  }  

  Node *node_to_delete_before = List_find(list, node_value);
  if(node_to_delete_before==NULL)
    return 1;
  
  // In case the node to delete is the tail
  if(node_to_delete_before==list->tail){
    List_free(list);
    return 0;
  }
  
  // Delete every node before the chosen node
  while(list->head!=node_to_delete_before){
    List_remove(list, (list->head)->value);
  }
  List_remove(list, (list->head)->value); // In order to delete the chosen node

  return 0;
}

/* Function to delete the first ocurrence of a node with node_value in the list and everything after
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value of the node to delete */
int List_truncate_after(List *list, int node_value){

  if(list==NULL)
    return 1;

  // Case empty list
  if(List_is_empty(list)){
    return 1;
  }  

  Node *node_to_delete_after = List_find(list, node_value);
  if(node_to_delete_after==NULL)
    return 1;
  if(node_to_delete_after==list->head){ // In case of the node to delete everything after is the head
    List_free(list);
    return 0;
  }

  Node *tmp = list->head;
  while(tmp->next!=node_to_delete_after)
    tmp = tmp->next;
  tmp->next = NULL;
  list->tail = tmp;

  tmp = node_to_delete_after;

  while(tmp!=NULL){
    tmp = node_to_delete_after->next;
    free(node_to_delete_after);
    node_to_delete_after = tmp;
  }

  return 0;
}

/* Function to append a item in the list
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value to append */
int List_push_back(List *list, int value){

  if(list==NULL)
    return 1;

  Node *new_node = List_node_create(value);
  if(new_node==NULL)
    return 1;
  
  if(List_is_empty(list)){
    list->head = list->tail = new_node;
    return 0;
  }

  (list->tail)->next = new_node;
  list->tail = new_node;

  return 0;
}

/* Function to push an item to the front of the list (item will be the new head)
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list and the value to push */
int List_push_front(List *list, int value){

  if(list==NULL)
    return 1;

  Node *new_node = List_node_create(value);
  if(new_node==NULL)
    return 1;
  
  if(List_is_empty(list)){
    list->head = list->tail = new_node;
    return 0;
  }

  new_node->next = list->head;
  list->head = new_node;

  return 0;
}

/* Function to insert an item in the middle of the list
   It returns a int (0 = success, 1 = fail)
   It receives a reference to the list, the value of the node to insert after and the value to assign to the new node */
int List_insert_after(List *list, int value_to_insert_after, int value_of_new_node){

  if(list==NULL)
    return 1;

  Node *tmp = List_find(list, value_to_insert_after);
  if(tmp==NULL) // Value not found
    return 1;

  Node *new_node = List_node_create(value_of_new_node);
  if(new_node==NULL)
    return 1;

  if(tmp==list->tail){
    new_node->next = NULL;
    tmp->next = new_node;
    list->tail = new_node;
    return 0;
  }

  new_node->next = tmp->next;
  tmp->next = new_node;

  return 0;
}