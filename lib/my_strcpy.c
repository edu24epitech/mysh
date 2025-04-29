/*
** EPITECH PROJECT, 2024
** MY_PRINT_DIGITS
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
