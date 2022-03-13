/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Printf tools functions
*/

#include "../my.h"

int my_nbr_num(int nbr)
{
    int len = 1;

    if (nbr < 0)
        len = len + 1;
    while (nbr > 9 || nbr < -9) {
        nbr = nbr / 10;
        len = len + 1;
    }
    return len;
}

char *my_int_to_str(int nbr)
{
    int i = 0;
    int neg = 0;
    char *str = malloc(sizeof(char) * (my_nbr_num(nbr) + 1));

    if (str == 0)
        return print_error("Error : Cannot malloc to put int into str");
    if (nbr < 0)
        neg = 1;
    nbr = my_absolute(nbr);
    while (nbr > 9) {
        str[i] = ((nbr % 10) + 48);
        nbr = nbr / 10;
        i = i + 1;
    }
    str[i] = nbr + 48;
    if (neg == 1) {
        str[i + 1] = '-';
        i = i + 1;
    }
    str[i + 1] = '\0';
    return my_revstr(str);
}

int get_count(const char *format, int **i, char_flags_t cflags)
{
    int count = 0;

    **i = **i + 1;
    while (my_isnum(format[**i]) == 1 && format[**i] != '\0') {
        count = (count * 10) + (format[**i] - 48);
        **i = **i + 1;
    }
    **i = **i - 1;
    count = count - my_strlen(cflags.content);
    count = count - my_strlen(cflags.display_sign);
    count = count - my_strlen(cflags.start_zero);
    count = count - my_strlen(cflags.space_sign);
    if (count < 0)
        count = 0;
    return count;
}

int is_cflags(char c)
{
    char flags[5] = {'#', '-', '+', ' ', 0};

    if (my_isnum(c) == 1)
        return 1;
    for (int i = 0; i < 4; i = i + 1)
        if (my_isnum(c) || c == flags[i])
            return 1;
    return 0;
}

int is_part_of(char *dict, char *c)
{
    for (int i = 0; dict[i] != '\0'; i = i + 1)
        if (dict[i] == c[0])
            return 1;
    return 0;
}
