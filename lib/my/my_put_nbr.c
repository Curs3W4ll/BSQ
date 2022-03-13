/*
** EPITECH PROJECT, 2020
** My_put_nbr
** File description:
** Display a number
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int nbr;

    if (nb == -2147483648)
        my_putstr("-2147483648");
    else {
        if (nb >= 0 && nb < 10)
            my_putchar(nb + 48);
        else if (nb >= 10) {
            nbr = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(nbr + 48);
        } else {
            nb = nb * -1;
            my_putchar('-');
            my_put_nbr(nb);
        }
    }
    return 0;
}
