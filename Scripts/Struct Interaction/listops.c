#include <stdlib.h>
#include <assert.h>

typedef int data_t;

typedef struct node node_t;

struct node {
    data_t data;
    node_t *next;
};

typedef struct {
    node_t *head;
    node_t *foot;
} list_t;

list_t 
*make_empty_list() {
    list_t *list = (list_t *) malloc(1*sizeof(list_t));

    assert(list != NULL);

    list->head = list->foot = NULL;

    return list;
}

int
is_empty(list_t *list) {
    assert(list != NULL);
    return list->head == NULL;
}

void
free_list(list_t *list) {
    node_t *curr, *prev;
    assert(list != NULL);
    curr = list->head;
    while (curr) {
        printf("freeing\n");
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(list);
}

list_t
*insert_at_head(list_t *list, data_t value) {
    node_t *new;
    // 1
    new = (node_t *) malloc(sizeof(*new));

    assert(list != NULL && new != NULL);
    
    new->data = value;
    new->next = list->head;

    list->head = new;

    // First insertion: The inserted node becomes the head and foot.
    if (list->foot == NULL) {
        list->foot = new;
    }
    return list;
}

list_t
*insert_at_foot(list_t *list, data_t value) {
    node_t *new;

    new = (node_t *) malloc(sizeof(*new));

    assert(list != NULL && new != NULL);
    
    new->data = value;
    new->next = NULL;

    // First insertion: The inserted node becomes the head and foot.
    if (list->foot == NULL) {
        list->head = list->foot = new;
    } else {
        list->foot->next = new;
        list->foot = new;
    }
    return list;
}

    // Get data of the head node;
data_t
get_head(list_t *list) {
    assert(list != NULL && list->head != NULL);
    return list->head->data;
}

list_t
*get_tail(list_t *list) {
    // 2
    node_t *oldhead;
    assert(list != NULL  && list->head != NULL);
    oldhead = list->head;
    list->head = list->head->next;
    if (list->head == NULL) {
        list->foot = NULL;
    }

    free(oldhead);
    return list;
}