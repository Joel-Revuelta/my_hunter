/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_malloc
*/

#include "my.h"

char *my_strmalloc(int size)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return (NULL);
    while (i <= size) {
        str[i] = '\0';
        i++;
    }
    return (str);
}
