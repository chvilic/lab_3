#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define BUFFER 100
void clean_input(void) {
    char buf[BUFFER];
    fgets(buf, sizeof(buf), stdin);
}
int stack_len(const OBJ* top) {
    int n = 0;
    while (top) {
        n++;
        top = top->next;
    }
    return n;
}
int main() {
    system("chcp 65001");

    char flag[10];
    char flag_mode[10];
    while (1) {
        printf("\nВведите '0' чтобы выйти, '1' чтобы продолжить: ");
        if (scanf(" %9s", flag) != 1) {
            clean_input();
            printf("Ошибка ввода\n");
            continue;
        }
        clean_input();

        if (strcmp(flag, "0") == 0) {
            break;
        }
        if (strcmp(flag, "1") != 0) {
            printf("Вы ввели что-то не то\n");
            continue;
        }
        /* Добавление чисел в стек*/
        printf("Вводите числа для добавления их в стек\n");
        OBJ* top = stack();
        int c;
        while (1) {
            c = getchar();
            if (c == '\n' || c == EOF) break;
            ungetc(c, stdin);

            int num = get_num();
            if (num == -1) return 0;

            top = push(top, num);
        }
        printf("Получившийся стек: ");
        show(top);
        OBJ* sort = split_and_merge(top);
        show(sort);
        to_file(sort);
        clean_stack(top);
        clean_stack(sort);
    }
    printf("До свидания\n");
    return 0;
}