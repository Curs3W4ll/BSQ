/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Printf type display function part 1
*/

#include "../my.h"

int print_int(va_list ap, int i, const char *format, int j)
{
    int nbr = va_arg(ap, int);
    char *str = my_int_to_str(nbr);
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    if (str == 0 || prepare_struct(format, i, &cflags, str) == -1 || \
        print_struct(cflags) == -1)
        return -1;
    return j;
}

int print_char(va_list ap, int i, const char *format, int j)
{
    unsigned char c = va_arg(ap, int);
    char *str = malloc(sizeof(char) * 2);
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (str == 0 || type == 0)
        return -1;
    str[0] = c;
    str[1] = '\0';
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}

int print_str(va_list ap, int i, const char *format, int j)
{
    char *str = my_strdup(va_arg(ap, char *));
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (type == 0)
        return -1;
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}

int print_perc(va_list ap, int i, const char *format, int j)
{
    my_putchar('%');
    return j;
}
