/*
A doubly linked list has each node know the left and right nodes. This file contains basic operations and initialization of such structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int data_t;

typedef struct node node_t;

struct node {
    data_t data;
    node_t *prev;
    node_t *next;
};

typedef struct {
    node_t *head;
    node_t *tail;
} list_t;


list_t *init_list() {
    list_t *list;
    list = malloc(sizeof(*list));
    assert(list);
    list->head = NULL;
    list->tail = NULL;
    return list;
}

node_t *init_node() {
    node_t *new_node;
    new_node = malloc(sizeof(*new_node));
    assert(new_node);
    return new_node;
}

void insert_head(list_t *list, data_t value) {
    node_t *new_node = init_node();

    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }

    list->head = new_node;
}

void insert_tail(list_t *list, data_t value) {
    node_t *new_node = init_node();

    new_node->data = value;
    new_node->prev = list->tail;
    new_node->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }

    list->tail = new_node;
}

// pop()
data_t remove_head(list_t *list) {
    assert(list && list->head);

    node_t *temp = list->head;
    data_t value = temp->data;

    list->head = temp->next;
    
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    free(temp);
    return value;
}

data_t remove_tail(list_t *list) {
    assert(list);

    node_t *temp = list->tail;
    data_t value = temp->data;

    list->tail = temp->prev;

    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    free(temp);
    return value;
}

// Traversal
void print_forward(list_t *list) {
    node_t *curr = list->head;
    printf("List (forward): ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void print_backward(list_t *list) {
    node_t *curr = list->tail;
    printf("List (backward): ");
    while (curr != NULL) {
        printf("%d ", curr->prev);
        curr = curr->prev;
    }
    printf("\n");
}
//--

// Free
void free_list(list_t *list) {
    node_t *curr = list->head;

    while (curr != NULL) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }

    list->head = NULL;
    list->tail = NULL;
    // Don't forget to free the list in the caller function!	
}