#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
OBJ* swap(OBJ* top, OBJ* one, OBJ* two) {
    OBJ* A = stack();
    OBJ* current = top;
    while (current != one) {
        A = push(A, current->data);
        current = current->next;
    }
    int one_data = current->data;
    current = current->next;
    A = push(A, current->data);
    OBJ* tail = current->next;
    OBJ* p = top;
    while (p != tail) {
        OBJ* nxt = p->next;
        free(p);
        p = nxt;
    }
    top = tail;
    top = push(top, one_data);
    while (A) {
        OBJ* next = A->next;
        top = push(top, A->data);
        free(A);
        A = next;
    }
    return top;
}
OBJ* sort_direct_connection(OBJ* top) {
    OBJ* sort = NULL;
    while (top) {
        int x = top->data;
        OBJ* t = top;
        top = top->next;
        free(t);
        OBJ* time = NULL;
        while (sort && sort->data < x) {
            time = push(time, sort->data);
            t = sort;
            sort = sort->next;
            free(t);
        }

        sort = push(sort, x);
        while (time) {
            sort = push(sort, time->data);
            t = time;
            time = time->next;
            free(t);
        }
    }
    return sort;
}