/*
** EPITECH PROJECT, 2020
** My_strcapitalize
** File description:
** Capitalize a string
*/

int test_if_first_letter_of_word(char const *str, int i);

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] + 32;
    for (int i = 0; str[i] != '\0'; i++)
        if (test_if_first_letter_of_word(str, i))
            str[i] = str[i] + 42;
    return str;
}

int test_if_first_letter_of_word(char const *str, int i)
{
    if (str[i] > 96 && str[i] < 123)
        if (i == 0 || (str[i - 1] < 97 && str[i - 1] > 122))
            return 1;
    return 0;
}
