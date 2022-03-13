/*
** EPITECH PROJECT, 2020
** My_strcat
** File description:
** Concatenate two string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len_dest;
    int len_src;

    len_dest = my_strlen(dest);
    len_src = my_strlen(src);
    while (i < len_src) {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';
    return dest;
}
