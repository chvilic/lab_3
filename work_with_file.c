#include <stdio.h>
#include "utils.h"
int to_file(const OBJ* top) {
    FILE *my_file;
    int symb;
    my_file = fopen("data.txt", "w");
    if (my_file == NULL) {
        printf("ошибка при открытии файла\n");
        fclose(my_file);
        return -1;
    }
    const OBJ* current = top;
    while (current != NULL && current->data != EOF) {
        fprintf(my_file, "%d ", current->data);
        current = current->next;
    }
    fclose(my_file);
    return 1;
}