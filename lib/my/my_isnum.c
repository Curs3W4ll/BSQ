/*
** EPITECH PROJECT, 2020
** My_isnum
** File description:
** Return 1 if the character is a digit
*/

int my_isnum(char const c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
