/*
** EPITECH PROJECT, 2020
** My_absolute
** File description:
** Return the absolute value of a number
*/

int my_absolute(int nbr)
{
    if (nbr < 0)
        nbr = nbr * -1;
    return nbr;
}
