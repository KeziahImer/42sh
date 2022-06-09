/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Parse Tools
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

void free_list(list_t *list)
{
    command_t *save_1 = NULL;
    separator_t *save_2 = NULL;

    for (command_t *tmp = list->commands; tmp != NULL; tmp = save_1) {
        free_array(tmp->array);
        save_1 = tmp->next;
        free(tmp);
    }
    for (separator_t *tmp = list->separators; tmp != NULL; tmp = save_2) {
        free(tmp->str);
        save_2 = tmp->next;
        free(tmp);
    }
    free(list);
}

char *get_separator(char *str, int *i, int *first)
{
    char *new = malloc(sizeof(char) * 3);

    *first += 1;
    new[0] = str[*i];
    if (str[*i] == '\0')
        return new;
    if (str[*i] == str[*i + 1]) {
        new[1] = str[*i + 1];
        new[2] = '\0';
        *first += 1;
        *i += 1;
    } else
        new[1] = '\0';
    return new;
}
