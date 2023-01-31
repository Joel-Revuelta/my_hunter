/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** hunter
*/

#include "my.h"
#include "hunter.h"

void handle_null(sfRenderWindow *wd, game_t *game)
{
}

void cursor(sfRenderWindow *wd, game_t *game)
{
    sfVector2i mouse_int = sfMouse_getPositionRenderWindow(wd);
    sfVector2f mouse = {mouse_int.x - 20, mouse_int.y - 20};

    sfSprite_setPosition(game->cursor, mouse);
}

void change_to_game(sfRenderWindow *wd, game_t *game)
{
    game->scn = 1;
    game->button = load_buttons("assets/game_menu.config");
    sfMusic_destroy(game->music);
    game->music = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
}

void game_actions(sfRenderWindow *wd, game_t *game)
{

    for (int i = 0; i < 5; i++) {
        change_rects(wd, game->duck[i]);
        move_duck(wd, game->duck[i]);
    }
    for (int i = 0; i < 3; i++)
        move_pokeballs(wd, game, game->pokeball[i], i);
}

void hunter(void)
{
    sfRenderWindow *wd = create_window("PokeHunter");
    game_t *game = init_game();

    srand(time(NULL));
    while (sfRenderWindow_isOpen(wd)) {
        cursor(wd, game);
        if (game->scn)
            game_actions(wd, game);
        while (sfRenderWindow_pollEvent(wd, &game->event))
            events(wd, game);
        display(wd, game);
    }
    destroyer(wd, game);
}
