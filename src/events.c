/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** events
*/

#include "my.h"
#include "hunter.h"

void check_hit(game_t *game, pokeball_t *ball)
{
    sfFloatRect duck_rect;
    sfFloatRect ball_rect;

    for (int i = 0; i < 5; i++) {
        duck_rect = sfSprite_getGlobalBounds(game->duck[i]->sprite);
        ball_rect = sfSprite_getGlobalBounds(ball->sprite);
        if (sfFloatRect_intersects(&duck_rect, &ball_rect, NULL)) {
            reset_duck(game->duck[i]);
            ball->thrown = 2;
            game->score += 1;
            sfText_setString(game->score_txt, my_int_to_str(game->score));
            return;
        } else
            ball->thrown = 0;
    }
}

void throw_pokeball(game_t *game)
{
    int x = -1;
    sfVector2f pos = {game->event.mouseButton.x, game->event.mouseButton.y};

    for (int i = 0; i < 3 && x < 0; i++)
        if (!game->pokeball[i]->thrown)
            x = i;
    if (x < 0)
        return;
    game->pokeball[x]->target = pos;
    game->pokeball[x]->clock = sfClock_create();
    game->pokeball[x]->thrown = 1;
    sfSprite_setPosition(game->pokeball[x]->sprite,
    (sfVector2f){pos.x - 46, 950});
}

void check_button(sfRenderWindow *wd, game_t *game, button_t *button)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->r_shape);
    sfVector2f pos = {game->event.mouseButton.x, game->event.mouseButton.y};

    if (sfFloatRect_contains(&rect, pos.x, pos.y))
        button->fn_ptr(wd, game);
}

void events(sfRenderWindow *wd, game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        if (game->scn && game->balls > 0)
            throw_pokeball(game);
        for (int i = 0; game->button[i]; i++)
            check_button(wd, game, game->button[i]);
    }
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(wd);
}
