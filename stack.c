/***********
 * Sara Spagnoletto
 * 556693885
 * 01
 * ass05
 ***********/



#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "stack.h"

//** initStack **//
Stack* initStack() {
    // initializing stack
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    // checking if it failed to initialize
    if (stack==NULL) {
        printf ("Stack: initStack: Heap memory error!");
        return NULL;
    }
    // inizializing size to 1
    stack->size = 1;
    // inizializing content
    stack->content = (Element*)malloc(sizeof(Element)*stack->size);
    // checking it it failed to initilize
    if (stack->content==NULL) {
        printf ("Stack: initStack: Heap memory error!");
        // freeing the old stack
        free(stack);
        return NULL;
    }
    
    //setting top index to -1
    stack->topIndex = -1;
    
    return stack;
}

//** destroyStack **//
void destroyStack(Stack* stack) {
    // freeing all alocated memory
    free(stack);
    free(stack->content);
}

//** isStackEmpty **//
int isStackEmpty (Stack* stack) {
    // checking if the stack has empty charathristics
    if (stack->topIndex==-1 && stack->size==1) {
        return 1;
    }
    else return 0;
}

//** lenOfStack **//
int lenOfStack (Stack* stack) {
    return (stack->topIndex + 1);
}

//** capacityOfStack **//
int capacityOfStack (Stack* stack) {
  return stack->size;
}

//** PUSH **//
void push(Stack* stack, Element element) {
    // setting the element at place ++topIndex inside the stack content array
    stack->content[++stack->topIndex] = element;
    
    // if the stack has full stack features (if the stakc is full)
    if (stack->topIndex == stack->size - 1) {
        //reallocating an array of size * 2
        stack->content = (Element*)realloc(stack->content, sizeof(Element) * stack->size*2);
        // checking if failed to initialize
        if (stack->content==NULL) {
            printf ("Stack: push: Heap memory error!");
        }
        // stack size moltiplied by 2
        else stack->size *= 2;
    }
}

//** POP **//
Element pop(Stack* stack) {
    // setting result equal to topIdex, and decreasing topIndex by 1
    Element result = stack->content[stack->topIndex--];
    // if the stack is not empty
    if (!(isStackEmpty(stack))) {
        // and if we are using half or less than half ot the size space
        if ((stack->topIndex+1)*2 <= (stack->size)) {
            // reallocatinf an array fo size/2
            stack->content = (Element*)realloc(stack->content, sizeof(Element) * stack->size/2);
            // checking if it failed to initialize
            if (stack->content==NULL) {
                printf ("Stack: pop: Heap memory error!");
            }
            // else divding the size
            else stack->size /= 2;
        }
    }
    return result;
}

//** TOP **//
Element top(Stack* stack) {
    // returning the topIndex
    return stack->content[stack->topIndex];
}

//** printStack **//
void printStack(Stack* stack) {
    // creating a temp to store the topIndex value
    int temp=stack->topIndex;
    // while the topIndex is not -1 (till the stack is empty basically)
    while (stack->topIndex != -1) {
        // print the number of the index (+1)
        printf("%d: ",stack->topIndex+1);
        // print the current element
        printElement(top(stack));
        printf ("\n");
        // decresing each time index by 1
        stack->topIndex--;
    }
    // restoring the actual topIndex to normal
    stack->topIndex=temp;
}


