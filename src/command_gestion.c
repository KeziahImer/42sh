/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Execute Binary
*/

#include "my.h"
#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static int is_exist(char *str, char *array[], char *env[], int *exist)
{
    int return_value = 0;
    __pid_t pid = 0;
    int status = 0;
    int fd = 0;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return 0;
    *exist = 1;
    pid = fork();
    if (pid == 0)
        return_value = execve(str, array, env);
    else
        waitpid(pid, &status, 0);
    if (return_value == -1)
        exit(84);
    if (WTERMSIG(status) != 0)
        write_error_message(array[0], WTERMSIG(status));
    return WEXITSTATUS(status);
}

static char **get_path(char *env[])
{
    int i = 0;
    char *path = NULL;
    char **array = NULL;

    for (; env[i] != NULL && my_strncmp(env[i], "PATH", 0); i++);
    if (env[i] == NULL)
        return NULL;
    path = env[i];
    path += 5;
    array = my_str_to_word_array(path, ":\n");
    return array;
}

static int execute_with_path(char *array[], char *env[])
{
    char **path = NULL;
    char *str = NULL;
    int return_value = 0;
    int verif = 0;

    path = get_path(env);
    if (path == NULL)
        return 0;
    for (int i = 0; path[i] != NULL; i++) {
        str = my_strcat(path[i], array[0]);
        verif = is_exist(str, array, env, &return_value);
        free(str);
        if (return_value) {
            free_array(path);
            return verif;
        }
    }
    free_array(path);
    return -1;
}

static int execute_without_path(char *array[], char *env[])
{
    int return_value = 0;
    int status = 0;
    __pid_t pid;

    if (is_dir(array[0]))
        return -1;
    pid = fork();
    if (pid == 0)
        return_value = execve(array[0], array, env);
    else
        waitpid(pid, &status, 0);
    if (return_value == -1)
        exit(84);
    if (WTERMSIG(status) != 0)
        write_error_message(array[0], WTERMSIG(status));
    return WEXITSTATUS(status);
}

int execute_program(char *array[], char **env[])
{
    int verif = 0;

    verif = execute_builtins(array, env);
    if (verif != -1)
        return verif;
    verif = execute_with_path(array, *env);
    if (verif > -1)
        return verif;
    verif = execute_without_path(array, *env);
    return verif;
}
