/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** built.h
*/

#ifndef BUILT_H_
    #define BUILT_H_

void builtin_exit(char **args, char **env);
void builtin_env(char **args, char **env);
int builtin_cd(char **args, char **env);
int builtin_unsetenv(char **args, char **env);
int process_command(char *line, char ***env);
int handle_builtin(char **args, char ***env);
int execute_external_command(char **args, char **env);
char **builtin_setenv(char **args, char **env);
char **copy_env(char **env);
char *get_env_var(char *var, char **env);
char *resolve_command_path(char *cmd, char **env);
void free_args(char **args);
void free_env(char **env);
#endif
