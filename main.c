#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define BUFFER 100
void clean_input(void) {
    char buf[BUFFER];
    fgets(buf, sizeof(buf), stdin);
}

int main() {
    system("chcp 65001");

    char flag[10];
    char flag_mode[10];
    while (1) {
        printf("Введите '0' чтобы выйти, '1' чтобы продолжить: ");
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
        stack();
    }
    printf("До свидания\n");
    return 0;
    return 0;
}