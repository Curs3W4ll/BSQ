/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Cflags management part 1
*/

#include "../my.h"

char *get_display_sign(const char *format, int i, char_flags_t cflags)
{
    char ok_types[] = "dieEfFgGaA\0";
    char *ret = malloc(sizeof(char) * 2);

    if (ret == 0)
        return print_error("Error : Cannot malloc the + flag result\n");
    ret[0] = '\0';
    ret[1] = '\0';
    if (is_part_of(ok_types, cflags.type) == 0)
        return ret;
    while (format[i] != '\0' && cflags_stop(format[i]) == 0) {
        if (format[i] == '+' && cflags.content[0] != '-')
            ret[0] = '+';
        i = i + 1;
    }
    return ret;
}

char *get_rspace_pad(const char *format, int i, char_flags_t cflags)
{
    char *ret = malloc(sizeof(char) * 1);

    if (ret == 0)
        return print_error("Error : Cannot malloc the - flag result\n");
    ret[0] = '\0';
    while (format[i] != '\0' && cflags_stop(format[i]) == 0) {
        if (format[i] == '-') {
            free(ret);
            ret = get_nbr_rspace(format, &i, cflags);
        }
        i = i + 1;
    }
    return ret;
}

char *get_nbr_rspace(const char *format, int *i, char_flags_t cflags)
{
    int j = 0;
    int count = get_count(format, &i, cflags);
    char *ret;

    ret = malloc(sizeof(char) * (count + 1));
    if (ret == 0)
        return print_error("Error : Cannot malloc the - flag result\n");
    while (j < count) {
        ret[j] = ' ';
        j = j + 1;
    }
    ret[j] = '\0';
    return ret;
}

char *get_lzero_pad(const char *format, int i, char_flags_t cflags)
{
    char ok_types[] = "diouxXeEfFgGaAb\0";
    char *ret;

    ret = malloc(sizeof(char) * 1);
    if (ret == 0)
        return print_error("Error : Cannot malloc the 0 flag result\n");
    ret[0] = '\0';
    if (is_part_of(ok_types, cflags.type) == 0 || cflags.rspace_pad[0] != '\0')
        return ret;
    while (format[i] != '\0' && cflags_stop(format[i]) == 0) {
        if (format[i] == '0') {
            free(ret);
            ret = get_nbr_lzero(format, &i, cflags);
        }
        i = i + 1;
    }
    return ret;
}

char *get_nbr_lzero(const char *format, int *i, char_flags_t cflags)
{
    int j = 0;
    int count = get_count(format, &i, cflags);
    char *ret;

    ret = malloc(sizeof(char) * (count + 1));
    if (ret == 0)
        return print_error("Error : Cannot 0 flag result\n");
    while (j < count) {
        ret[j] = '0';
        j = j + 1;
    }
    ret[j] = '\0';
    return ret;
}
