/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Builtins gestion
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static int execute_echo(char *array[])
{
    if (my_strcmp(array[0], "echo"))
        return 0;
    if (check_quotes(array))
        return 2;
    start_echo(array);
    return 1;
}

static int execute_cd(char *array[], char *env[])
{
    int i = 0;

    if (my_strcmp(array[0], "cd"))
        return 0;
    for (; array[i] != NULL; i++);
    if (i > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 2;
    } else if (i == 1)
        change_directory(NULL, env);
    else
        change_directory(array[1], env);
    return 1;
}

static int execute_env(char *array[], char *env[])
{
    if (my_strcmp(array[0], "env"))
        return 0;
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return 1;
}

static int execute_exit(char *array[])
{
    int i = 0;

    if (my_strcmp(array[0], "exit"))
        return 0;
    for (; array[i] != NULL; i++);
    if (i != 1) {
        write(2, "exit: Expression Syntax.\n", 25);
        return 2;
    }
    my_printf("exit\n");
    return -1;
}

int execute_builtins(char *array[], char **env[])
{
    int verif = -1;

    if (array[0] == NULL)
        return 1;
    verif += execute_exit(array);
    verif += execute_env(array, *env);
    verif += execute_cd(array, *env);
    verif += execute_echo(array);
    *env = execute_setenv(array, *env, &verif);
    *env = execute_unsetenv(array, *env, &verif);
    return verif;
}
