/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Separator Gestion
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static int verif_invalid(list_t *list)
{
    int i = 0;
    command_t *tmp_1 = list->commands;
    separator_t *tmp_2 = list->separators;

    for (; tmp_1 != NULL && tmp_1->array[0] != NULL; tmp_1 = tmp_1->next)
        i++;
    for (; tmp_2 != NULL; tmp_2 = tmp_2->next) {
        if (my_strcmp(tmp_2->str, "&") == 0) {
            write(2, "Job not supported.\n", 20);
            return 1;
        }
        i--;
    }
    if (i == 0)
        return 0;
    write(2, "Invalid null command.\n", 23);
    return 1;
}

void free_exit(list_t *list, char *env[], char *str)
{
    free_list(list);
    free_array(env);
    free(str);
    exit(0);
}

static separator_t *verif_exit_status_two(int e_s, separator_t *tmp, int code)
{
    if (code == 1 && e_s != 0)
        return tmp = tmp->next;
    else if (code == 0 && e_s == 0)
        return tmp = tmp->next;
    return tmp;
}

static command_t *verif_exit_status_one(int e_s, command_t *parse, int code)
{
    if (code == 1 && e_s != 0)
        return parse = parse->next;
    else if (code == 0 && e_s == 0)
        return parse = parse->next;
    return parse;
}

void separator_gestion(list_t *list, char **env[], char *str)
{
    command_t *parse = list->commands;
    int exit_status = 0;

    if (verif_invalid(list))
        return;
    for (separator_t *tmp = list->separators; tmp != NULL;) {
        exit_status = execute_program(parse->array, env);
        if (exit_status == -2)
            free_exit(list, *env, str);
        if (parse != NULL) {
            parse = parse->next;
            tmp = tmp->next;
        }
    }
}
