/*
** EPITECH PROJECT, 2020
** My_islower
** File description:
** Return 1 if the character is lowercase
*/

int my_islower(char const c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}
