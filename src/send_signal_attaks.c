/*
** EPITECH PROJECT, 2023
** attacks signals
** File description:
** plaecholder
*/

#include "../include/my.h"
#include <unistd.h>

void send_signals_attacks_player2(char *userinput, int pid_player1)
{
    for (int i = 0; i < userinput[0] - 64; i++) {
        kill(pid_player1, SIGUSR1);
        usleep(10000);
    }
    kill(pid_player1, SIGUSR2);
    usleep(1000);
    for (int i = 0; i < (userinput[1] - 48); i++) {
        kill(pid_player1, SIGUSR1);
        usleep(10000);
    }
    kill(pid_player1, SIGUSR2);
}

void send_signals_attacks_player1(char *userinput, int pid_player2)
{
    for (int i = 0; i < userinput[0] - 64; i++) {
        kill(pid_player2, SIGUSR1);
        usleep(10000);
    }
    kill(pid_player2, SIGUSR2);
    usleep(1000);
    for (int i = 0; i < (userinput[1] - 48); i++) {
        kill(pid_player2, SIGUSR1);
        usleep(10000);
    }
    kill(pid_player2, SIGUSR2);
}
