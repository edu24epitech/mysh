/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_setenv.c
*/

#include "../../include/my.h"
#include "../../include/built.h"

char *create_new_var(char **args)
{
    int len1 = my_strlen(args[1]);
    int len2 = my_strlen(args[2]);
    char *new_var = malloc(len1 + len2 + 2);

    if (new_var == NULL) {
        perror("malloc");
        return NULL;
    }
    my_strcpy(new_var, args[1]);
    new_var[len1] = '=';
    my_strcpy(new_var + len1 + 1, args[2]);
    return new_var;
}

char **update_existing_var(char **env, char *new_var, int len1)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], new_var, len1) == 0 && env[i][len1] == '=') {
            free(env[i]);
            env[i] = new_var;
            return env;
        }
    }
    free(new_var);
    return NULL;
}

char **add_new_var(char **env, char *new_var)
{
    int count = 0;
    char **new_env = NULL;

    while (env[count])
        count++;
    new_env = malloc((count + 2) * sizeof(char *));
    if (new_env == NULL) {
        perror("malloc");
        free(new_var);
        return env;
    }
    for (int i = 0; i < count; i++) {
        new_env[i] = env[i];
    }
    new_env[count] = new_var;
    new_env[count + 1] = NULL;
    free(env);
    return new_env;
}

char *create_new_var_with_empty_value(char *key)
{
    int len = my_strlen(key);
    char *new_var = malloc(len + 2);

    if (new_var == NULL) {
        perror("malloc");
        return NULL;
    }
    my_strcpy(new_var, key);
    new_var[len] = '=';
    new_var[len + 1] = '\0';
    return new_var;
}

static int check_args(char **args, char ***env)
{
    char *new_var = NULL;

    if (args[1] == NULL) {
        builtin_env(args, *env);
        return 1;
    }
    if (args[1] != NULL && args[2] == NULL) {
        new_var = create_new_var_with_empty_value(args[1]);
        if (new_var == NULL) {
            return 1;
        }
        *env = add_new_var(*env, new_var);
        return 1;
    }
    if (args[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 1;
    }
    return 0;
}

char **builtin_setenv(char **args, char **env)
{
    char *new_var = NULL;
    char **updated_env = NULL;

    if (check_args(args, &env) == 1) {
        return env;
    }
    new_var = create_new_var(args);
    if (new_var == NULL) {
        return env;
    }
    updated_env = update_existing_var(env, new_var, my_strlen(args[1]));
    if (updated_env != NULL) {
        return updated_env;
    }
    return add_new_var(env, new_var);
}
