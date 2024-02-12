/*
** EPITECH PROJECT, 2023
** connection signals
** File description:
** placeholder
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>

loop_cond_t loop_cond = {.pid_player2 = 0, .pid_player1 = 0, .sig = 0,
    .loop_cond_receive_attaks = 0};

void handle_signal_connection(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1 && loop_cond.sig == 0) {
        write(1, "\nenemy connected\n", 18);
        loop_cond.sig = 1;
        loop_cond.pid_player2 = info->si_pid;
        kill(info->si_pid, SIGUSR2);
    }
}

int waiting_signal_connection(signal_t *signal_info)
{
    struct sigaction sa;

    write(1, "waiting for enemy connection...\n", 33);
    while (loop_cond.sig == 0) {
        sa.sa_sigaction = handle_signal_connection;
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR2, &sa, NULL);
        sigaction(SIGUSR1, &sa, NULL);
    }
    return loop_cond.pid_player2;
}

void handle_sigusr1_player2(int signo, siginfo_t *info, void *context)
{
    static int cnt = 0;

    if (signo == SIGUSR2) {
        cnt++;
        if (cnt == 1)
            write(1, "successfully connected\n", 24);
        loop_cond.sig = 2;
    }
    loop_cond.pid_player1 = info->si_pid;
}

int init_sigaction_player2(void)
{
    struct sigaction sa_player2;

    while (loop_cond.sig == 0 || loop_cond.sig == 1) {
        sa_player2.sa_sigaction = handle_sigusr1_player2;
        sa_player2.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR2, &sa_player2, NULL);
        sigaction(SIGUSR1, &sa_player2, NULL);
    }
    return loop_cond.pid_player1;
}
