/*
** EPITECH PROJECT, 2024
** B_PSU_100_LIL_1_1_navy_enzo_dubeaurepaire
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #define FILE_SIZE 1024
    #include "../lib/lib.h"

typedef enum {
    OUT,
    EMPTY,
    TWO,
    THREE,
    FOUR,
    FIVE,
    TOUCHED,
    MISSED
} square_t;
typedef struct {
    int player2_pid;
    int player1_pid;
} signal_t;
typedef struct {
    int is_palyer1;
    int is_player2;
} player_t;
typedef struct {
    square_t **my_map;
    square_t **enemy_map;
    int try_letter;
    int try_number;
} game_t;
int error_handling_attaks(char *user_input);
void handle_signal_attaks(int signo, siginfo_t *info, void *context);
void send_signals_attacks_player2(char *userinput, int pid_player1);
void send_signals_attacks_player1(char *userinput, int pid_player2);
void extract_input_player1(int pid_player2);
void extract_input_player2(int pid_player1);
void attack_or_wait_player1(int pid_player2, game_t *game);
void attack_or_wait_player2(int pid_player1, game_t *game);
int find_player1_pid(signal_t *signal_info);
int waiting_signal_atttaks(void);
typedef struct loop_cond {
    int sig;
    int pid_player1;
    int pid_player2;
    int loop_cond_receive_attaks;
    game_t *game;
}loop_cond_t;
extern loop_cond_t loop_cond;
int init_sigaction_player2(void);
void player2_signals(int pid_player1, signal_t *signal_info);
void launch_fonction_connecting(int argc, char **argv, signal_t *signal_info,
    game_t *game);
void handle_sigusr1_player2(int signo, siginfo_t *info, void *context);
char **my_str_to_word_array_del(char *str, const char *delimiters);
int waiting_signal_connection_p2(signal_t *signal_info);
void handle_signal_connection(int signo, siginfo_t *info, void *context);
int waiting_signal_connection(signal_t *signal_info);
void interpret_attaks(int letter_count, int number_count, int pid);
void dump_game(square_t **my_map, square_t **enemy_map);
square_t **get_blank_map(void);
int check_hit(square_t **map, char const *hit);
int check_lose(square_t **map);
char **my_str_to_word_array_del(char *str, const char *delimiters);
int my_pow(int base, int power);
square_t **get_map(const char *filename);
void dump_map(square_t **map);
#endif
