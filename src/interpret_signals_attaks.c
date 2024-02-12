/*
** EPITECH PROJECT, 2023
** interpret signals
** File description:
** plaecholder;
*/

#include "../include/my.h"
#include <unistd.h>

void interpret_attaks(int letter_count, int number_count, int pid)
{
    char letter = letter_count + 64;
    char number = number_count + 48;
    char *hit = malloc(2);

    hit[0] = letter;
    hit[1] = number;
    write(1, "\nresult: ", 9);
    write(1, &letter, 1);
    write(1, &number, 1);
    if (check_hit(loop_cond.game->my_map, hit)) {
        write(1, ":hit\n", 5);
        kill(pid, SIGUSR1);
    } else {
        write(1, ":missed\n", 8);
        kill(pid, SIGUSR2);
    }
    free(hit);
}
