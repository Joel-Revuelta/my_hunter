/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** pokeballs
*/

#include "my.h"
#include "hunter.h"

void rect_pokeballs(pokeball_t *pokeball)
{
    sfIntRect rect;

    if (sfTime_asSeconds(sfClock_getElapsedTime(pokeball->clock)) > 0.2) {
        rect = sfSprite_getTextureRect(pokeball->sprite);
        rect.top += 95;
        if (rect.top > 290)
            rect.top = 5;
        sfSprite_setTextureRect(pokeball->sprite, rect);
        sfClock_restart(pokeball->clock);
    }
}

void rect_catch(pokeball_t *pokeball)
{
    sfIntRect rect = sfSprite_getTextureRect(pokeball->sprite);

    if (rect.left == 100) {
        rect = (sfIntRect){195, 5, 89, 144};
        sfSprite_setTextureRect(pokeball->sprite, rect);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(pokeball->clock)) > 0.3) {
        if (rect.top == 280) {
            rect = (sfIntRect){5, 5, 90, 90};
            pokeball->thrown = 0;
        }
        if (rect.top == 155)
            rect = (sfIntRect){195, 280, 89, 99};
        if (rect.top == 5 && rect.height == 144)
            rect = (sfIntRect){195, 155, 89, 119};
        sfSprite_setTextureRect(pokeball->sprite, rect);
        sfClock_restart(pokeball->clock);
    }
}

void move_pokeballs(game_t *game, pokeball_t *ball, int i)
{
    if (ball->thrown == 2)
        rect_catch(ball);
    if (ball->thrown == 0) {
        sfSprite_setTextureRect(ball->sprite, (sfIntRect){100, 5, 90, 90});
        sfSprite_setPosition(ball->sprite, (sfVector2f){1200 + (100 * i), 850});
        sfSprite_setScale(ball->sprite, (sfVector2f){1, 1});
    }
    if (ball->thrown == 1) {
        sfSprite_move(ball->sprite, (sfVector2f){0.4, -10});
        rect_pokeballs(ball);
        sfSprite_scale(ball->sprite, (sfVector2f){0.99, 0.99});
        if (sfSprite_getPosition(ball->sprite).y <= ball->target.y - 46)
            check_hit(game, ball);
    }
}
