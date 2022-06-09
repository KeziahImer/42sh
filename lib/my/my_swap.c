/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** nothing
*/

void my_swap(int *a, int *b)
{
    int pass;

    pass = *a;
    *a = *b;
    *b = pass;
}
