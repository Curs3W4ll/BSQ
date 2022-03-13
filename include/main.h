/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Main prototypes of BSQ project and other includes
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "my.h"

typedef struct file_stats {
    int nbr_rows;
    int nbr_cols;
    char **map;
} file_stats_t;

typedef struct biggest_square_stats {
    int row_pos;
    int col_pos;
    int size;
} bsq_stats_t;

typedef struct test_biggest_square {
    int row_pos;
    int col_pos;
} bsq_tests_t;

int run_bsq(int ac, char *path);
int check_errors(const char *buf);
int check_firstline(const char *buf);
int check_character(const char c);
int check_col_len(int col_len, int *rows, int *count, const char c);
int check_len(const char *buf);
int check_every_chars(const char *buf, int i, int row_len, int col_len);
int get_nbr_cols(const char *buf);
int print_errors(char *str);
void put_bsq_in_solved(file_stats_t *file, bsq_stats_t bsq);
void print_solved_map(file_stats_t file, bsq_stats_t bsq);
char *get_file(int fd, off_t size);
char **put_into_2d(char *buf, int nb_rows, int nb_cols);
int set_map(char const *filepath, file_stats_t *file);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void free_2d_array(char **arr, int nb_rows);
int is_row(char **map, int rpos, int cpos, int size);
int is_square(file_stats_t file, int rpos, int cpos, int size);
int is_empty(file_stats_t file, bsq_stats_t bsq, bsq_tests_t *test);
int get_bsq(file_stats_t file, bsq_stats_t *bsq);
void update_test(char **map, int nbr_rows, bsq_tests_t *test, int size);
void update_bsq(bsq_tests_t test, bsq_stats_t *bsq);

#endif /* MAIN_H_ */
