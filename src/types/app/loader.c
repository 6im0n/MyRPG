/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** loader
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/type.h"
#include "app/constants.h"
#include "components/player.h"
#include "components/mobs.h"
#include "types/list.h"

static sfRectangleShape *shape_init(sfTexture *texture,
sfVector2f size, sfVector2f position)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f origin = {size.x / 2, size.y / 2};

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setTexture(shape, texture, sfFalse);
    sfRectangleShape_setOrigin(shape, origin);
    sfRectangleShape_setPosition(shape, position);
    return shape;
}

static sfText *text_init(int size, sfVector2f position)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/droid.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    sfText_setString(text, "NULL");
    return text;
}

loader_t *loader_init(void)
{
    loader_t *loader = malloc(sizeof(loader_t));
    sfTexture *textureepitech =
        sfTexture_createFromFile("assets/assets_rpg/epitech.png", NULL);
    sfTexture *texturelogo =
        sfTexture_createFromFile("assets/assets_rpg/logo.png", NULL);
    sfTexture *texturerafa =
        sfTexture_createFromFile("assets/assets_rpg/rafapixel.jpg", NULL);

    if (!loader)
        return NULL;
    loader->shape = shape_init(textureepitech, (sfVector2f){ 600, 600},
        (sfVector2f){ W_VIDEO_MODE.width / 2, W_VIDEO_MODE.height / 2});
    loader->logo = shape_init(texturelogo, (sfVector2f){ 600, 600},
        (sfVector2f){ W_VIDEO_MODE.width / 2, W_VIDEO_MODE.height / 2});
    loader->cursor = shape_init(texturerafa, (sfVector2f){ 600, 600},
        (sfVector2f){ W_VIDEO_MODE.width / 2, W_VIDEO_MODE.height / 2});
    loader->text = text_init(30, (sfVector2f){ W_VIDEO_MODE.width / 2,
        W_VIDEO_MODE.height / 1.2});
    return loader;
}

void loader_display(app_t *app, sfRectangleShape *shape)
{
    sfVector2f scale = {0, 0};
    int second = 0;

    while (scale.x < 1) {
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            return;
        sfRectangleShape_setScale(shape, scale);
        sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
        sfRenderWindow_display(app->window);
        sfRenderWindow_clear(app->window, W_COLOR);
        second++;
        scale.x += 0.0025;
        scale.y += 0.0025;
    }
}

void loader_text_display(app_t *app, sfRectangleShape *shape, char *content)
{
    sfFloatRect bound = {0, 0, 0, 0};

    sfRenderWindow_clear(app->window, W_COLOR);
    sfText_setString(app->loader->text, content);
    bound = sfText_getLocalBounds(app->loader->text);
    sfText_setOrigin(app->loader->text, (sfVector2f){bound.width / 2,
        bound.height / 2});
    sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
    sfRenderWindow_drawText(app->window, app->loader->text, NULL);
    sfRenderWindow_display(app->window);
}
