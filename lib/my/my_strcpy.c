/*
** EPITECH PROJECT, 2020
** My_strcpy
** File description:
** Copy a string into another
*/

void my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
