/*
** EPITECH PROJECT, 2020
** Task01/My_strdup
** File description:
** Alloc memory and copy a string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int len;
    int i = 0;

    len = my_strlen(src);
    str = malloc(sizeof(char) * (len + 1));
    while (i < len) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
