/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** placeholder
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

int is_delimiter(char c, const char *delimiters)
{
    while (*delimiters) {
        if (c == *delimiters)
            return 1;
        delimiters++;
    }
    return 0;
}

static void resize_buff(
    const char *file_content, const char *delimiters, int *start, int *end)
{
    while (is_delimiter(file_content[(*end)], delimiters) &&
        file_content[(*end)])
        (*end)++;
    (*start) = (*end);
    while (!is_delimiter(file_content[(*end)], delimiters) &&
        file_content[(*end)]) {
        (*end)++;
    }
}

int count_words_del(const char *file_content, const char *delimiters)
{
    int word_count = 0;
    int i = 0;
    int start = 0;
    int end = 0;

    while (file_content[end]) {
        while (is_delimiter(file_content[end], delimiters) &&
            file_content[end])
            end++;
        start = end;
        while (!is_delimiter(file_content[end], delimiters) &&
            file_content[end])
            end++;
        if (end > start)
            word_count++;
    }
    return word_count;
}

char **allocate_memory(int word_count)
{
    return (char **) malloc((word_count + 1) * sizeof(char *));
}

char **fill_words(char **line_info, const char *file_content,
    const char *delimiters)
{
    int word_count = 0;
    int start = 0;
    int end = 0;
    int word_length;

    while (file_content[end]) {
        resize_buff(file_content, delimiters, &start, &end);
        word_length = end - start;
        line_info[word_count] = malloc((word_length + 1) * sizeof(char *));
        for (int i = 0; i < word_length; i++)
            line_info[word_count][i] = file_content[start + i];
        if (word_length > 0) {
            line_info[word_count][word_length] = '\0';
            word_count++;
        }
        if (word_length <= 0)
            free(line_info[word_count]);
    }
    line_info[word_count] = NULL;
    return line_info;
}

char **my_str_to_word_array_del(char *str, const char *delimiters)
{
    int word_count = count_words_del(str, delimiters);
    char **str_array = NULL;

    str_array = allocate_memory(word_count);
    if (!str_array)
        return NULL;
    str_array = fill_words(str_array, str, delimiters);
    return str_array;
}
