/*
** EPITECH PROJECT, 2020
** My_strlen
** File description:
** Return the number of chars in a string
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return count;
}
