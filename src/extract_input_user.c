/*
** EPITECH PROJECT, 2023
** input utilisateur
** File description:
** placeholder
*/

#include "../include/my.h"
#include <unistd.h>

void extract_input_player1(int pid_player2)
{
    char *userInput = NULL;
    size_t bufferSize = 0;
    ssize_t bytesRead;

    while (1) {
        userInput = NULL;
        bytesRead = getline(&userInput, &bufferSize, stdin);
        if (userInput != NULL && error_handling_attaks(userInput) == 0) {
            loop_cond.game->try_letter = userInput[0] - 65;
            loop_cond.game->try_number = userInput[1] - 49;
            send_signals_attacks_player1(userInput, pid_player2);
            break;
        } else
            write(1, "\nwrong position\n\nattack: ", 26);
    }
}

void extract_input_player2(int pid_player1)
{
    char *userInput = "O";
    size_t bufferSize = 0;
    ssize_t bytesRead;

    while (1) {
        bytesRead = getline(&userInput, &bufferSize, stdin);
        if (userInput != NULL && error_handling_attaks(userInput) == 0) {
            loop_cond.game->try_letter = userInput[0] - 65;
            loop_cond.game->try_number = userInput[1] - 49;
            send_signals_attacks_player2(userInput, pid_player1);
            break;
        } else {
            write(1, "\nwrong position\n\nattack: ", 26);
        }
    }
}
