/*
** EPITECH PROJECT, 2021
** mystrcat
** File description:
** nothing
*/

#include <stdlib.h>
#include "my.h"

char *my_other_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (; src[j] != '\0'; j++)
        str[i + j] = src[j];
    str[i + j] = '\0';
    return str;
}

char *my_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    if (str[i - 1] != '/') {
        str[i] = '/';
        i++;
    }
    for (; src[j] != '\0'; j++)
        str[i + j] = src[j];
    str[i + j] = '\0';
    return str;
}
