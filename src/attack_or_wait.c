/*
** EPITECH PROJECT, 2023
** attack or wait
** File description:
** placeholder
*/

#include "../include/my.h"
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

void handle_signal_answer(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1) {
        loop_cond.loop_cond_receive_attaks = 1;
        write(1, "\nresult: ", 9);
        my_putchar(loop_cond.game->try_letter + 65);
        my_putchar(loop_cond.game->try_number + 49);
        write(1, ":hit\n", 5);
        loop_cond.game->enemy_map[loop_cond.game->try_number]
            [loop_cond.game->try_letter] = TOUCHED;
    }
    if (signo == SIGUSR2) {
        loop_cond.loop_cond_receive_attaks = 1;
        write(1, "\nresult: ", 9);
        my_putchar(loop_cond.game->try_letter + 65);
        my_putchar(loop_cond.game->try_number + 49);
        write(1, ":missed\n", 9);
        loop_cond.game->enemy_map[loop_cond.game->try_number]
            [loop_cond.game->try_letter] =
            (loop_cond.game->enemy_map[loop_cond.game->try_number]
            [loop_cond.game->try_letter] != TOUCHED) ? MISSED : TOUCHED;
    }
}

void wait_answer(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal_answer;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (loop_cond.loop_cond_receive_attaks == 0);
    loop_cond.loop_cond_receive_attaks = 0;
}

void attack_or_wait_player1(int pid_player2, game_t *game)
{
    for (int i = 0;; i++){
        if ((i % 2) == 0 || i == 0) {
            dump_game(game->my_map, game->enemy_map);
            write(1, "\nattack: ", 10);
            extract_input_player1(pid_player2);
            wait_answer();
        } else {
            write(1, "\nwaiting for enemy's attack...\n", 31);
            waiting_signal_atttaks();
        }
        if (check_lose(game->my_map)) {
            write(1, "\nEnemy won\n", 11);
            return;
        }
        if (check_lose(game->enemy_map)) {
            write(1, "\nI won\n", 7);
            return;
        }
    }
}

void attack_or_wait_player2(int pid_player2, game_t *game)
{
    for (int i = 0;; i++){
        if ((i % 2) != 0) {
            write(1, "\nattack: ", 10);
            extract_input_player2(pid_player2);
            wait_answer();
        } else {
            dump_game(game->my_map, game->enemy_map);
            write(1, "\nwaiting for enemy's attack...\n", 31);
            waiting_signal_atttaks();
        }
        if (check_lose(game->my_map)) {
            write(1, "\nEnemy won\n", 11);
            return;
        }
        if (check_lose(game->enemy_map)) {
            write(1, "\nI won\n", 7);
            return;
        }
    }
}
