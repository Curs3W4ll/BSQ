/*
** EPITECH PROJECT, 2020
** My_isupper
** File description:
** Return 1 if the character is uppercase
*/

int my_str_isupper(char const c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
