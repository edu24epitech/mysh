/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_unsetenv.c
*/

#include "../../include/my.h"
#include "../../include/built.h"

void remove_env_var(char **env, int i)
{
    free(env[i]);
    while (env[i]) {
        env[i] = env[i + 1];
        i++;
    }
}

int builtin_unsetenv(char **args, char **env)
{
    int len = 0;
    int found = 0;

    if (args[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    len = my_strlen(args[1]);
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], args[1], len) == 0 && env[i][len] == '=') {
            remove_env_var(env, i);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        my_putstr("unsetenv: Variable not found.\n");
        return 1;
    }
    return 0;
}
