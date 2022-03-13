/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** Management of the file (set the file stats)
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

char *get_file(int fd, off_t size)
{
    int rd;
    char *buf = malloc(sizeof(char) * (size + 1));

    if (buf == 0) {
        print_errors("Error : Cannot malloc buffer of file\n");
        return "-1";
    }
    rd = read(fd, buf, size);
    if (rd < 0 || check_errors(buf) == 1)
        return "-1";
    return buf;
}

char **put_into_2d(char *buf, int nb_rows, int nb_cols)
{
    int y = 0;
    int j = 0;
    char **map = mem_alloc_2d_array(nb_rows, nb_cols);

    while (buf[y] != '\n')
        y = y + 1;
    y = y + 1;
    for (int i = 0; i < nb_rows; i = i + 1){
        j = 0;
        while (j < nb_cols && buf[y] != '\n' && buf[y] != '\0') {
            map[i][j] = buf[y];
            y = y + 1;
            j = j + 1;
        }
        map[i][j] = '\0';
        y = y + 1;
    }
    return map;
}

int set_map(char const *filepath, file_stats_t *file)
{
    int fd = open(filepath, O_RDONLY);
    char *buf;
    struct stat sb;

    if (fd <= 0)
        return 84;
    stat(filepath, &sb);
    buf = get_file(fd, sb.st_size);
    if (buf[0] == '-')
        return 84;
    file->nbr_rows = my_getnbr(buf);
    file->nbr_cols = get_nbr_cols(buf);
    if (file->nbr_rows < 1 || file->nbr_cols < 1)
        return 84;
    file->map = put_into_2d(buf, file->nbr_rows, file->nbr_cols);
    free(buf);
    close(fd);
    return 0;
}
