/*
** EPITECH PROJECT, 2021
** Day 05
** File description:
** nothing
*/

int my_compute_power_rec(int nb, int p)
{
    long result = nb;
    int overflow;

    if (nb == 0 || p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p == 1) {
        return (nb);
    }
    result = result * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647) {
        return (0);
    }
    overflow = result;
    return (overflow);
}
