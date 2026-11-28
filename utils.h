#ifndef UTILS_H
#define UTILS_H
typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;
int stack_len(const OBJ* top);
OBJ* push(OBJ* top, int data);
OBJ* stack();
void show(const OBJ* top);
int get_num();
int to_file(const OBJ* top);
void clean_stack(const OBJ* top);
OBJ* swap(OBJ* top, OBJ* one, OBJ* two);
OBJ* sort_direct_connection(OBJ* top);
OBJ* merge(OBJ* one, OBJ* two);
OBJ* split_and_merge(OBJ* top);
#endif