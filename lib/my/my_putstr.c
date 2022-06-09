/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** nothing
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
