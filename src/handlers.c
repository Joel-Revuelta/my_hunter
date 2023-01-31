/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** handlers
*/

#include "my.h"
#include "hunter.h"

handler_t handlers[2] = {
    {"handle_null", &handle_null},
    {"change_to_game", &change_to_game}
};
