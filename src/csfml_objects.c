/*
** EPITECH PROJECT, 2022
** CPool_13
** File description:
** csfml_objects
*/

#include "hunter.h"

sfRenderWindow *create_window(char *name)
{
    sfVideoMode video_mode = {1560, 975, 64};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

sfSprite *create_sprite(char *filepath, int x, int y)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {x, y};

    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

sfSound *create_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);

    sfSound_setBuffer(sound, buffer);
    return (sound);
}

sfText *create_text(char *font_fp, char *str, sfVector2f pos, int size)
{
    sfFont *font = sfFont_createFromFile(font_fp);
    sfText *text = sfText_create();

    pos.x += 10;
    pos.y -= 30;
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    return (text);
}

sfRectangleShape *create_rectangle(char *fp, sfVector2f pos, sfVector2f size,
sfIntRect rect)
{
    sfRectangleShape *r_shape = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(fp, NULL);

    sfRectangleShape_setTexture(r_shape, texture, sfTrue);
    sfRectangleShape_setTextureRect(r_shape, rect);
    sfRectangleShape_setSize(r_shape, size);
    sfRectangleShape_setPosition(r_shape, pos);
    return (r_shape);
}
