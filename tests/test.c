/*
** EPITECH PROJECT, 2020
** Tests
** File description:
** Criterion tests
*/

#include "main.h"
#include "test.h"

void redirect_all_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

char *get_solved_file(int fd, off_t size)
{
    int rd;
    char *buf = malloc(sizeof(char) * (size + 1));

    if (buf == 0) {
        print_errors("Error : Cannot malloc buffer of file\n");
        return "-1";
    }
    rd = read(fd, buf, size);
    if (rd < 0) {
        print_errors("Error : Cannot open file");
        return "-1";
    }
    return buf;
}
