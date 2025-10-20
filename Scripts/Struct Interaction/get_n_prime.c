#include <stdio.h>
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
} linked_list_t;

int is_prime(int n);

linked_list_t *create_empty_list();

void insert_at_foot(linked_list_t *mylist, data_t new);
void print_list(linked_list_t *mylist);
void free_list(linked_list_t *mylist);

int 
main(int argc, char *argv[]) {
    int n;
    // 1
    linked_list_t *mylist;
    mylist = create_empty_list();

    printf("Enter a number n: ");
    scanf("%d", &n);

    int i = 2;
    while (i < n) {
        if (is_prime(n)) {
            // 3
            insert_at_foot(mylist, i);
        }
        i++;
    }
    // 6
    print_list(mylist);
    free_list(mylist);

    // 8
    mylist = NULL;
    return 0;
}

void
free_list(linked_list_t *mylist) {
    node_t *new;
    while (mylist->head) {
        printf("freeing\n");
        new = mylist->head;
        mylist->head = mylist->head->next;
        free(new);
    }
    mylist->head = mylist->foot = NULL;

    free(mylist);
    // 7
    // mylist = NULL;
}

void
print_list(linked_list_t *mylist) {
    if (mylist->head) {
        node_t *new = mylist->head;

        while (new) {
            printf("%d ", new->data);
            new = new->data;
        }
        printf("\n");
    }
}

// 2
linked_list_t 
*create_empty_list() {
    linked_list_t *mylist = (linked_list_t *) malloc(1*sizeof(linked_list_t));

    assert(mylist);

    mylist->head  = mylist->foot = NULL;

    return mylist;
}

void
insert_at_foot(linked_list_t *mylist, data_t new_item) {
    node_t *new = (node_t *) malloc(1*sizeof(node_t));
    // 4
    if (new == NULL) {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }

    // 5
    new->data = new_item;
    new->next = NULL;
    
    if (mylist->head == NULL) {
        mylist->head = mylist->foot = new;
    } else {
        mylist->foot->next = new;
        mylist->foot = new;
    }
}