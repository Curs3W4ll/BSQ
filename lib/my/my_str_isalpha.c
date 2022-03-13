/*
** EPITECH PROJECT, 2020
** My_str_isalpha
** File description:
** Return 1 if the string contain only alphabetical characters
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
    return 1;
}
