/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Update the struct
*/

#include "main.h"

void update_test(char **map, int nbr_rows, bsq_tests_t *test, int size)
{
    int rpos = test->row_pos;
    int i = test->col_pos + 1;

    while (rpos < nbr_rows && (map[rpos][i] != '.' || \
        (i < test->col_pos + size && test->row_pos == rpos))) {
        if (map[rpos][i] == '\0') {
            rpos = rpos + 1;
            i = 0;
        } else
            i = i + 1;
    }
    test->row_pos = rpos;
    test->col_pos = i;
}

void update_bsq(bsq_tests_t test, bsq_stats_t *bsq)
{
    bsq->size = bsq->size + 1;
    bsq->row_pos = test.row_pos;
    bsq->col_pos = test.col_pos;
}
