/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_arr_to_str
*/

#include "my.h"

char *my_resize_string(char *str)
{
    int size = my_strlen(str);
    char *copy_str = malloc(sizeof(char) * (size + 2));
    int i = 0;

    while (i < size) {
        copy_str[i] = str[i];
        i++;
    }
    copy_str[i] = '\0';
    copy_str[i + 1] = '\0';
    free(str);
    return (copy_str);
}

char *my_arr_to_str(char **arr_str, char del)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * 2);

    while (arr_str[i] != NULL) {
        while (arr_str[i][j]) {
            str[k] = arr_str[i][j];
            str = my_resize_string(str);
            k++;
            j++;
        }
        str[k] = del;
        str = my_resize_string(str);
        k++;
        j = 0;
        i++;
    }
    str[k] = '\0';
    return (str);
}
