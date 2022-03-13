/*
** EPITECH PROJECT, 2020
** My_sort_int_array
** File description:
** Sort an integer array in ascending order
*/

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int tmp;

    while (i + 1 < size && tab[i] <= tab[i + 1])
        i++;
    if (i + 1 < size) {
        tmp = tab[i];
        tab[i] = tab[i + 1];
        tab[i + 1] = tmp;
        my_sort_int_array(tab, size);
    }
}
