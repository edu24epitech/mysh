/*
** EPITECH PROJECT, 2024
** MY_PRINT_DIGITS
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int comp = 0;

    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
        if (s1[i] != s2[i]){
            comp += s1[i] - s2[i];
            return comp;
        }
    }
    return 0;
}
