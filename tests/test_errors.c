/*
** EPITECH PROJECT, 2020
** Tests
** File description:
** Tests the error cases
*/

#include "main.h"
#include "test.h"

Test(test_error_output, empty_map, .init = redirect_all_std)
{
    run_bsq(2, "tests/maps/empty_map");
    cr_assert_stderr_eq_str("Error : There is too less lines in the file\n");
}

Test(test_error_output, invalid_number, .init = redirect_all_std)
{
    run_bsq(2, "tests/maps/invalid_number");
    cr_assert_stderr_eq_str("Error : The first line of the file is incorrect\n");
}

Test(test_error_output, invalid_column, .init = redirect_all_std)
{
    run_bsq(2, "tests/maps/invalid_column");
    cr_assert_stderr_eq_str("Error : One of the line contain less or more characters than the others\n");
}

Test(test_error_output, invalid_char, .init = redirect_all_std)
{
    run_bsq(2, "tests/maps/invalid_char");
    cr_assert_stderr_eq_str("Error : One of the character is not 'o' or '.'\n");
}
