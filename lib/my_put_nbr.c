/*
** EPITECH PROJECT, 2024
** my put nbr
** File description:
** no tiene en cuenta si el numero tiene decimales y los queremos imprimir
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    int aux = 0;

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    aux = nb % 10;
    if (nb > 9){
        my_put_nbr(nb / 10);
    }
    my_putchar(aux + 48);
    return 0;
}
