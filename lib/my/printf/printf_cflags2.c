/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Cflags management part 2
*/

#include "../my.h"

char *get_lspace_pad(const char *fmt, int i, char_flags_t cflags)
{
    char *ret;

    ret = malloc(sizeof(char) * 1);
    if (ret == 0)
        return print_error("Error : Cannot malloc the nbr flag result\n");
    ret[0] = '\0';
    if (cflags.rspace_pad[0] != '\0' || cflags.lzero_pad[0] != '\0')
        return ret;
    while (fmt[i] != '\0' && fmt[i] != '0' && cflags_stop(fmt[i]) == 0) {
        if (my_isnum(fmt[i]) && fmt[i] != '0') {
            free(ret);
            ret = get_nbr_lspace(fmt, &i, cflags);
        }
        i = i + 1;
    }
    return ret;
}

char *get_nbr_lspace(const char *format, int *i, char_flags_t cflags)
{
    int j = 0;
    int count = 0;
    char *ret;

    *i = *i - 1;
    count = get_count(format, &i, cflags);
    ret = malloc(sizeof(char) * (count + 1));
    if (ret == 0)
        return print_error("Error : Cannot malloc the nbr flag result\n");
    while (j < count) {
        ret[j] = ' ';
        j = j + 1;
    }
    ret[j] = '\0';
    return ret;
}

char *get_start_zero(const char *format, int i, char_flags_t cflags)
{
    char types[] = "oxXeEfFgGaAb\0";
    char *ret = malloc(sizeof(char) * 1);

    if (ret == 0)
        return print_error("Error : Cannot malloc the # flag result\n");
    ret[0] = '\0';
    if (is_part_of(types, cflags.type) == 0 || cflags.display_sign[0] != '\0')
        return ret;
    while (format[i] != '\0' && cflags_stop(format[i]) == 0) {
        if (format[i] == '#') {
            free(ret);
            ret = get_startz(cflags.content, cflags.type);
        }
        i = i + 1;
    }
    return ret;
}

char *get_startz(const char *content, const char *type)
{
    int i = 0;
    char *ret = malloc(sizeof(char) * 3);

    if (ret == 0)
        return print_error("Error : Cannot malloc the # flag result\n");
    for (int j = 0; j < 3; j = j + 1)
        ret[j] = '\0';
    if (type[0] == 'x' || type[0] == 'X') {
        ret[0] = '0';
        if (type[0] == 'X')
            ret[1] = 'X';
        else
            ret[1] = 'x';
    } else if (content[i] != (0 + 48))
        ret[0] = '0';
    return ret;
}

char *get_space_sign(const char *format, int i, char_flags_t cflags)
{
    char ok_types[] = "dieEfFgGaA\0";
    char *ret = malloc(sizeof(char) * 2);

    if (ret == 0)
        return print_error("Error : Cannot malloc the ' ' flag result\n");
    ret[0] = '\0';
    ret[1] = '\0';
    if (is_part_of(ok_types, cflags.type) == 0 || \
        cflags.display_sign[0] != '\0' || cflags.start_zero[0] != '\0')
        return ret;
    while (format[i] != '\0' && cflags_stop(format[i]) == 0) {
        if (format[i] == ' ' && cflags.content[0] != '-')
            ret[0] = ' ';
        i = i + 1;
    }
    return ret;
}
