/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls
*/

#ifndef MY_LS_H_
    #define MY_LS_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <time.h>

    typedef struct handler_s {
        char *str;
        void (*fn_ptr)();
    } handler_t;

    extern handler_t handlers[];

    typedef struct duck_s {
        sfSprite *sprite;
        sfVector2f vel;
        sfClock *clock;
    } duck_t;

    typedef struct pokeball_s {
        sfSprite *sprite;
        sfClock *clock;
        sfVector2f target;
        sfVector2f scale;
        int thrown;
    } pokeball_t;

    typedef struct button_s {
        sfRectangleShape *r_shape;
        sfText *text;
        void (*fn_ptr)();
    } button_t;

    typedef struct game_s {
        int scn;
        button_t **button;
        sfEvent event;
        duck_t **duck;
        pokeball_t **pokeball;
        int balls;
        int score;
        sfText *score_txt;
        sfSprite *bg;
        sfSprite *cursor;
        sfMusic *music;
    } game_t;

    sfRenderWindow *create_window(char *name);
    sfSprite *create_sprite(char *filepath, int x, int y);
    sfText *create_text(char *font_fp, char *str, sfVector2f pos, int size);
    sfSound *create_sound(char *filepath);
    sfRectangleShape *create_rectangle(char *fp, sfVector2f pos,
    sfVector2f size, sfIntRect rect);
    button_t **load_buttons(char *filepath);
    void change_to_game(sfRenderWindow *wd, game_t *game);
    void events(sfRenderWindow *wd, game_t *game);
    game_t *init_game(void);
    void display(sfRenderWindow *wd, game_t *game);
    void destroyer(sfRenderWindow *wd, game_t *game);
    void reset_duck(sfRenderWindow *wd, duck_t *duck);
    void move_duck(sfRenderWindow *wd, duck_t *duck);
    void change_rects(sfRenderWindow *wd, duck_t *duck);
    void check_hit(sfRenderWindow *wd, game_t *game, pokeball_t *ball);
    void handle_null(sfRenderWindow *wd, game_t *game);

#endif /* !MY_LS_H_ */
