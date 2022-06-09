/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** Builtins Tools
*/

#include "my.h"
#include <unistd.h>

int is_alphanumeric(char *str, int *verif)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z')
        && (str[i] < 'A' || str[i] > 'Z')) {
            *verif += 1;
            write(2, "setenv: Variable name must contain ", 36);
            write(2, "alphanumeric characters.\n", 26);
            return 0;
        }
    }
    return 1;
}

int is_new_line(char *array[], int *i)
{
    if (array[1] == NULL)
        return 1;
    if (my_strcmp(array[1], "-n"))
        return 1;
    *i += 1;
    return 0;
}
