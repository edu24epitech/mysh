/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_copy_env.c
*/

#include "../include/my.h"
#include "../include/built.h"

char **copy_env(char **env)
{
    int i = 0;
    int count = 0;
    char **new_env = NULL;

    while (env[count])
        count++;
    new_env = malloc((count + 1) * sizeof(char *));
    for (i = 0; i < count; i++) {
        new_env[i] = my_strdup(env[i]);
    }
    new_env[count] = NULL;
    return new_env;
}
