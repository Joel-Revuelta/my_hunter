/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init_game
*/

#include "my.h"
#include "hunter.h"

pokeball_t **init_pokeballs(void)
{
    pokeball_t **pokeball = malloc(sizeof(pokeball_t *) * 3);
    sfIntRect rect = {100, 5, 90, 90};

    for (int i = 0; i < 3; i++) {
        pokeball[i] = malloc(sizeof(pokeball_t));
        pokeball[i]->sprite = create_sprite("assets/pokeball.png", -100, -100);
        pokeball[i]->thrown = 0;
        sfSprite_setTextureRect(pokeball[i]->sprite, rect);
    }
    return (pokeball);
}

duck_t **init_ducks(void)
{
    duck_t **duck = malloc(sizeof(duck_t *) * 5);
    sfIntRect rect = {0, 0, 155, 120};
    int y = 0;
    int x = 0;

    for (int i = 0; i < 5; i++) {
        y = rand() % 750;
        x = rand() % 1000 + 1700;
        duck[i] = malloc(sizeof(duck_t));
        duck[i]->sprite = create_sprite("assets/charizard.png", x, y);
        duck[i]->vel = (sfVector2f){-3, 0};
        duck[i]->clock = sfClock_create();
        sfSprite_setTextureRect(duck[i]->sprite, rect);
    }
    return (duck);
}

void get_fn_ptr(button_t *button, char *str)
{
    for (int i = 0; i < 2; i++) {
        if (my_strcmp(str, handlers[i].str) == 0)
            button->fn_ptr = handlers[i].fn_ptr;
    }
}

button_t **load_buttons(char *filepath)
{
    char **file = my_str_to_array(open_file(filepath), '\n'), **info = NULL;
    button_t **button = malloc(sizeof(button_t *) * (my_arr_len(file) + 1));
    sfVector2f p, s, pt;
    sfIntRect r = {0, 0, 88, 56};
    int i = 0;

    for (; file[i]; i++) {
        button[i] = malloc(sizeof(button_t));
        info = my_str_to_array(file[i], ':');
        p = (sfVector2f){my_getnbr(info[2]), my_getnbr(info[3])};
        s = (sfVector2f){my_getnbr(info[4]), my_getnbr(info[5])};
        button[i]->r_shape = create_rectangle("assets/butt_02.png", p, s, r);
        pt = (sfVector2f){my_getnbr(info[7]), my_getnbr(info[8])};
        button[i]->text = create_text("assets/font.ttf", info[6], pt,
        my_getnbr(info[9]));
        get_fn_ptr(button[i], info[10]);
    }
    button[i] = NULL;
    return (button);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->duck = init_ducks();
    game->pokeball = init_pokeballs();
    game->bg = create_sprite("assets/background.png", 0, 0);
    game->cursor = create_sprite("assets/cursor.png", 0, 0);
    game->music = sfMusic_createFromFile("assets/keyboard_cat.ogg");
    game->balls = 3;
    game->scn = 0;
    game->button = load_buttons("assets/main_menu.config");
    game->score = 0;
    game->score_txt = create_text("assets/font.ttf", "0", (sfVector2f){25, 775},
    200);

    sfSprite_scale(game->cursor, (sfVector2f){0.5, 0.5});
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    return (game);
}
