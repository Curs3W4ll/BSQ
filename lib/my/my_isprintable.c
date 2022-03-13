/*
** EPITECH PROJECT, 2020
** My_isprintable
** File description:
** Return 1 if the char is printable
*/

int my_isprintable(char const c)
{
    if (c >= ' ' && c <= '~')
        return 1;
    return 0;
}
