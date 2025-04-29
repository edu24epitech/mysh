/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_strncmp.c
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int comp = 0;

    for (i = 0; (s1[i] != '\0' || s2[i] != '\0') && i < n; i++) {
        if (s1[i] != s2[i]) {
            comp += s1[i] - s2[i];
            return comp;
        }
    }
    return 0;
}
