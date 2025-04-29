/*
** EPITECH PROJECT, 2024
** MY_STRLEN
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int count = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
