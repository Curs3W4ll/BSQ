/*
** EPITECH PROJECT, 2020
** My_strlowcase
** File description:
** Put every letter of every word in lowercase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
}
