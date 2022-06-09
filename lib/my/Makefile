##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compilation
##

SRC =	my_find_prime_sup.c		\
	my_getstring.c			\
	my_is_prime.c			\
	my_putstr.c			\
	my_showstr.c			\
	my_strcat.c			\
	my_str_isalpha.c		\
	my_str_isprintable.c		\
	my_strlowcase.c 		\
	my_strncpy.c 			\
	my_swap.c 			\
	my_compute_power_rec.c 		\
	my_getnbr.c 			\
	my_putchar.c 			\
	my_revstr.c 			\
	my_sort_int_array.c 		\
	my_strcmp.c 			\
	my_str_islower.c 		\
	my_str_isupper.c 		\
	my_strncat.c 			\
	my_strstr.c 			\
	my_compute_square_root.c	\
	my_str_to_word_array.c	\
	my_isneg.c 			\
	my_put_nbr.c 			\
	my_showmem.c			\
	my_strcapitalize.c 		\
	my_strcpy.c			\
	my_str_isnum.c 			\
	my_strlen.c 			\
	my_strncmp.c 			\
	my_strupcase.c 			\
	my_strdup.c			\
	my_printf.c			\
	my_put_long.c			\
	my_put_conv.c			\
	my_put_invis.c			\
	my_put_adress.c			\
	pointeur1.c			\
	pointeur2.c			\
	pointeur3.c			\

OBJ = $(SRC:.c=.o)

LIB = libmy.a

all : $(LIB)

$(LIB): $(SRC) $(OBJ)
	gcc -c $(SRC)
	ar rc $(LIB) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f ../../include/my.h

re: fclean all
