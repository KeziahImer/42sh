/*
** EPITECH PROJECT, 2021
** Library
** File description:
** My str to word array
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int is_separator(char c, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return 1;
    }
    return 0;
}

int allocate_string(char **array, char *str, int a, char *delim)
{
    int tmp = 0;
    int s = a;
    int i = 0;

    for (; array[i] != "Fill"; i++);
    for (; !is_separator(str[a], delim) && str[a] != '\0'; a++, tmp++);
    array[i] = malloc(sizeof(char) * (tmp + 1));
    if (array[i] == NULL)
        return -1;
    array[i][tmp] = '\0';
    for (tmp = 0; !is_separator(str[s], delim) && str[s] != '\0'; s++, tmp++)
        array[i][tmp] = str[s];
    return a;
}

char **allocate_tab(char *str, char *delim)
{
    int i = 0;
    int cpt = 0;
    char **array = NULL;

    for (; is_separator(str[i], delim); i++);
    for (; str[i] != '\0';) {
        for (; !is_separator(str[i], delim) && str[i] != '\0'; i++);
        cpt += 1;
        for (; is_separator(str[i], delim) && str[i] != '\0'; i++);
    }
    array = malloc(sizeof(char *) * (cpt + 1));
    for (i = 0; i < cpt; i++)
        array[i] = "Fill";
    array[cpt] = NULL;
    return array;
}

char **my_str_to_word_array(char *str, char *delim)
{
    char **array = NULL;
    int a = 0;
    int i = 0;

    array = allocate_tab(str, delim);
    if (array == NULL)
        return NULL;
    for (; is_separator(str[a], delim); a++);
    for (; array[i] != NULL; i++) {
        a = allocate_string(array, str, a, delim);
        if (a == -1)
            return array;
        for (; is_separator(str[a], delim) && str[a] != '\0'; a++);
    }
    return array;
}
