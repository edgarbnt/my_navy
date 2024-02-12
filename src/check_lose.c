/*
** EPITECH PROJECT, 2024
** B_PSU_100_LIL_1_1_navy_enzo_dubeaurepaire
** File description:
** check_lose.c
*/

#include "../include/my.h"

int check_lose(square_t **map)
{
    int touched_count = 0;

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j] != OUT; j++)
            touched_count += (map[i][j] == TOUCHED) ? 1 : 0;
    if (touched_count == 14)
        return 1;
    return 0;
}
