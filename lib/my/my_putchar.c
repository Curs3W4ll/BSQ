/*
** EPITECH PROJECT, 2020
** My_putchar
** File description:
** Display one character
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
