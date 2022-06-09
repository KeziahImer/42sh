/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Main File
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

static void wait_command(char *env[])
{
    list_t *list = NULL;
    char *str = NULL;
    size_t size = 0;

    my_printf("$> ");
    while (getline(&str, &size, stdin) != -1) {
        list = parse_command(str);
        separator_gestion(list, &env, str);
        free_list(list);
        my_printf("$> ");
    }
    free_array(env);
    free(str);
    return;
}

static char **copy_env(char *env[])
{
    char **copy = NULL;
    int i = 0;

    if (env == NULL)
        exit(84);
    if (env[0] == NULL)
        exit(84);
    for (; env[i] != NULL; i++);
    copy = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j++)
        copy[j] = my_strdup(env[j]);
    copy[i] = NULL;
    return copy;
}

int main(int argc, char *argv[], char *env[])
{
    char **copy = NULL;

    if (argc != 1)
        return 84;
    copy = copy_env(env);
    wait_command(copy);
    my_printf("exit\n");
    return 0;
}
