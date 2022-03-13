/*
** EPITECH PROJECT, 2020
** Task02/My.h
** File description:
** Contains all the prototypes of the mylib functions
*/

#ifndef MYLIB
#define MYLIB

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "struct.h"

ssize_t write(int fd, const void *buf, size_t count);
void my_putchar(char c);
int my_isneg(int nb);
int my_absolute(int nbr);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
unsigned long my_compute_power_recul(unsigned int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_isalpha(char const c);
int my_isnum(char const c);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_islower(char const c);
int my_str_isupper(char const *str);
int my_isupper(char const c);
int my_isprintable(char const c);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
int is_alpha(char c);
int calc_char_word(char const *str, int i);
int calc_number_cases(char const *str);
char **write_tab(char const *str, char **tab, int i, int j);
int calc_char_word(char const *str, int i);
int calc_number_cases(char const *str);
int test_if_first_letter_of_word(char const *str, int i);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);
void my_sort_word_array(char **tab);
int test_swap(char *s1, char *s2);

int my_printf(const char *format, ...);
int print_next_perc(va_list ap, const char *format);
int find_asked_format(va_list ap, const char *format, int i);
int print_without_type(const char *format, int i, int j);
int print_int(va_list ap, int i, const char *format, int j);
int print_char(va_list ap, int i, const char *format, int j);
int print_str(va_list ap, int i, const char *format, int j);
int print_perc(va_list ap, int i, const char *format, int j);
int print_str_ascii(va_list ap, int i, const char *format, int j);
char *get_ascii_str(char *str);
int put_ascii_number(char **ret, char c, int i);
int print_binary(va_list ap, int i, const char *format, int j);
int print_octal(va_list ap, int i, const char *format, int j);
int print_decimal(va_list ap, int i, const char *format, int j);
int print_minihexa(va_list ap, int i, const char *format, int j);
int print_maxihexa(va_list ap, int i, const char *format, int j);
int print_pointer(va_list ap, int i, const char *format, int j);
char *get_binary_base(unsigned int nbr);
char *get_octal_base(unsigned int nbr);
char get_acode(int count, int plus);
char *get_hexa_base(unsigned long nbr, int plus);
char *get_display_sign(const char *format, int i, char_flags_t cflags);
char *get_rspace_pad(const char *format, int i, char_flags_t cflags);
char *get_nbr_rspace(const char *format, int *i, char_flags_t cflags);
char *get_lzero_pad(const char *format, int i, char_flags_t cflags);
char *get_nbr_lzero(const char *format, int *i, char_flags_t cflags);
char *get_lspace_pad(const char *fmt, int i, char_flags_t cflags);
char *get_nbr_lspace(const char *format, int *i, char_flags_t cflags);
char *get_start_zero(const char *format, int i, char_flags_t cflags);
char *get_startz(const char *content, char const *type);
char *get_space_sign(const char *format, int i, char_flags_t cflags);
int prepare_struct(const char *format, int i, char_flags_t *cflags, char *str);
int print_struct(char_flags_t cflags);
int free_struct(char_flags_t cflags);
int cflags_stop(char c);
int my_nbr_num(int nbr);
char *my_int_to_str(int nbr);
char *my_uint_to_str(unsigned int nbr);
int get_count(const char *format, int **i, char_flags_t cflags);
int is_cflags(char c);
int is_part_of(char *dict, char *c);
int count_nonprintable(char *str);
char *add_to_start_str(char *str, char *add);
int my_ishexa(const char c);
char *print_error(const char *str);

#endif
