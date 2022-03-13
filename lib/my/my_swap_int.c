/*
** EPITECH PROJECT, 2020
** My_swap_int
** File description:
** Swap content of two integers
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
