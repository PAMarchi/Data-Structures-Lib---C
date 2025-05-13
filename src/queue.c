#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Function to initialize the queue with NULL (empty queue)
   It receives a reference to the queue */
void Queue_init_empty(Queue *queue){

  List_init_empty(&(queue->data));
}

/* Function to insert an element at the end of the queue
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the queue and the value of the element */
int Queue_enqueue(Queue *queue, int value){

  return(List_push_back(&(queue->data), value));
}

/* Function to dequeue the first element of the queue
   It returns 0 in case of success and 1 in case of error
   It receives a reference to the queue and a reference to an int variable to assign the element dequeued */
int Queue_dequeue(Queue *queue, int *value_dequeued){

  if(Queue_is_empty(queue))
    return 1;

  Node *head = queue->data.head;
  Node *tail = queue->data.tail;

  *value_dequeued = head->value;

  if(head==tail){
    free(head);
    queue->data.head = queue->data.tail = NULL;
    return 0;
  }

  Node *tmp = head;

  head = head->next;
  queue->data.head = head;
  free(tmp);
  
  return 0;
}

/* Function to return the value of the element of the front (head) of the queue 
   It returns 0 in case of success and 1 in case of error 
   It receives a reference to the queue and a reference to an int variable to assign the element peeked */
int Queue_peek_front(Queue *queue, int *value){

  if(Queue_is_empty(queue))
    return 1;

  *value = queue->data.head->value;

  return 0;
}

/* Function to return the value of the element of the back (tail) of the queue 
   It returns 0 in case of success and 1 in case of error 
   It receives a reference to the queue and a reference to an int variable to assign the element peeked */
int Queue_peek_back(Queue *queue, int *value){

  if(Queue_is_empty(queue))
    return 1;

  *value = queue->data.tail->value;

  return 0;
}

/* Function to tell whether the queue is empty or not
   It returns 0 if is not empty and 1 if it is empty
   It receives a reference to the queue */
int Queue_is_empty(Queue *queue){

  return (List_is_empty(&(queue->data)));
}

/* Function to destroy the queue, freeing the memory
   It receives a reference to the queue */
void Queue_destroy(Queue *queue){
  
  List_free(&(queue->data));
}