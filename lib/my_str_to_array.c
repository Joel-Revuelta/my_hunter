/*
** EPITECH PROJECT, 2022
** CPool_08
** File description:
** my_str_to_word_array
*/

#include "my.h"

int nb_cages (char *str, char sep)
{
    int num = 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == sep)
            num++;
    return (num);
}

char **my_str_to_array(char *str, char sep)
{
    int num = nb_cages (str, sep);
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
