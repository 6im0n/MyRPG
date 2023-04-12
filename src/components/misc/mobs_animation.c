/*
** EPITECH PROJECT, 2023
** RPG [WSL : Ubuntu]
** File description:
** Annimation
*/

#include "components/components.h"
#include "types/type.h"

static void draw_mobs_annimation(app_t *app, node_mobs_t *mobs, sfIntRect rect)
{
    (void) app;
    sfRectangleShape_setTextureRect(mobs->shape, rect);
}

static void mobs_annimation_edit(app_t *app, node_mobs_t *mobs)
{
    sfIntRect rect = mobs->irect;
    sfIntRect rect_a = mobs->annimation.rect;

    if ( mobs->annimation.index >
    mobs->annimation.max)
        mobs->annimation.index = 0;
    rect_a.height *= mobs->annimation.index;
    rect_a.top *= mobs->annimation.index;
    rect_a.left *= mobs->annimation.index;
    rect_a.width *= mobs->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_mobs_annimation(app, mobs, rect);
    mobs->annimation.index++;
}

static void render_mobs_annimation(app_t *app, node_mobs_t *mobs)
{
    sfTime time = sfClock_getElapsedTime(mobs->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > mobs->annimation.speed) {
        mobs_annimation_edit(app, mobs);
        sfClock_restart(mobs->clock);
    }
}


void mobs_render_annimation(app_t *app)
{
    node_mobs_t *tmp = app->element->mobs->first;
    while (tmp) {
        render_mobs_annimation(app, tmp);
        sfRenderWindow_drawRectangleShape(app->window,
            tmp->shape, NULL);
        tmp = tmp->next;
    }
}
