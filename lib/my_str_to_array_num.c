/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_to_array_num
*/

#include "my.h"

char **my_str_to_array_num(char *str, char sep, int num)
{
    char **result = malloc((num + 1) * sizeof(char *));
    int j = 0, z = 0, x = 0, i = 0;

    while (j < num) {
        x = 0;
        while (str[x + z] != '\0' && str[x + z] != sep)
            x++;
        result[j] = my_strmalloc(x + 1);
        for (i = 0; i < x; i++) {
            result[j][i] = str[z];
            z++;
        }
        result[j][i] = '\0';
        z++;
        j++;
    }
    result[j] = NULL;
    return (result);
}
