/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Prototypes of criterion functions
*/

#ifndef BSQ
#define BSQ

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void redirect_all_std(void);
char *get_solved_file(int fd, off_t sixe);

#endif /* BSQ */
