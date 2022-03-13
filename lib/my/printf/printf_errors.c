/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Error message display
*/

#include "../my.h"

char *print_error(const char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return "-1";
}
