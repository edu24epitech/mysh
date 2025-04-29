/*
** EPITECH PROJECT, 2024
** last_test.c
** File description:
** my_external_commands.c
*/

#include "../../include/my.h"
#include "../../include/built.h"
#include <sys/wait.h>

static void handle_exit_status(int status)
{
    if (WIFEXITED(status))
        WEXITSTATUS(status);
}

char *get_env_var(char *var, char **env)
{
    int len = my_strlen(var);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], var, len) == 0 && env[i][len] == '=') {
            return env[i] + len + 1;
        }
    }
    return NULL;
}

char *build_full_path(char *dir, char *cmd)
{
    char *full_path = malloc(my_strlen(dir) + my_strlen(cmd) + 2);

    if (full_path == NULL)
        return NULL;
    my_strcpy(full_path, dir);
    my_strcat(full_path, "/");
    my_strcat(full_path, cmd);
    return full_path;
}

char *search_in_path(char *path, char *cmd)
{
    char *path_copy = my_strdup(path);
    char *dir = strtok(path_copy, ":");
    char *full_path = NULL;

    while (dir) {
        full_path = build_full_path(dir, cmd);
        if (full_path == NULL) {
            free(path_copy);
            return NULL;
        }
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}

char *resolve_command_path(char *cmd, char **env)
{
    char *path = NULL;

    if (cmd[0] == '/') {
        return my_strdup(cmd);
    }
    path = get_env_var("PATH", env);
    if (!path)
        return NULL;
    return search_in_path(path, cmd);
}

static void write_error_message(char *cmd)
{
    write(2, cmd, my_strlen(cmd));
    write(2, ": Command not found.\n", 21);
}

static void execute_command(char *path, char **args, char **env)
{
    execve(path, args, env);
    perror("execve");
    free(path);
    exit(EXIT_FAILURE);
}

static int fork_and_execute(char *path, char **args, char **env)
{
    int pid = fork();

    if (pid == -1) {
        perror("fork");
        free(path);
        return 1;
    } else if (pid == 0) {
        execute_command(path, args, env);
    }
    return pid;
}

static int wait_for_child(int pid, char *path)
{
    int status;

    waitpid(pid, &status, 0);
    handle_exit_status(status);
    free(path);
    return 0;
}

int execute_external_command(char **args, char **env)
{
    int pid;
    char *path = resolve_command_path(args[0], env);

    if (path == NULL) {
        write_error_message(args[0]);
        return 1;
    }
    pid = fork_and_execute(path, args, env);
    if (pid == 1)
        return 1;
    return wait_for_child(pid, path);
}
