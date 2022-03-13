/*
** EPITECH PROJECT, 2020
** My_getnbr
** File description:
** Return a number from a string
*/

#include "my.h"

int my_getdigit_rec(char const *str, int i, int y);
int my_getnbrlen(char const *str, int i);

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 1;
    int y;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            j = j * -1;
        i++;
    }
    if (str[i] > '9' || str[i] < '0')
        return 0;
    y = my_getnbrlen(str, i);
    return (my_getdigit_rec(str, i, y - 1) * j);
}

int my_getdigit_rec(char const *str, int i, int y)
{
    int mult = (str[i] - 48) * my_compute_power_rec(10, y);
    int next;

    if (str[i + 1] < '0' || str[i + 1] > '9')
        return (str[i] - 48);
    else {
        next = my_getdigit_rec(str, i + 1, y - 1);
        return (mult + next);
    }
    return 0;
}

int my_getnbrlen(char const *str, int i)
{
    int count = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        count++;
        i++;
    }
    return count;
}
