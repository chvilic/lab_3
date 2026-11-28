#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data) {
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}
OBJ* pop(OBJ* top) {
    if (top == NULL) {
        return top;
    }
    printf("Удален элемент: %d\n", top->data);
    OBJ* ptr_next = top->next;
    free(top);
    return ptr_next;
}
void show(const OBJ* top) {
    printf("\n");
    const OBJ* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
int get_num() {
    int c;
    int res_num = 0;
    int degree = 0;
    while ((c = getchar()) == ' ');
    if (c == '\n' || c == EOF)
        return -1;
    
    while (isdigit(c)) {
        res_num = res_num*10 + (c - '0');
        c = getchar();
    }
    if (c != ' ' && c != '\n' && c != EOF) {
        printf("Вы ввели что-то не то\n");
        while (c != '\n' && c != EOF) c = getchar();
        return -1;
    }
    if (c == '\n' || c == EOF) ungetc(c, stdin);
    return res_num;
}
void clean_stack(OBJ* top) {
    while (top != NULL) {
        OBJ* tmp = top;
        top = top->next;
        free(tmp);
    }
}
OBJ* stack() {
    OBJ* top = NULL;
    return top;
}

