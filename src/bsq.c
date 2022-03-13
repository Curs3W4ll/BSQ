/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Main calls
*/

#include "main.h"

int check_errors(const char *buf)
{
    if (check_firstline(buf) == -1 || check_len(buf) == -1)
        return 1;
    return 0;
}

int run_bsq(int ac, char *path)
{
    file_stats_t file;
    bsq_stats_t bsq;

    if (ac < 2)
        return 84;
    if (set_map(path, &file) == 84)
        return 84;
    if (get_bsq(file, &bsq) == -1)
        return 84;
    print_solved_map(file, bsq);
    free_2d_array(file.map, file.nbr_rows);
    return 0;
}
