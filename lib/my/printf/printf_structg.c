/*
** EPITECH PROJECT, 2020
** Printf
** File description:
** Struct management
*/

#include "../my.h"

int prepare_struct(const char *format, int i, char_flags_t *cflags, char *str)
{
    cflags->content = str;
    cflags->display_sign = get_display_sign(format, i, *cflags);
    cflags->start_zero = get_start_zero(format, i, *cflags);
    cflags->space_sign = get_space_sign(format, i, *cflags);
    cflags->rspace_pad = get_rspace_pad(format, i, *cflags);
    cflags->lzero_pad = get_lzero_pad(format, i, *cflags);
    cflags->lspace_pad = get_lspace_pad(format, i, *cflags);
    if (cflags->display_sign == "-1" || cflags->start_zero == "-1" || \
        cflags->space_sign == "-1" || cflags->rspace_pad == "-1" || \
        cflags->lzero_pad == "-1" || cflags->lspace_pad == "-1")
        return -1;
    return 0;
}

int print_struct(char_flags_t cflags)
{
    char neg_types[] = "dieEfFgGaA\0";
    int neg = 0;

    if (is_part_of(neg_types, cflags.type) == 1 && cflags.content[0] == '-')
        neg = 1;
    my_putstr(cflags.lspace_pad);
    if (neg == 1)
        my_putchar(cflags.content[0]);
    my_putstr(cflags.display_sign);
    my_putstr(cflags.space_sign);
    my_putstr(cflags.lzero_pad);
    my_putstr(cflags.start_zero);
    if (neg == 1)
        my_putstr(&cflags.content[1]);
    else
        my_putstr(cflags.content);
    my_putstr(cflags.rspace_pad);
    return (free_struct(cflags));
}

int free_struct(char_flags_t cflags)
{
    free(cflags.type);
    free(cflags.content);
    free(cflags.lspace_pad);
    free(cflags.rspace_pad);
    free(cflags.start_zero);
    free(cflags.lzero_pad);
    free(cflags.display_sign);
    free(cflags.space_sign);
    return 0;
}
