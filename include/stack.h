#ifndef STACK_H
#define STACK_H

#include "singly_linked_list.h"

/* Struct defining the Stack type */
typedef struct{
  List data;
} Stack;

/* Function to initialize the stack with NULL (empty stack)
   It receives a reference to the stack */
void Stack_init_empty(Stack *stack);

/* Function to insert an element in the top of the stack
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the stack and the value of the element */
int Stack_push(Stack *stack, int value);

/* Function to remove the element of the top of the stack
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the stack and a reference to an int variable to assign the element popped */
int Stack_pop(Stack *stack, int *value_popped);

/* Function to return the value of the element of the top of the stack 
   It returns 0 in case of success and 1 in case of error 
   It receives a reference to the stack and a reference to an int variable to assign the element peeked */
int Stack_peek(Stack *stack, int *value);

/* Function to tell whether the stack is empty or not
   It returns 0 if is not empty and 1 if it is empty
   It receives a reference to the stack */
int Stack_is_empty(Stack *stack);

/* Function to destroy the stack, freeing the memory
   It receives a reference to the stack */
void Stack_destroy(Stack *stack);

#endif