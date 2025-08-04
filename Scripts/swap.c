// A swap function for any data type.

typedef int flex_t;

void swap(flex_t *p1, flex_t *p2);

void swap(flex_t *p1, flex_t *p2) {
    flex_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}