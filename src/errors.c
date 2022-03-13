/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Check errors functions
*/

#include "main.h"

int check_firstline(const char *buf)
{
    for (int i = 0; buf[i] != '\n' && buf[i] != '\0'; i = i + 1)
        if (my_isnum(buf[i]) == 0)
            return print_errors("Error : \
The first line of the file is incorrect");
    return 0;
}

int check_character(const char c)
{
    if (c != 'o' && c != '.' && c != '\n')
        return print_errors("Error : \
One of the character is not 'o' or '.'\n");
    return 0;
}

int check_col_len(int col_len, int *rows, int *count, const char c)
{
    if (c == '\n') {
        if (*count != col_len)
            return print_errors("Error : \
One of the line contain less or more characters than the others\n");
        *count = -1;
        *rows = *rows + 1;
    }
    return 0;
}

int check_len(const char *buf)
{
    int i = 0;
    int col_len = 0;
    int row_len = my_getnbr(buf);

    while (buf[i] != '\n' && buf[i] != '\0')
        i = i + 1;
    if (buf[i] == '\0')
        return print_errors("Error : The map is empty\n");
    i = i + 1;
    for (int j = i; buf[j] != '\n' && buf[j] != '\0'; j = j + 1)
        col_len = col_len + 1;
    if (check_every_chars(buf, i, row_len, col_len) == -1)
        return -1;
    return 0;
}

int check_every_chars(const char *buf, int i, int row_len, int col_len)
{
    int count = 0;
    int rows = 0;

    while (buf[i] != '\0') {
        if (check_character(buf[i]) == -1)
            return -1;
        if (check_col_len(col_len, &rows, &count, buf[i]) == -1)
            return -1;
        count = count + 1;
        i = i + 1;
    }
    if (rows != row_len)
        return print_errors("Error : \
There is too less lines in the file\n");
    return 0;
}
