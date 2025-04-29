/*
** EPITECH PROJECT, 2024
** solo_stmpr_1
** File description:
** my.h
*/

#ifndef STMPR1_H
    #define STMPR1_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void my_putstr(char const *str);
void my_putchar(char c);
char *my_strdup(char const *src);
char **my_str_to_word_array(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
#endif
