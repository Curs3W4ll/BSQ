/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Base conversions for printf
*/

#include "../my.h"

char *get_binary_base(unsigned int nbr)
{
    int i = 0;
    int mult = 0;
    char *ret;

    while (my_compute_power_recul(2, mult) <= nbr)
        mult = mult + 1;
    ret = malloc(sizeof(char) * (mult + 1));
    if (ret == 0)
        return print_error("Error : Cannot malloc the binary base number\n");
    for (int j = mult - 1; j >= 0; j = j - 1) {
        if (nbr >= my_compute_power_recul(2, j)) {
            ret[i] = '1';
            nbr = nbr - my_compute_power_recul(2, j);
        } else
            ret[i] = '0';
        i = i + 1;
    }
    ret[i] = '\0';
    return ret;
}

char *get_octal_base(unsigned int nbr)
{
    int i = 0;
    int mult = 0;
    int count = 0;
    char *ret;

    while (my_compute_power_recul(8, mult) <= nbr)
        mult = mult + 1;
    ret = malloc(sizeof(char) * (mult + 1));
    if (ret == 0)
        return print_error("Error : Cannot malloc the octal base\n");
    for (int j = mult - 1; j >= 0; j = j - 1) {
        count = 0;
        while ((nbr / my_compute_power_recul(8, j))) {
            count = count + 1;
            nbr = nbr - my_compute_power_recul(8, j);
        }
        ret[i] = count + 48;
        i = i + 1;
    }
    ret[i] = '\0';
    return ret;
}

char get_acode(int count, int plus)
{
    int code = count + 48;

    if (count > 9)
        code = count + 55 + plus;
    return code;
}

char *get_hexa_base(unsigned long nbr, int plus)
{
    int i = 0;
    int mult = 0;
    int count = 0;
    char *ret;

    while (my_compute_power_recul(16, mult) <= nbr)
        mult = mult + 1;
    ret = malloc(sizeof(char) * (mult + 1));
    if (ret == 0)
        return print_error("Error : Cannot malloc the hexadecimal base\n");
    for (int j = mult - 1; j >= 0; j = j - 1) {
        count = 0;
        while ((nbr / my_compute_power_recul(16, j)) != 0) {
            count = count + 1;
            nbr = nbr - my_compute_power_recul(16, j);
        }
        ret[i] = get_acode(count, plus);
        i = i + 1;
    }
    ret[i] = '\0';
    return ret;
}
