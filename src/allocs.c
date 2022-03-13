/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Alloc and free mem functions
*/

#include <stdlib.h>
#include "main.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr;
    int y = 0;

    arr = malloc(sizeof(char*) * (nb_rows + 1));
    while (y < nb_rows) {
        arr[y] = malloc(sizeof(char) * (nb_cols + 1));
        y++;
    }
    arr[y] = 0;
    return arr;
}

void free_2d_array(char **arr, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        free(arr[i]);
    free(arr);
}
