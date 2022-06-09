/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Setenv and unsetenv gestion
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static char *give_new_line(char *name, char *value)
{
    char *str = NULL;
    char *copy = NULL;

    str = my_other_strcat(name, "=");
    if (value == NULL)
        return str;
    copy = str;
    copy = my_other_strcat(str, value);
    free(str);
    return copy;
}

static char **set_env(char *env[], char *name, char *value)
{
    char **copy = NULL;
    int size = 0;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, 0) == 0) {
            free(env[i]);
            env[i] = give_new_line(name, value);
            return env;
        }
    }
    for (; env[size] != NULL; size++);
    copy = malloc(sizeof(char *) * (size + 2));
    for (int i = 0; i < size; i++)
        copy[i] = env[i];
    free(env);
    copy[size] = give_new_line(name, value);
    copy[size + 1] = NULL;
    return copy;
}

char **execute_setenv(char *array[], char *env[], int *verif)
{
    int i = 0;

    if (my_strcmp(array[0], "setenv"))
        return env;
    *verif += 1;
    for (; array[i] != NULL; i++);
    if (i == 1) {
        for (int j = 0; env[j] != NULL; j++)
            my_printf("%s\n", env[j]);
    }
    if (i == 2 || i == 3) {
        if (!is_alphanumeric(array[1], verif))
            return env;
        env = set_env(env, array[1], array[2]);
    }
    if (i == 4) {
        *verif += 1;
        write(2, "setenv : too many arguments.\n", 29);
    }
    return env;
}

static char **unset_env(char *env[], char *name)
{
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, 0)) {
            i++;
            continue;
        }
        free(env[i]);
        for (j = i; env[j + 1] != NULL; j++)
            env[j] = env[j + 1];
        env[j] = NULL;
    }
    return env;
}

char **execute_unsetenv(char *array[], char *env[], int *verif)
{
    int i = 0;

    if (my_strcmp(array[0], "unsetenv"))
        return env;
    *verif += 1;
    for (; array[i]; i++);
    if (i == 1) {
        write(2, "unsetenv : too few arguments.\n", 30);
        *verif += 1;
        return env;
    }
    for (i = 0; array[i] != NULL; i++)
        env = unset_env(env, array[i]);
    return env;
}
