/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Part 3 of printf types
*/

#include "../my.h"

int print_decimal(va_list ap, int i, const char *format, int j)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = my_uint_to_str(nbr);
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (type == 0 || str[0] == '-')
        return -1;
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}

int print_minihexa(va_list ap, int i, const char *format, int j)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = get_hexa_base(nbr, 32);
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (type == 0 || str[0] == '-')
        return -1;
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}

int print_maxihexa(va_list ap, int i, const char *format, int j)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = get_hexa_base(nbr, 0);
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (type == 0 || str[0] == '-')
        return -1;
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}

int print_pointer(va_list ap, int i, const char *format, int j)
{
    int pos = 2;
    unsigned long nbr = (unsigned long) va_arg(ap, void*);
    char *str = add_to_start_str(get_hexa_base(nbr, 32), "0x");
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (type == 0 || str[0] == '-')
        return -1;
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}
