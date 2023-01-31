/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** destroyer
*/

#include "my.h"
#include "hunter.h"

void destroyer(sfRenderWindow *wd, game_t *game)
{
    sfMusic_destroy(game->music);
    sfSprite_destroy(game->bg);
    for (int i = 0; i < 5; i++)
        sfSprite_destroy(game->duck[i]->sprite);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(game->pokeball[i]->sprite);
    sfSprite_destroy(game->cursor);
    sfRenderWindow_destroy(wd);
}
