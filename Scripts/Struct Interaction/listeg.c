#include <stdio.h>
#include "listops.c"

int 
main(int argc, char *argv[]) {
    list_t *list;
    int i;
    
    list = make_empty_list();

    while (scanf("%d", &i) == 1) {
        list = insert_at_head(list, i);
        list = insert_at_head(list, i+1);
        list = insert_at_foot(list, i+2);
    }

    while (!is_empty_list(list)) {
        i = get_head(list);
        printf("%d", i);
        list = get_tail(list);
    }

    printf("\n");

    free_list(list);
    list = NULL;

    return 0;
}