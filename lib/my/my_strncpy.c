/*
** EPITECH PROJECT, 2020
** My_strncpy
** File description:
** Copy n characters from a string into another
*/

void my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    while (i < n) {
        dest[i] = '\0';
        i = i + 1;
    }
}
