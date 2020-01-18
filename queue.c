/***********
 * Sara Spagnoletto
 * 556693885
 * 01
 * ass05
 ***********/



#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//** initQueue **//
Queue* initQueue() {
    // initializing queque
    Queue* queue = (Queue*)malloc(sizeof(queue));
    if (queue==NULL) {
        printf ("Queue: initQueue: Heap memory error!");
        return NULL;
    }
    
    // initializing s1 and s2
    queue->s1 = initStack();
    if (queue->s1==NULL) {
        printf("Queue: initQueue: Heap memory error!");
        // freeing the old queue if it filed
        free(queue);
        return NULL;
    }
    queue->s2 = initStack();
    if (queue->s2==NULL) {
        printf("Queue: initQueue: Heap memory error!");
        // freeing the old queue and the old s1 if it failed 
        free(queue);
        destroyStack(queue->s1);
        return NULL;
    }
    return queue;
}

//** initQueue **//
void destroyQueue(Queue* queue) {
    // freeing all located memory
    free(queue);
    destroyStack(queue->s1);
    destroyStack(queue->s2);
}


//** isQueueEmpty **//
int isQueueEmpty(Queue* queue) {
    if (queue->s1->topIndex==-1 && queue->s1->size==1)  {
        return 1;
    }
    else return 0;
}


//** lenOfQueue **//
int lenOfQueue(Queue* queue) {
    return (queue->s1->topIndex + 1);
}

//** capacityOfQueue **//
int capacityOfQueue(Queue* queue) {
  return queue->s1->size;
}

//** ENQUEUE **//
void enqueue(Queue* queue, Element element){
    push(queue->s1, element);
}

/* INVERT
 Input : stack from, stack to
 The function receives a stack from a stack to, and copied the element in stack from, in ineverse order, inside stack to, by doing this it empies stack from
 */
void invert (Stack* from, Stack* to) {
    if (isStackEmpty(to)) {
        while (!(isStackEmpty(from))) {
            push(to,top(from));
            pop(from);
        }
    }
}

//** DEQUEUE **//
Element dequeue(Queue* queue){
    Element result;
    // inverting the stacks
    invert(queue->s1, queue->s2);
    // setting result equale to the top of stack 2, and poppint the top of stack 2
    result = pop(queue->s2);
    // reinvertinf again
    invert(queue->s2, queue->s1);
    return result;
}


//** PEEK **//
Element peek(Queue* queue) {
    Element result;
    // inverting
    invert(queue->s1, queue->s2);
    // setting result equal to the top of stack 2
    result = top(queue->s2);
    // reinverting again
    invert(queue->s2, queue->s1);
    return result;
}









