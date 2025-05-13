#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Function to initialize the stack with NULL (empty stack)
   It receives a reference to the stack */
void Stack_init_empty(Stack *stack){
  
  List_init_empty(&(stack->data));
}

/* Function to insert an element in the top of the stack
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the stack and the value of the element */
int Stack_push(Stack *stack, int value){

  return List_push_front(&(stack->data), value);
}

/* Function to remove the element of the top of the stack
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the stack and a reference to an int variable to assign the element popped */
int Stack_pop(Stack *stack, int *value_popped){

  if(Stack_is_empty(stack))
    return 1;

  Node *head = stack->data.head;
  Node *tail = stack->data.tail;
  *value_popped = head->value;

  if(head==tail){
    free(head);
    stack->data.head = stack->data.tail = NULL;
    return 0;
  }

  Node *tmp = head;

  head = head->next;
  stack->data.head = head;
  free(tmp);

  return 0;
}

/* Function to return the value of the element of the top of the stack 
   It returns 0 in case of success and 1 in case of error 
   It receives a reference to the stack and a reference to an int variable to assign the element peeked */
int Stack_peek(Stack *stack, int *value){

  if(Stack_is_empty(stack))
    return 1;
  
  *value = stack->data.head->value;
  return 0;
}

/* Function to tell whether the stack is empty or not
   It returns 0 if is not empty and 1 if it is empty
   It receives a reference to the stack */
int Stack_is_empty(Stack *stack){

  return List_is_empty(&(stack->data));
}

/* Function to destroy the stack, freeing the memory
   It receives a reference to the stack */
void Stack_destroy(Stack *stack){

  List_free(&(stack->data));
}

