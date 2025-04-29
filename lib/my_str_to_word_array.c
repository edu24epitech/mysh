/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** displays array of words
*/

#include "../include/my.h"

int is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '-') || (c == '/') || (c == '.') ||
        (c == '.'))
        return 1;
    return 0;
}

static int count_alphanum(int i, char *str)
{
    while (is_alphanum(str[i])) {
        i++;
    }
    return i;
}

int get_max_words(char *str)
{
    int i = 0;
    int max_words = 0;

    while (str[i]) {
        if (is_alphanum(str[i])) {
            max_words++;
            i = count_alphanum(i, str);
        } else {
            i++;
        }
    }
    return max_words;
}

int get_word_length(const char *start)
{
    int length = 0;

    while (is_alphanum(start[length])) {
        length++;
    }
    return length;
}

char *my_strdup_length(const char *start, int length)
{
    char *word = malloc((length + 1) * sizeof(char));

    if (!word) {
        my_putstr("Alloc error\n");
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        word[i] = start[i];
    }
    word[length] = '\0';
    return word;
}

char **my_str_to_word_array(char *str)
{
    int max_words = 0;
    int word_i = 0;
    char **word_array = NULL;
    char *start = NULL;
    int length = 0;

    max_words = get_max_words(str);
    word_array = malloc((max_words + 1) * sizeof(char *));
    while (*str) {
        if (is_alphanum(*str)) {
            start = str;
            length = get_word_length(start);
            word_array[word_i] = my_strdup_length(start, length);
            word_i++;
            str += length;
        } else
            str++;
    }
    word_array[word_i] = NULL;
    return word_array;
}
