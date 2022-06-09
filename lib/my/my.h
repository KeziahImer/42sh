/*
** EPITECH PROJECT, 2021
** Day09
** File description:
** nothing
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
    #define is_number(c) (c >= '0' && c <= '9') ? 1 : 0
    #define is_lowercase(c) (c >= 'a' && c <= 'z') ? 1 : 0
    #define is_uppercase(c) (c >= 'A' && c <= 'Z') ? 1 : 0

void my_putchar(char c);

char *my_strstr(char *str, char const *to_find);

char *my_getstring(int result);

int my_isneg(int nb);

int my_strcmp(char const *s1, char const *s2);

int my_put_nbr(int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char **my_str_to_word_array(char *str, char *delim);

void free_array(char **array);

void my_swap(int *a, int *b);

char *my_strupcase(char *str);

int my_putstr(char const *str);

char *my_strlowcase(char *str);

int my_strlen(char const *str);

char *my_strcapitalize(char *str);

int my_getnbr(char const *str);

int my_getnbr_index(char const *str, int i);

int my_str_isalpha(char const *str);

void my_sort_int_array(int *tab, int size);

int my_str_isnum(char const *str);

int my_compute_power_rec(int nb, int power);

int my_str_islower(char const *str);

int my_compute_square_root(int nb);

int my_str_isupper(char const *str);

int my_is_prime(int nb);

int my_str_isprintable(char const *str);

int my_find_prime_sup(int nb);

int my_showstr(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_showmem(char const *str, int size);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strcat(char *dest, char const *src);

char *my_other_strcat(char *dest, char const *src);

char *my_revstr(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strlen2(char const *str);

int compteur(char *str, char const *to_find, int k, int i);

void myswap(int *a, int *b);

int mystrlen(char const *str);

char *my_strdup(char const *src);

int my_printf(char const *format, ...);

int my_put_long(long a);

int my_put_hexa_low(unsigned int a);

int my_put_hexa_upper(unsigned int a);

int size_number(int a);

int my_put_invis(char *str);

int my_put_oct(unsigned int a);

int my_put_bin(unsigned int a);

int size_unsigned(unsigned int a);

int my_put_adress(long long a);

int p_my_putstr(va_list list);

int p_my_put_adress(va_list list);

int p_my_put_hexa_upper(va_list list);

int p_my_put_hexa_low(va_list list);

int p_my_put_oct(va_list list);

int p_my_put_bin(va_list list);

int p_my_put_invis(va_list list);

int p_my_put_long(va_list list);

int p_my_put_nbr(va_list list);

int p_my_putchar(va_list list);

int p_my_put_pourcent(va_list list);

#endif
