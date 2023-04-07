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
    sfRectangleShape_setTextureRect( app->element->player->character->shape,
    rect);
}

static void player_annimation_edit(app_t *app)
{
    sfIntRect rect = app->element->player->character->irect;
    sfIntRect rect_a = app->element->player->character->annimation.rect;

    if ( app->element->player->character->annimation.index >
    app->element->player->character->annimation.max)
        app->element->player->character->annimation.index = 0;
    rect_a.height *= app->element->player->character->annimation.index;
    rect_a.top *= app->element->player->character->annimation.index;
    rect_a.left *= app->element->player->character->annimation.index;
    rect_a.width *= app->element->player->character->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_player_annimation(app, rect);
    app->element->player->character->annimation.index++;
}

static void render_player_annimation(app_t *app)
{
    sfTime time = sfClock_getElapsedTime(
        app->element->player->character->clock);
    float seconds = time.microseconds / 1000000.0;

    (void) app;
    if (seconds > app->element->player->character->annimation.speed) {
        player_annimation_edit(app);
        sfClock_restart(app->element->player->character->clock);
    }
}

void player_render_annimation(app_t *app)
{
    if (!(app->element->player->character->annimation.speed > 0))
        return;
    render_player_annimation(app);
}
