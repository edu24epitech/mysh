/*
** EPITECH PROJECT, 2024
** strcat
** File description:
** task02
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len] = src[i];
        len++;
        i++;
    }
    dest[len] = '\0';
    return dest;
}
