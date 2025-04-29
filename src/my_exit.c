/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_exit.c
*/

#include "../include/my.h"
#include "../include/built.h"

void free_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        free(env[i]);
    }
    free(env);
}

void free_args(char **args)
{
    for (int i = 0; args[i]; i++) {
        free(args[i]);
    }
    free(args);
}

void builtin_exit(char **args, char **env)
{
    free_env(env);
    free_args(args);
    exit(EXIT_SUCCESS);
}
