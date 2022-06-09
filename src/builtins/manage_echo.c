/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Manage Echo
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

static int verif_char(int open, char c)
{
    if (c == '\'') {
        if (open == 0)
            open = 1;
        else if (open == 1)
            open = 0;
    }
    if (c == '"') {
        if (open == 0)
            open = 2;
        else if (open == 2)
            open = 0;
    }
    return open;
}

static int manage_print(char c, char d, int open, int *j)
{
    if (c == '\'' && open != 2)
        return 0;
    if (c == '"' && open != 1)
        return 0;
    if (c == '\\' && open != 0) {
        if (is_interpretable(d)) {
            *j += 1;
            return 1;
        }
    }
    if (c == '\\' && open == 0)
        *j += 1;
    return 2;
}

static int print_if_nothing(int code, char c, char *buffer, int index)
{
    if (code != 2)
        return index;
    if (c == '\\')
        buffer[index] = '\\';
    else
        buffer[index] = c;
    return index + 1;
}

static int interpret_code(int code, char c, char *buffer, int index)
{
    if (code == 0 || code == 2)
        return index;
    switch (c) {
        case '\\':
            buffer[index] = '\\';
            break;
        case 'n':
            buffer[index] = '\n';
            break;
        case 't':
            buffer[index] = '\t';
            break;
    }
    return index + 1;
}

void start_echo(char *array[])
{
    char *buffer = get_buffer(array);
    int index = 0;
    int open = 0;
    int code = 0;
    int i = 1;
    int new_line = is_new_line(array, &i);

    for (; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            open = verif_char(open, array[i][j]);
            code = manage_print(array[i][j], array[i][j], open, &j);
            index = interpret_code(code, array[i][j], buffer, index);
            index = print_if_nothing(code, array[i][j], buffer, index);
        }
        if (array[i + 1] == NULL)
            continue;
        buffer[index] = ' ';
        index++;
    }
    print_buffer(buffer, index, new_line);
}
