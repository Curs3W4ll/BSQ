/*
** EPITECH PROJECT, 2020
** My_swap_char
** File description:
** Swap content of two char
*/

void my_swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}
