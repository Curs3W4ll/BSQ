/*
** EPITECH PROJECT, 2020
** My_str_numlen
** File description:
** Return the number of digits in a string
*/

int my_str_numlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0')
        if (str[i] >= '0' && str[i] <= '9')
            count++;
    return count;
}
