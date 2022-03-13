/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Tools functions
*/

#include "main.h"

int get_nbr_cols(const char *buf)
{
    int i = 0;
    int nbr_cols = 0;

    while (buf[i] != '\n') {
        if (buf[i] == '\0')
            return -1;
        i = i + 1;
    }
    i = i + 1;
    while (buf[i] != '\n' && buf[i] != '\0') {
        i = i + 1;
        nbr_cols = nbr_cols + 1;
    }
    return nbr_cols;
}

int print_errors(char *str)
{
    write(2, str, my_strlen(str));
    return -1;
}

void put_bsq_in_solved(file_stats_t *file, bsq_stats_t bsq)
{
    int row = 0;

    while (row < bsq.row_pos)
        row = row + 1;
    while (row < (bsq.row_pos + bsq.size)) {
        for (int i = bsq.col_pos; i < (bsq.col_pos + bsq.size); i = i + 1) {
            file->map[row][i] = 'x';
        }
        row = row + 1;
    }
}

void print_solved_map(file_stats_t file, bsq_stats_t bsq)
{
    int row = 0;

    put_bsq_in_solved(&file, bsq);
    while (row < file.nbr_rows) {
        my_printf("%s\n", file.map[row]);
        row = row + 1;
    }
}
