/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** display
*/

#include "my.h"
#include "hunter.h"

void display(sfRenderWindow *wd, game_t *game)
{
    sfRenderWindow_clear(wd, sfBlack);
    sfRenderWindow_drawSprite(wd, game->bg, NULL);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(wd, game->duck[i]->sprite, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(wd, game->pokeball[i]->sprite, NULL);
    for (int i = 0; game->button[i]; i++) {
        sfRenderWindow_drawRectangleShape(wd, game->button[i]->r_shape, NULL);
        sfRenderWindow_drawText(wd, game->button[i]->text, NULL);
    }
    sfRenderWindow_drawText(wd, game->score_txt, NULL);
    sfRenderWindow_drawSprite(wd, game->cursor, NULL);
    sfRenderWindow_display(wd);
}
