/*
** EPITECH PROJECT, 2020
** My_putstr
** File description:
** Displays characters of a string
*/

#include "my.h"

void my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
}
