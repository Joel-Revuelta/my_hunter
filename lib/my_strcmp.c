/*
** EPITECH PROJECT, 2022
** CPool_06
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int i2 = 0;
    int x1 = 0;
    int x2 = 0;

    while (s1[i] || s2[i2]) {
        if (s1[i]) {
            x1 += s1[i];
            i++;
        }
        if (s2[i2]) {
            x2 += s2[i2];
            i2++;
        }
    }
    return (x1 - x2);
}
