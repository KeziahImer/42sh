/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Execute cd command
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static char *get_pwd(char *env[])
{
    int i = 0;
    char *pwd = NULL;

    for (; my_strncmp(env[i], "PWD", 0); i++);
    if (env[i] == NULL)
        return NULL;
    pwd = env[i];
    pwd += 4;
    return pwd;
}

static int does_exist(char *path)
{
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        write(2, path, my_strlen(path));
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    return 0;
}

static int make_cd(char *path)
{
    struct stat sb;

    if (path == NULL)
        return 0;
    stat(path, &sb);
    if (does_exist(path))
        return 0;
    if (S_ISDIR(sb.st_mode) != 1) {
        write(2, path, my_strlen(path));
        write(2, ": Not a directory.\n", 19);
        return 0;
    }
    return 1;
}

void change_directory(char *path, char *env[])
{
    static char *old_pwd = NULL;
    char *copy = NULL;
    int i = 0;

    if (path == NULL) {
        for (; my_strncmp(env[i], "HOME", 0); i++);
        path = env[i];
        path += 5;
    }
    if (my_strcmp(path, "-") == 0 && old_pwd != NULL)
        copy = my_strdup(old_pwd);
    else
        copy = my_strdup(path);
    if (make_cd(copy)) {
        old_pwd = getcwd(old_pwd, 256);
        chdir(copy);
    }
    free(copy);
}
