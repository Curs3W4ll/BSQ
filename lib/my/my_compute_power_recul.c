/*
** EPITECH PROJECT, 2020
** My_compute_power_recul
** File description:
** Return the result of an unsigned number by a power
*/

#include "my.h"

unsigned long my_compute_power_recul(unsigned int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    else {
        return (nb * my_compute_power_recul(nb, p - 1));
    }
}
