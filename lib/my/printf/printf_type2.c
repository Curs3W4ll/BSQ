/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Printf type display function part 2
*/

#include "../my.h"

int print_str_ascii(va_list ap, int i, const char *format, int j)
{
    char *res = va_arg(ap, char *);
    char *str = get_ascii_str(res);
    char *type = malloc(sizeof(char) * 2);
    char_flags_t cflags;

    if (str == 0 || type == 0)
        return -1;
    type[0] = format[j];
    type[1] = '\0';
    cflags.type = type;
    prepare_struct(format, i, &cflags, str);
    if (print_struct(cflags) == -1)
        return -1;
    return j;
}

char *get_ascii_str(char *str)
{
    int i = 0;
    int not_printable = count_nonprintable(str) * 3;
    char *ret = malloc(sizeof(char) * (my_strlen(str) + not_printable + 1));

    if (ret == 0)
        return print_error("Error : Cannot malloc the ascii format str\n");
    for (int y = 0; str[y] != '\0'; y = y + 1) {
        if (my_isprintable(str[y]))
            ret[i] = str[y];
        else
            i = put_ascii_number(&ret, str[y], i);
        i = i + 1;
    }
    ret[i] = '\0';
    return ret;
}

int put_ascii_number(char **ret, char c, int i)
{
    int ascii_code = c;
    int y = i + 3;

    (*ret)[i] = '\\';
    i = i + 1;
    while (ascii_code > 9) {
        (*ret)[y] = (ascii_code % 10) + 48;
        y = y - 1;
        ascii_code = ascii_code / 10;
    }
    (*ret)[y] = ascii_code + 48;
    y = y - 1;
    while (y >= i) {
        (*ret)[y] = '0';
        y = y - 1;
    }
    return i + 2;
}

int print_binary(va_list ap, int i, const char *format, int j)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = get_binary_base(nbr);
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

int print_octal(va_list ap, int i, const char *format, int j)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = get_octal_base(nbr);
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
