/*
** EPITECH PROJECT, 2021
** Day 06
** File description:
** nothing
*/

int my_strlen2(char const *str)
{
    int i = 0;

    if (!str) {
        return (0);
    }
    while (str[i] != '\0') {
        i++;
    }

    return (i);
}

int compteur(char *str, char const *to_find, int k, int i)
{
    while (to_find[k] == str[i] && to_find[k] != '\0') {
        k++;
        i++;
    }
    return (k);
}

char *my_strstr(char *str, char const *to_find)
{
    return (0);
}
