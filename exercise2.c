/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    if (s == NULL) return;
    s->head = NULL;
    /* pre-condition: true */
    /* post-condition: stack is empty */
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: s is a valid pointer */
    /* post-condition: x is added to top of stack */
    if (s == NULL) return;
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
  
        return;
    }
    new_node->data = x;
    new_node->next = s->head;
    s->head = new_node;
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */
    if (s == NULL || s->head == NULL) {

        return 0;
    }

    node *top = s->head;
    int value = top->data;
    s->head = top->next;
    free(top);
    return value;
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */
    if (s == NULL) return true;
    return (s->head == NULL);
}

/* Print the contents of the stack */
void print(stack *s)
{
node *current = s->head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */
}
