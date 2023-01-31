/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main
*/

#include "my.h"
#include "hunter.h"

void print_help(void)
{
    my_putstr("THIS MY GAME :)\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        print_help();
    else if (ac == 1) {
        hunter();
        return (0);
    }
    return (84);
}
