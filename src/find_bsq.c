/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Find bsq functions
*/

#include "main.h"

int is_row(char **map, int rpos, int cpos, int size)
{
    for (int i = cpos; i < cpos + size; i = i + 1)
        if (map[rpos][i] != '.')
            return 0;
    return 1;
}

int is_square(file_stats_t file, int rpos, int cpos, int size)
{
    int tested = 0;

    for (int i = rpos + 1; i < rpos + size && i < file.nbr_rows; i = i + 1) {
        if (is_row(file.map, i, cpos, size) == 0)
            return 0;
        tested = tested + 1;
    }
    if (tested != size - 1)
        return 0;
    return 1;
}

int is_empty(file_stats_t file, bsq_stats_t bsq, bsq_tests_t *test)
{
    if (is_row(file.map, test->row_pos, test->col_pos, bsq.size + 1) == 1) {
        if (is_square(file, test->row_pos, test->col_pos, bsq.size + 1) == 1)
            return 1;
        else
            update_test(file.map, file.nbr_rows, test, 1);
    } else
        update_test(file.map, file.nbr_rows, test, bsq.size + 1);
    return 0;
}

int get_bsq(file_stats_t file, bsq_stats_t *bsq)
{
    int empty;
    bsq_tests_t test;

    bsq->size = 0;
    bsq->row_pos = 0;
    bsq->col_pos = 0;
    test.row_pos = 0;
    test.col_pos = 0;
    while (test.row_pos < file.nbr_rows && test.col_pos < file.nbr_cols) {
        empty = is_empty(file, *bsq, &test);
        if (empty == 1)
            update_bsq(test, bsq);
        else if (empty == -1)
            return (print_errors("Error : Cannot get biggest square\n"));
    }
    return 0;
}
