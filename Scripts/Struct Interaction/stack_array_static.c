/*
A stack structure implemented with a static array along with its operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100

typedef int data_t;

typedef struct {
    data_t data[MAX_SIZE];
    int top;
} stack_t;

void init_stack(stack_t *s) {
    s->top = -1;
}

int is_empty(stack_t *s) {
    return s->top == -1;
}

int is_full(stack_t *s) {
    return s->top == MAX_SIZE - 1;
}

void push(stack_t *s, data_t value) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
}

data_t pop(stack_t *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return;
    }
    return s->data[(s->top)--];
}

data_t peek(stack_t *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    return s->data[s->top];
}