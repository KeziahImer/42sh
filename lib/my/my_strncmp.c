/*
** EPITECH PROJECT, 2021
** mystrncmp
** File description:
** nothing
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int j = 0;

    for (int i = n; s1[i] != '\0' && s2[j] != '\0'; i++) {
        if (s1[i] != s2[j])
            return 1;
        j++;
    }
    return 0;
}
