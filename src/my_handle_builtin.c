/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** handle_builtin.c
*/

#include "../include/my.h"
#include "../include/built.h"

void update_env_var(char *var, char *value, char ***env)
{
    char *args[] = {"setenv", var, value, NULL};

    if (var == NULL || value == NULL) {
        return;
    }
    *env = builtin_setenv(args, *env);
}

static int handle_cd(char **args, char ***env)
{
    if (builtin_cd(args, *env) == 1)
        return 1;
    update_env_var("OLDPWD", get_env_var("PWD", *env), env);
    update_env_var("PWD", getcwd(NULL, 0), env);
    return 0;
}

static int handle_exit(char **args, char **env)
{
    builtin_exit(args, env);
    return 0;
}

static int handle_setenv(char **args, char ***env)
{
    *env = builtin_setenv(args, *env);
    return 0;
}

static int handle_unsetenv(char **args, char ***env)
{
    if (builtin_unsetenv(args, *env) == 1)
        return 1;
    return 0;
}

static int handle_env(char **args, char **env)
{
    builtin_env(args, env);
    return 0;
}

int handle_builtin(char **args, char ***env)
{
    if (my_strcmp(args[0], "cd") == 0)
        return handle_cd(args, env);
    if (my_strcmp(args[0], "exit") == 0)
        return handle_exit(args, *env);
    if (my_strcmp(args[0], "setenv") == 0)
        return handle_setenv(args, env);
    if (my_strcmp(args[0], "unsetenv") == 0)
        return handle_unsetenv(args, env);
    if (my_strcmp(args[0], "env") == 0)
        return handle_env(args, *env);
    return 0;
}
