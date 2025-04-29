/*
** EPITECH PROJECT, 2024
** MY_PRINT_DIGITS
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include <stdio.h>
#include <stdlib.h>
// #include "lib/my/my.h"

char *my_strcpydup(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int my_strlendup(char const *str)
{
    int count = 0;

        for (int i = 0; str[i] != '\0'; i++) {
        count++;
        }
    return count;
}

char *my_strdup(char const *src)
{
    int len = my_strlendup(src);
    char *dest = malloc(sizeof(char) * len + 1);

        if (dest == NULL){
            return NULL;
        }
    my_strcpydup(dest, src);
    return dest;
}
