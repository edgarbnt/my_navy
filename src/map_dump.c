/*
** EPITECH PROJECT, 2024
** B_PSU_100_LIL_1_1_navy_enzo_dubeaurepaire
** File description:
** map_dump.c
*/

#include "../include/my.h"

void show_square(square_t **map, int i, int j)
{
    if (map[i][j] == EMPTY)
        write(1, ".", 1);
    if (map[i][j] == TWO)
        write(1, "2", 1);
    if (map[i][j] == THREE)
        write(1, "3", 1);
    if (map[i][j] == FOUR)
        write(1, "4", 1);
    if (map[i][j] == FIVE)
        write(1, "5", 1);
    if (map[i][j] == TOUCHED)
        write(1, "x", 1);
    if (map[i][j] == MISSED)
        write(1, "o", 1);
    if (j == 7)
        write(1, "\n", 1);
    if (j != 7)
        write(1, " ", 1);
}

void dump_map(square_t **map)
{
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 1; i < 9; i++) {
        my_putnbr(i);
        write(1, "|", 1);
        for (int j = 0; j < 8; j++) {
            show_square(map, i - 1, j);
        }
    }
}

void dump_game(square_t **my_map, square_t **enemy_map)
{
    write(1, "my navy:\n", 9);
    dump_map(my_map);
    write(1, "\nenemy navy:\n", 13);
    dump_map(enemy_map);
}
