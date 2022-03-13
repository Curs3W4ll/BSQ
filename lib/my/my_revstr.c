/*
** EPITECH PROJECT, 2020
** My_revstr
** File description:
** Reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int position;
    int y;
    char tmp;

    y = my_strlen(str) - 1;
    position = y / 2;
    for (int i = 0; i <= position; i++) {
        tmp = str[i];
        str[i] = str[y];
        str[y] = tmp;
        y--;
    }
    return str;
}
