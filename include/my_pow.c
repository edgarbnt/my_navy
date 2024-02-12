/*
** EPITECH PROJECT, 2024
** B_PSU_100_LIL_1_1_navy_enzo_dubeaurepaire
** File description:
** my_pow.c
*/

int my_pow(int base, int power)
{
    int ret = 1;

    for (int i = 0; i < power; i++) {
        ret *= base;
    }
    return ret;
}
