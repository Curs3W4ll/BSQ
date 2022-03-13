/*
** EPITECH PROJECT, 2020
** My_str_isnum
** File description:
** Return 1 if the string only contain digits
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
            return 0;
    return 1;
}
