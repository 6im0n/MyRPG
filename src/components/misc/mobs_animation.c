/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Annimation
*/

#include "components/components.h"
#include "components/mobs.h"
#include "types/type.h"

static void draw_mob_annimation(app_t *app, node_mob_t *mob, sfIntRect rect)
{
    (void) app;
    sfRectangleShape_setTextureRect(mob->obj_shape, rect);
}

static void mob_annimation_edit(app_t *app, node_mob_t *mob)
{
    sfIntRect rect = mob->irect;
    sfIntRect rect_a = mob->annimation.rect;

    if (mob->annimation.index > mob->annimation.max) {
        mob->annimation.index = 0;
    }
    rect_a.height *= mob->annimation.index;
    rect_a.top *= mob->annimation.index;
    rect_a.left *= mob->annimation.index;
    rect_a.width *= mob->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_mob_annimation(app, mob, rect);
    mob->annimation.index++;
}

static void render_mob_annimation(app_t *app, node_mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > mob->annimation.speed) {
        mob_annimation_edit(app, mob);
        sfClock_restart(mob->clock);
    }
    if (finish_animation(mob, app)) {
        mob->irect.top = 192;
        mob->annimation.max = 7;
    }
}

void flip_animation(node_mob_t *mob)
{
    if (mob->state.left){
        mob->irect.width = -224;
        mob->irect.left = 224;
        return;
    } else if (!mob->state.left) {
        mob->irect.width = 224;
        mob->irect.left = 0;
        return;
    }
}

void mob_render_annimation(app_t *app)
{
    node_mob_t *tmp = app->element->mobs->first;

    if (app->element->player->character->state.attack)
        mob_attacked(app->element->mobs, app);
    while (tmp != NULL) {
        render_mob_annimation(app, tmp);
        if (!tmp->state.intersect)
            flip_animation(tmp);
        mob_move_to_player(tmp, app);
        if (!tmp->state.die) {
            mob_health_bar(tmp, app);
            mob_attack(tmp, app);
        }
        sfRenderWindow_drawRectangleShape(app->window,
            tmp->obj_shape, NULL);
        dying_mob(tmp, app);
        if (tmp)
            tmp = tmp->next;
    }
}
