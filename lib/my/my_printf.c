/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Main file for my_printf
*/

#include "my.h"

int my_printf(const char *format, ...)
{
    int ret;
    va_list ap;

    va_start(ap, format);
    ret = print_next_perc(ap, format);
    if (ret = 84)
        return 84;
    va_end(ap);
    return 0;
}

int print_next_perc(va_list ap, const char *format)
{
    int i = 0;
    int j = 0;

    while (format[i] != '\0') {
        if (format[i] == '%')
            i = find_asked_format(ap, format, i);
        else {
            my_putchar(format[i]);
        }
        if (i == -1)
            return 84;
        i = i + 1;
    }
    return 0;
}

int find_asked_format(va_list ap, const char *format, int i)
{
    int y = 0;
    int j = i + 1;
    int asked = -1;
    char type[] = {"dics%SbouxXp\0"};
    int(*(print_format[13]))(va_list ap, int i, const char *format, int j) = \
{&print_int, &print_int, &print_char, &print_str, &print_perc, \
&print_str_ascii, &print_binary, &print_octal, &print_decimal, \
&print_minihexa, &print_maxihexa, &print_pointer, 0};

    while (is_cflags(format[j]) == 1 && format[j] != '\0')
        j = j + 1;
    while (type[y] != 0) {
        if (format[j] == type[y])
            asked = y;
        y = y + 1;
    }
    if (asked == -1)
        return (print_without_type(format, i, j));
    return (print_format[asked](ap, i + 1, format, j));
}

int print_without_type(const char *format, int i, int j)
{
    for (int y = i; y <= j; y = y + 1)
        my_putchar(format[y]);
    return j;
}
