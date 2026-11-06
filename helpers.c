/**
 * @file helpers.c
 * @author Ricardo Araújo (a21150@alunos.ipca.pt)
 * @brief Helper functions for "main.c"
 * @version 0.2
 * @date 24-12-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "helpers.h"

int read_integer(char prompt[]) {
    int result, value;

    while (getchar() != '\n')
        ;
    do {
        printf("%s", prompt);
        result = scanf("%d", &value);
    } while (result == 0);

    return value;
}
float read_float(char prompt[]) {
    int result;
    float value;

    while (getchar() != '\n')
        ;
    do {
        printf("%s", prompt);
        result = scanf("%f", &value);
    } while (result == 0);

    return value;
}
void read_string(char prompt[], char response[]) {
    int result;

    while (getchar() != '\n')
        ;
    do {
        printf("%s", prompt);
        result = scanf("%[^\n]", response);
    } while (result == 0);
}
bool employee_exists(employee_data employees[MAX_EMPLOYEES], int employee_count,
                     int id) {
    bool match = false;
    for (int i = 0; i < employee_count; i++)
        if (employees[i].id == id)
            match = true;

    return match;
}
void pause_screen() {
    while (getchar() != '\n')
        ;
    printf("\nPress ENTER to continue...");
    getchar();
}
void print_separator(int width) {
    printf("+");
    for (int i = 0; i < width; i++)
        printf("-");
    printf("+\n");
}
