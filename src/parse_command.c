/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Parse Command
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

static int is_delim(char *str, int i)
{
    switch (str[i]) {
        case '|': return 1;
        case ';': return 1;
        case '&': return 1;
    }
    return 0;
}

static void add_element(list_t *list, char *str, int *first, int *i)
{
    command_t *command = malloc(sizeof(command_t));
    separator_t *separator = malloc(sizeof(separator_t));
    char *buffer = malloc(sizeof(char) * (*i - *first + 1));
    command_t *tmp_c = list->commands;
    separator_t *tmp_s = list->separators;
    int j = 0;

    for (; *first != *i; *first += 1, j++)
        buffer[j] = str[*first];
    buffer[j] = '\0';
    command->array = my_str_to_word_array(buffer, " \t\n");
    free(buffer);
    command->next = NULL;
    for (; tmp_c->next != NULL; tmp_c = tmp_c->next);
    tmp_c->next = command;
    separator->str = get_separator(str, i, first);
    separator->next = NULL;
    for (; tmp_s->next != NULL; tmp_s = tmp_s->next);
    tmp_s->next = separator;
}

static list_t *initialize_element(char *str, int *first, int *i)
{
    list_t *list = malloc(sizeof(list_t));
    command_t *command = malloc(sizeof(command_t));
    separator_t *separator = malloc(sizeof(separator_t));
    char *buffer = malloc(sizeof(char) * (*i - *first + 1));
    int j = 0;

    for (; *first != *i; *first += 1) {
        buffer[j] = str[*first];
        j++;
    }
    buffer[j] = '\0';
    command->array = my_str_to_word_array(buffer, " \t\n");
    free(buffer);
    command->next = NULL;
    list->commands = command;
    separator->str = get_separator(str, i, first);
    separator->next = NULL;
    list->separators = separator;
    return list;
}

static list_t *manage_head(list_t *list, char *str, int *first, int *i)
{
    if (list == NULL)
        list = initialize_element(str, first, i);
    else
        add_element(list, str, first, i);
    return list;
}

list_t *parse_command(char *str)
{
    list_t *list = NULL;
    int first = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (is_delim(str, i))
            list = manage_head(list, str, &first, &i);
    }
    list = manage_head(list, str, &first, &i);
    return list;
}
