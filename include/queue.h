#ifndef QUEUE_H
#define QUEUE_H

#include "singly_linked_list.h"

/* Struct defining the Queue type */
typedef struct{
  List data;
} Queue;

/* Function to initialize the queue with NULL (empty queue)
   It receives a reference to the queue */
void Queue_init_empty(Queue *queue);

/* Function to insert an element at the end of the queue
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the queue and the value of the element */
int Queue_enqueue(Queue *queue, int value);

/* Function to dequeue the first element of the queue
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the queue and a reference to an int variable to assign the element dequeued */
int Queue_dequeue(Queue *queue, int *value_dequeued);

/* Function to return the value of the element of the front (head) of the queue 
   It returns 0 in case of success and 1 in case of error 
   It receives a reference to the queue and a reference to an int variable to assign the element peeked */
int Queue_peek_front(Queue *queue, int *value);

/* Function to return the value of the element of the back (tail) of the queue 
   It returns 0 in case of success and 1 in case of error 
   It receives a reference to the queue and a reference to an int variable to assign the element peeked */
int Queue_peek_back(Queue *queue, int *value);

/* Function to tell whether the queue is empty or not
   It returns 0 if is not empty and 1 if it is empty
   It receives a reference to the queue */
int Queue_is_empty(Queue *queue);

/* Function to destroy the queue, freeing the memory
   It receives a reference to the queue */
void Queue_destroy(Queue *queue);

#endif