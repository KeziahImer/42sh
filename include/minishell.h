/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** H File
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

/* Structures */

typedef struct command_s {
    struct command_s *next;
    char **array;
} command_t;

typedef struct separator_s {
    struct separator_s *next;
    char *str;
} separator_t;

typedef struct list_s {
    command_t *commands;
    separator_t *separators;
} list_t;

/* Prototypes */

list_t *parse_command(char *str);

char *get_separator(char *str, int *i, int *first);

void separator_gestion(list_t *list, char **env[], char *str);

int execute_program(char *array[], char **env[]);

int execute_builtins(char *array[], char **env[]);

int is_dir(char *str);

void change_directory(char *path, char *env[]);

char **execute_setenv(char *array[], char *env[], int *verif);

int is_alphanumeric(char *str, int *verif);

char **execute_unsetenv(char *array[], char *env[], int *verif);

int check_quotes(char *array[]);

void start_echo(char *array[]);

void print_buffer(char *buffer, int index, int code);

int is_new_line(char *array[], int *i);

char *get_buffer(char *array[]);

int is_interpretable(char c);

void write_error_message(char *name, int status);

void and_or_gestion(command_t *parse, separator_t *tmp, char **env[]);

void free_list(list_t *head);

#endif
