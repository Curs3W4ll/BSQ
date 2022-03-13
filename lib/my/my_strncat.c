/*
** EPITECH PROJECT, 2020
** My_strncat
** File description:
** Concatenate n charcters from a string into another
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len_dest;
    int len_src;

    len_dest = my_strlen(dest);
    len_src = my_strlen(src);
    while (i < len_src && i < nb) {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';
    return dest;
}
