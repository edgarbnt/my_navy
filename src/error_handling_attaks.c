/*
** EPITECH PROJECT, 2023
** navy
** File description:
** error handling user
*/

#include "../include/my.h"
#include <unistd.h>

int error_handling_attaks(char *user_input)
{
    if (my_strlen(user_input) != 3)
        return 1;
    if (user_input[0] < 'A' || user_input[0] > 'H')
        return 1;
    if ((user_input[1]) <= '0' || (user_input[1]) > '8') {
        return 1;
    }
    return 0;
}
