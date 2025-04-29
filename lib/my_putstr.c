/*
** EPITECH PROJECT, 2024
** MY_PUTSTR
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

void my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
    my_putchar(str[i]);
    }
}
