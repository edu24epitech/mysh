/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_process_command.c
*/

#include "../include/my.h"
#include "../include/built.h"

int is_builtin(char *cmd)
{
    char *builtins[] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};

    for (int i = 0; builtins[i]; i++) {
        if (my_strcmp(cmd, builtins[i]) == 0)
            return 2;
    }
    return 0;
}

int process_command(char *line, char ***env)
{
    char **args = my_str_to_word_array(line);

    if (args == NULL || args[0] == NULL) {
        free_args(args);
        return 0;
    }
    if (is_builtin(args[0]) == 2) {
        if (handle_builtin(args, env) == 1) {
            free_args(args);
            return 1;
        }
        free_args(args);
        return 0;
    }
    if (execute_external_command(args, *env) == 1) {
        free_args(args);
        return 1;
    }
    free_args(args);
    return 0;
}
