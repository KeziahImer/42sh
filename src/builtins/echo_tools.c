/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Echo Tools
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void print_buffer(char *buffer, int index, int code)
{
    buffer[index] = '\0';
    if (code == 1)
        my_printf("%s\n", buffer);
    else
        my_printf("%s", buffer);
    free(buffer);
}

char *get_buffer(char *array[])
{
    char *buffer = NULL;
    int size = 0;

    for (int i = 1; array[i] != NULL; i++) {
        size += my_strlen(array[i]);
        size++;
    }
    buffer = malloc(sizeof(char) * (size + 1));
    return buffer;
}

static int get_number(char c, int open, int *simple, int *doubles)
{
    if (c == '\'') {
        if (open == 0) {
            open = 1;
            *simple += 1;
        } else if (open == 1) {
            open = 0;
            *simple += 1;
        }
    }
    if (c == '"') {
        if (open == 0) {
            open = 2;
            *doubles += 1;
        } else if (open == 2) {
            open = 0;
            *doubles += 1;
        }
    }
    return open;
}

int check_quotes(char *array[])
{
    int open = 0;
    int simple = 0;
    int doubles = 0;

    for (int i = 1; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++)
            open = get_number(array[i][j], open, &simple, &doubles);
    }
    if (simple % 2 != 0) {
        write(2, "Unmatched \"'\".\n", 15);
        return 1;
    }
    if (doubles % 2 != 0) {
        write(2, "Unmatched '\"'.\n", 15);
        return 1;
    }
    return 0;
}

int is_interpretable(char c)
{
    if (c == 'n' || c == 't' || c == '\\')
        return 1;
    return 0;
}
