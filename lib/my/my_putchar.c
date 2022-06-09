/*
** EPITECH PROJECT, 2021
** My_putchar
** File description:
** nothing
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
