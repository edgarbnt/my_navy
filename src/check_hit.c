/*
** EPITECH PROJECT, 2024
** B_PSU_100_LIL_1_1_navy_enzo_dubeaurepaire
** File description:
** check_hit.c
*/

#include "../include/my.h"

int check_hit(square_t **map, char const *hit)
{
    square_t hit_square = map[hit[1] - 49][hit[0] - 65];

    if (hit_square == TWO || hit_square == THREE || hit_square == FOUR
        || hit_square == FIVE) {
        map[hit[1] - 49][hit[0] - 65] = TOUCHED;
        return 1;
    }
    if (hit_square == TOUCHED)
        return 0;
    map[hit[1] - 49][hit[0] - 65] = MISSED;
    return 0;
}
