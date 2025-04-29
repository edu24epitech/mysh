/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_cd.c
*/

#include "../../include/my.h"
#include "../../include/built.h"

void change_to_home(char **env)
{
    char *home = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            home = env[i] + 5;
            break;
        }
    }
    chdir(home);
}

void change_to_old_pwd(char **env)
{
    char *oldpwd = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0) {
            oldpwd = env[i] + 7;
            break;
        }
    }
    chdir(oldpwd);
}

int chdir_to_path(char **args)
{
    if (chdir(args[1]) == -1) {
        my_putstr(args[1]);
        my_putstr(": No such file or directory.\n");
        return 1;
    }
    return 0;
}

int builtin_cd(char **args, char **env)
{
    int status = 0;

    if (args[1] == NULL) {
        change_to_home(env);
    } else if (my_strcmp(args[1], "-") == 0) {
        change_to_old_pwd(env);
        return 0;
    } else {
        status = chdir_to_path(args);
    }
    return status;
}
