/*
** EPITECH PROJECT, 2023
** placeholder
** File description:
** map in array
*/

#include "../include/my.h"

char **read_file_content(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    char buffer[32001] = {0};
    char **ret;
    int i = 0;

    if (fd < 0)
        return NULL;
    read(fd, buffer, 32000);
    ret = my_str_to_word_array_del(buffer, "\n");
    close(fd);
    for (; ret[i]; i++);
    if (i != 4)
        return NULL;
    return ret;
}

square_t **get_blank_map(void)
{
    square_t **map = malloc(sizeof(square_t *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(square_t) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = EMPTY;
        map[i][8] = OUT;
    }
    map[8] = 0;
    return map;
}

static int is_error_line(char *line)
{
    return my_strlen(line) != 7 || line[0] < 50 || line[0] > 53 ||
        line[1] != ':' || line[4] != ':' || line[2] < 65 || line[2] > 72 ||
        line[5] < 65 || line[5] > 72 || line[3] < 49 || line[3] > 56 ||
        line[6] < 49 || line[6] > 56;
}

static int is_wrong_size(const char *line, int size)
{
    int diff = 0;

    if (line[2] != line[5] && line[3] != line[6])
        return 1;
    diff = (line[2] - line[5]) + (line[3] - line[6]);
    if (diff < 0)
        diff *= -1;
    diff++;
    if (diff != size)
        return 1;
    return 0;
}

int check_size(char **content)
{
    int boat = 0;

    for (int i = 0; content[i]; i++) {
        if (is_error_line(content[i]) ||
            (my_pow(2, content[i][0] - 50) & boat) != 0 ||
            is_wrong_size(content[i], content[i][0] - 48))
            return 0;
        boat ^= my_pow(2, content[i][0] - 50);
    }
    if (boat != 0b1111)
        return 0;
    return 1;
}

static int fill_line(square_t **map, char *line, int length_diff,
    int height_diff)
{
    int lim = (length_diff + height_diff >= 0) ? length_diff + height_diff
        : -(length_diff + height_diff);
    int sign = (length_diff + height_diff >= 0) ? -1 : 1;
    square_t temp;

    for (int i = 0; i <= lim; i++) {
        temp = map[(line[3] - 49) + i * sign * (height_diff != 0)]
            [(line[2] - 65) + i * sign * (length_diff != 0)];
        if (temp == TWO || temp == THREE || temp == FOUR)
            return 84;
        map[(line[3] - 49) + i * sign * (height_diff != 0)]
            [(line[2] - 65) + i * sign * (length_diff != 0)] =
                ((length_diff + height_diff) * -sign) + 1;
    }
    return 0;
}

static int fill_map(square_t **map, char **content)
{
    int length_diff;
    int height_diff;

    if (!check_size(content))
        return 0;
    for (int i = 0; content[i]; i++) {
        length_diff = content[i][2] - content[i][5];
        height_diff = content[i][3] - content[i][6];
        if (fill_line(map, content[i], length_diff, height_diff) == 84)
            return 0;
    }
    return 1;
}

square_t **get_map(const char *filename)
{
    char **file_content = read_file_content(filename);
    square_t **map = get_blank_map();

    if (!file_content) {
        free(map);
        return NULL;
    }
    if (!fill_map(map, file_content)) {
        free(map);
        free(file_content);
        return NULL;
    }
    free(file_content);
    return map;
}
