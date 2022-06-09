##
## EPITECH PROJECT, 2021
## 42sh
## File description:
## Makefile
##

SRC =	src/shell.c	\
		src/parse_command.c	\
		src/parse_tools.c	\
		src/separator_gestion.c	\
		src/command_gestion.c	\
		src/error_messages.c	\
		src/error_handling.c	\
		src/builtins/builtins_gestion.c	\
		src/builtins/execute_cd.c	\
		src/builtins/setenv_unsetenv.c	\
		src/builtins/manage_echo.c	\
		src/builtins/echo_tools.c	\
		src/builtins/builtins_tools.c	\

OBJ =	$(SRC:.c=.o)

LDFLAGS =	-L./lib/my -lmy

CPPFLAGS =	-I./include

ALL_FLAGS =	$(LDFLAGS) $(CPPFLAGS)

BINARY =	42sh

## Repository rules

all: build $(BINARY)

$(BINARY): $(OBJ)
	gcc -o $(BINARY) $(OBJ) $(ALL_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY)

re: fclean all

debug: build $(SRC)
	gcc -o $(BINARY) $(SRC) $(ALL_FLAGS)

## Lib Rules

build:
	$(MAKE) -C ./lib/my

libfclean:
	$(MAKE) -C ./lib/my fclean
