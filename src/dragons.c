/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** dragons
*/

#include "my.h"
#include "hunter.h"

void change_rects(sfRenderWindow *wd, duck_t *duck)
{
    sfIntRect rect;

    if (sfTime_asSeconds(sfClock_getElapsedTime(duck->clock)) > 0.3) {
        rect = sfSprite_getTextureRect(duck->sprite);
        rect.left += 157;
        if (rect.left >= 620)
            rect.left = 0;
        sfSprite_setTextureRect(duck->sprite, rect);
        sfClock_restart(duck->clock);
    }
}

void reset_duck(sfRenderWindow *wd, duck_t *duck)
{
    sfVector2f pos = {1800, rand() % 500};
    duck->vel.x = rand() % 8 * -1 - 2;

    sfSprite_setPosition(duck->sprite, pos);
}

void move_duck(sfRenderWindow *wd, duck_t *duck)
{
        sfSprite_move(duck->sprite, duck->vel);
        if (sfSprite_getPosition(duck->sprite).x < -200)
            reset_duck(wd, duck);
}
