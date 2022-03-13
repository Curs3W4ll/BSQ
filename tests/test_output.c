/*
** EPITECH PROJECT, 2020
** Tests
** File description:
** Criterion tests for output of bsq
*/

#include "main.h"
#include "test.h"

Test(test_basic_output, intermediate_map_100_100, .init = redirect_all_std)
{
    char *filepath = "tests/solved_maps/intermediate_map_100_100";
    int fd = open(filepath, O_RDONLY);
    char *buf;
    struct stat sb;

    stat(filepath, &sb);
    buf = get_solved_file(fd, sb.st_size);
    run_bsq(2, "tests/maps/intermediate_map_100_100");
    cr_assert_stdout_eq_str(buf);
    close(fd);
    free(buf);
}
