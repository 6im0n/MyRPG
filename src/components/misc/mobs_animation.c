/*
** EPITECH PROJECT, 2023
** RPG [WSL : Ubuntu]
** File description:
** Annimation
*/

#include "components/components.h"
#include "types/type.h"

static void draw_mobs_annimation(app_t *app, sfIntRect rect)
{
    sfRectangleShape_setTextureRect( app->element->mobs->character->shape,
    rect);
}

static void mobs_annimation_edit(app_t *app)
{
    sfIntRect rect = app->element->mobs->character->irect;
    sfIntRect rect_a = app->element->mobs->character->annimation.rect;

    if ( app->element->mobs->character->annimation.index >
    app->element->mobs->character->annimation.max)
        app->element->mobs->character->annimation.index = 0;
    rect_a.height *= app->element->mobs->character->annimation.index;
    rect_a.top *= app->element->mobs->character->annimation.index;
    rect_a.left *= app->element->mobs->character->annimation.index;
    rect_a.width *= app->element->mobs->character->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_mobs_annimation(app, rect);
    app->element->mobs->character->annimation.index++;
}

static void render_mobs_annimation(app_t *app)
{
    sfTime time = sfClock_getElapsedTime(
        app->element->mobs->character->clock);
    float seconds = time.microseconds / 1000000.0;

    (void) app;
    if (seconds > app->element->mobs->character->annimation.speed) {
        mobs_annimation_edit(app);
        sfClock_restart(app->element->mobs->character->clock);
    }
}

void mobs_render_annimation(app_t *app)
{
    if (!(app->element->mobs->character->annimation.speed > 0))
        return;
    render_mobs_annimation(app);
}
