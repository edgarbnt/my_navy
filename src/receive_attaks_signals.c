/*
** EPITECH PROJECT, 2023
** receive attaks
** File description:
** placeholder
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handle_signal_attaks(int signo, siginfo_t *info, void *context)
{
    static int letter_count = 0;
    static int number_count = 0;
    static int sigusr2_count = 0;

    if (signo == SIGUSR1) {
        if (!sigusr2_count)
            letter_count++;
        if (sigusr2_count)
            number_count++;
    }
    if (signo == SIGUSR2) {
        sigusr2_count++;
        if (sigusr2_count >= 2) {
            interpret_attaks(letter_count, number_count, info->si_pid);
            sigusr2_count = 0;
            letter_count = 0;
            number_count = 0;
            loop_cond.loop_cond_receive_attaks = 1;
        }
    }
}

int waiting_signal_atttaks(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal_attaks;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (loop_cond.loop_cond_receive_attaks == 0);
    loop_cond.loop_cond_receive_attaks = 0;
    return 0;
}
