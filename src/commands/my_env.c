/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_env.c
*/

#include "../../include/my.h"
#include "../../include/built.h"

void builtin_env(char **args, char **env)
{
    (void)**args;
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        my_putstr("\n");
    }
}
