/*
A stack structure implemented with a dynamic array along with its operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int data_t;

typedef struct {
	data_t *data;
	data_t top;
	int capacity;
} stack_t;

// make_empty_stack()
void init_stack(stack_t *s, int capacity) {
	s->data = malloc(sizeof(*(s->data)) * capacity);
	assert(s->data);

	s->top = -1;
	s->capacity = capacity;
}

int is_empty(stack_t *s) {
	return s->top == -1;
}

int is_full(stack_t *s) {
	return s->top == s->capacity - 1;
}

void push(stack_t *s, data_t value) {
	if (is_full(s)) {
		s->capacity *= 2;
		int *new_data = realloc(s->data, sizeof(*(s->data))*s->capacity);
		assert(new_data);
	
		s->data = new_data;
		printf("Resized stack to capacity %d", s->capacity);
	}
	s->data[++(s->top)] = value;
}

int pop(stack_t *s) {
	if (is_empty(s)) {
		printf("Stack underflow!\n");
		return -1; // Sentinel value
	}
	return s->data[(s->top)--];
}

int peek(stack_t *s) {
	if (is_empty(s)) {
		printf("Stack is empty!\n");
		return -1;
	}
	return s->data[s->top];
}

void free_stack(stack_t *s) {
	free(s->data);
	s->data = NULL;
	s->top = -1;
	s->capacity = 0;
}