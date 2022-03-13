/*
** EPITECH PROJECT, 2020
** My_str_to_word_array
** File description:
** Stock a string in an array of words
*/

#include "my.h"

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int i = 0;
    int j = 0;

    tab = malloc(sizeof(char*) * calc_number_cases(str));
    if (!my_isalpha(str[0]))
        j = -1;
    write_tab(str, tab, i, j);
    return tab;
}

char **write_tab(char const *str, char **tab, int i, int j)
{
    int y;

    while (str[i] != '\0') {
        if (j >= 0)
            tab[j] = malloc(sizeof(char) * calc_char_word(str, i));
        y = 0;
        while (my_isalpha(str[i])) {
            tab[j][y] = str[i];
            i++;
            y++;
        }
        if (j >= 0)
            tab[j][y] = '\0';
        while (!my_isalpha(str[i]) && str[i] != '\0')
            i++;
        j++;
    }
    tab[j] = 0;
    return tab;
}

int calc_number_cases(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isalpha(str[i]))
            count++;
    return (count + 1);
}

int calc_char_word(char const *str, int i)
{
    int count = 0;

    while (my_isalpha(str[i + count]))
        count++;
    return (count + 1);
}
