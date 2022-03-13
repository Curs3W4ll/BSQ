/*
** EPITECH PROJECT, 2020
** My_isalpha
** File description:
** Return 1 if the character is alphabetical
*/

int my_isalpha(char const c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
