/*
** EPITECH PROJECT, 2020
** My_str_isprintable
** File description:
** Return 1 if the string contain only printable character
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < ' ' || str[i] > '~')
            return 0;
    return 1;
}
