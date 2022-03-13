/*
** EPITECH PROJECT, 2020
** My_sort_word_array
** File description:
** Sort an array of words in ascii order
*/

#include "my.h"

void my_sort_word_array(char **tab)
{
    char *tmp;

    for (int i = 0; tab[i + 1] != 0; i++) {
        if (test_swap(tab[i], tab[i + 1])) {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            my_sort_word_array(tab);
        }
    }
}

int test_swap(char *s1, char *s2)
{
    int dif = 0;

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && !dif; i++) {
        if (s1[i] > s2[i]) {
            dif = 1;
            return 1;
        } else if (s1[i] < s2[i])
            dif = 1;
    }
    return 0;
}
