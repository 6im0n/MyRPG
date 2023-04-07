/*
** EPITECH PROJECT, 2023
** RPG [WSL : Ubuntu]
** File description:
** Annimation
*/


#include "components/components.h"
#include "types/type.h"

static void draw_player_annimation(app_t *app, sfIntRect rect)
{
    sfRectangleShape_setTextureRect(app->player->character->shape,
    rect);
}

static void player_annimation_edit(app_t *app)
{
    sfIntRect rect = app->player->character->irect;
    sfIntRect rect_a = app->player->character->annimation.rect;

    if (app->player->character->annimation.index > app->player->character->annimation.max)
        app->player->character->annimation.index = 0;
    rect_a.height *= app->player->character->annimation.index;
    rect_a.top *= app->player->character->annimation.index;
    rect_a.left *= app->player->character->annimation.index;
    rect_a.width *= app->player->character->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_render_annimation(app, rect);
    app->player->character->annimation.index++;
}

static void render_player_annimation(app_t *app)
{
    sfTime time = sfClock_getElapsedTime(app->player->character->clock);
    float seconds = time.microseconds / 1000000.0;

    (void) app;
    if (seconds > app->player->character->annimation.speed) {
        annimation_edit(app);
        sfClock_restart(app->player->character->object->clock);
    }
}

void player_render_annimation(app_t *app)
{
    if (!(app->player->character->annimation.speed > 0))
        return;
    render_player_annimation(app);
}
