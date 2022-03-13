/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Printf tools functions
*/

#include "../my.h"

int cflags_stop(char c)
{
    char type[9] = {'d', 'i', 'c', 's', '%', 'S', 0};

    for (int i = 0; type[i] != '\0'; i = i + 1)
        if (c == type[i]) {
            return 1;
        }
    return 0;
}

int count_nonprintable(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1)
        if (my_isprintable(str[i]) == 0)
            count = count + 1;
    return count;
}

char *my_uint_to_str(unsigned int nbr)
{
    int i = 0;
    int len = 1;
    unsigned int cpnbr = nbr;
    char *str;

    while (cpnbr > 9) {
        cpnbr = cpnbr / 10;
        len = len + 1;
    }
    str = malloc(sizeof(char) * (len + 1));
    if (str == 0)
        return print_error("Error : Cannot malloc to put uint into str");
    nbr = my_absolute(nbr);
    while (nbr > 9) {
        str[i] = ((nbr % 10) + 48);
        nbr = nbr / 10;
        i = i + 1;
    }
    str[i] = nbr + 48;
    str[i + 1] = '\0';
    return my_revstr(str);
}

char *add_to_start_str(char *str, char *add)
{
    int i = 0;
    char *ret = malloc(sizeof(char) * (my_strlen(str) + my_strlen(add) + 1));

    if (ret == 0)
        return print_error("Error : Cannot modify the start of the string\n");
    for (int y = 0; add[y] != '\0'; y = y + 1) {
        ret[i] = add[y];
        i = i + 1;
    }
    for (int y = 0; str[y] != '\0'; y = y + 1) {
        ret[i] = str[y];
        i = i + 1;
    }
    ret[i] = '\0';
    free(str);
    return ret;
}

int my_ishexa(const char c)
{
    if ((c <= 'F' && c >= 'A') || (c <= 'f' && c >= 'a'))
        return 1;
    if (c <= '9' && c >= '0')
        return 1;
    return 0;
}
