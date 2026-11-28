#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
OBJ* reverse_stack(OBJ* top) {
    OBJ* res = NULL;
    while (top) {
        res = push(res, top->data);
        OBJ* t = top;
        top = top->next;
        free(t);
    }
    return res;
}
OBJ* merge(OBJ* one, OBJ* two) {
    OBJ* res = NULL;
    while (one && two) {
        OBJ* time;
        if (one->data <= two->data) {
            time = one;
            one = one->next;
        } else {
            time = two;
            two = two->next;
        }
        res = push(res, time->data);
        free(time);
    }
    while (two) {
            res = push(res, two->data);
            OBJ* t = two;
            two = two->next;
            free(t);
        }
    while (one) {
            res = push(res, one->data);
            OBJ* t = one;
            one = one->next;
            free(t);
        }
    return reverse_stack(res);
}

OBJ* split_and_merge(OBJ* top) {
    int n = stack_len(top);
    if (n <= 1) return top;

    int N = n / 2;
    OBJ* A = NULL;
    OBJ* B = NULL;
    const OBJ* cur = top;

    for (int i = 0; i < n; i++) {
        if (i < N) 
            A = push(A, cur->data);
        else 
            B = push(B, cur->data);
        cur = cur->next;
    }
    clean_stack(top);
    if (stack_len(A) > 1)
        A = split_and_merge(A);
    if (stack_len(B) > 1)
        B = split_and_merge(B);
    return merge(A, B);
}
