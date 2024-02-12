/*
** EPITECH PROJECT, 2023
** handle signals
** File description:
** placeholder
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdlib.h>

void player2_signals(int pid_player1, signal_t *signal_info)
{
    pid_t process_info = getpid();

    write(1, "my_pid: ", 8);
    my_putnbr(process_info);
    write(1, "\n", 1);
    kill(pid_player1, SIGUSR1);
    signal_info->player2_pid = (int) process_info;
}

int find_player1_pid(signal_t *signal_info)
{
    pid_t process_info = getpid();

    write(1, "my_pid: ", 8);
    my_putnbr(process_info);
    write(1, "\n", 2);
    return (int)process_info;
}

void launch_fonction_connecting(int argc, char **argv, signal_t *signal_info,
    game_t *game)
{
    player_t *player_info = malloc(sizeof(player_t));
    int player1_pid;
    int player2_pid;

    if (argc == 2) {
        player_info->is_palyer1 = 1;
        find_player1_pid(signal_info);
        player2_pid = waiting_signal_connection(signal_info);
        attack_or_wait_player1(player2_pid, game);
    }
    if (argc == 3) {
        player_info->is_player2 = 1;
        player2_signals(my_getnbr(argv[1]), signal_info);
        player1_pid = init_sigaction_player2();
        attack_or_wait_player2(player1_pid, game);
    }
}

int main(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));
    signal_t *signal_info = malloc(sizeof(signal_t));

    loop_cond.game = game;
    if (argc != 2 && argc != 3)
        return 84;
    if (argc == 2)
        game->my_map = get_map(argv[1]);
    else
        game->my_map = get_map(argv[2]);
    if (!(game->my_map))
        return 84;
    game->enemy_map = get_blank_map();
    launch_fonction_connecting(argc, argv, signal_info, game);
    free(game);
    return 0;
}
