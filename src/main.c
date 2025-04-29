/*
** EPITECH PROJECT, 2024
** shell_programming
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/built.h"
#include <sys/wait.h>

int minishell_loop(char **my_env)
{
    char *line = NULL;
    size_t len = 0;
    int read;
    int status = 0;

    while (1) {
        if (isatty(STDIN_FILENO))
            my_putstr("$> ");
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        status = process_command(line, &my_env);
        if (status == 1) {
            continue;
        }
    }
    free(line);
    return status;
}

int main(int ac, char **av, char **env)
{
    char **my_env;

    (void)ac;
    (void)av;
    my_env = copy_env(env);
    if (minishell_loop(my_env) == 1) {
        free(my_env);
        return 1;
    }
    for (int i = 0; my_env[i]; i++)
        free(my_env[i]);
    free(my_env);
    return 0;
}
