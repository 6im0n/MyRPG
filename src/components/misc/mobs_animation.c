/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Annimation
*/

#include "components/components.h"
#include "components/mobs.h"
#include "types/type.h"

static void draw_mobs_annimation(app_t *app, node_mob_t *mob, sfIntRect rect)
{
    (void) app;
    sfRectangleShape_setTextureRect(mob->shape, rect);
}

static void mobs_annimation_edit(app_t *app, node_mob_t *mob)
{
    sfIntRect rect = mob->irect;
    sfIntRect rect_a = mob->annimation.rect;

    if (mob->annimation.index > mob->annimation.max) {
        mob->annimation.index = 0;
        mob->state.hit = false;
    }
    rect_a.height *= mob->annimation.index;
    rect_a.top *= mob->annimation.index;
    rect_a.left *= mob->annimation.index;
    rect_a.width *= mob->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_mobs_annimation(app, mob, rect);
    mob->annimation.index++;
}

static void render_mobs_annimation(app_t *app, node_mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > mob->annimation.speed) {
        mobs_annimation_edit(app, mob);
        sfClock_restart(mob->clock);
    }
}

void mobs_render_annimation(app_t *app)
{
    node_mob_t *tmp = app->element->mobs->first;

    while (tmp != NULL) {
        render_mobs_annimation(app, tmp);
        mobs_move_to_player(tmp, app);
        mobs_attack(tmp, app);
        sfRenderWindow_drawRectangleShape(app->window,
            tmp->shape, NULL);
        tmp = tmp->next;
    }
}
