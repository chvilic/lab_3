#ifndef UTILS_H
#define UTILS_H
typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;
OBJ* push(OBJ* top, int data);
int stack();
void show(const OBJ* top);
int get_num();

#endif