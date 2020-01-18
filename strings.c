/***********
 * Sara Spagnoletto
 * 556693885
 * 01
 * ass05
 ***********/

#include <string.h>
#include "strings.h"
#include "stack.h"
#include "element.h"

//** isLegalString **//

int isLegalString(char str[]) {
    // initializing a stack
    Stack* stack = initStack();
    
    Element element;
    
    // loop trough all the current string to analyze
    for (int i=0; i<strlen(str); i++) {
        // if you find an open bracket
        if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<') {
            // setting element equal to that char
            element.c = str[i];
            // pushing it inside the stack
            push(stack, element);
        }
        // if you find a closing breacket
        else if (str[i]==')') {
            // setting eleement to the equivalent closing bracket
            element.c = '(';
            // checking if the top of the stack is the the opne breacket
            if (top(stack).c == element.c) {
                // if yes, popping it out
                pop(stack);
            // if not, illgeal
            } else {
                destroyStack(stack);
                return 0;
            }
        }
        // continuing for all closet bracket cases
        else if (str[i]==']') {
            element.c = '[';
            if (top(stack).c == element.c) {
                pop(stack);
            } else {
                destroyStack(stack);
                return 0;
            }
        }
        else if (str[i]=='}') {
            element.c = '{';
            if (top(stack).c == element.c) {
                pop(stack);
            } else {
                destroyStack(stack);
                return 0;
            }
        }
        else if (str[i]=='>') {
            element.c = '<';
            if (top(stack).c == element.c) {
                pop(stack);
            } else {
                destroyStack(stack);
                return 0;
            }
        }
    }
    
    // if you arrived till here, and the stack is empty
    if (isStackEmpty(stack)) {
        // return 1
        destroyStack(stack);
        return 1;
    } else {
        destroyStack(stack);
        return 0;
    }
}
