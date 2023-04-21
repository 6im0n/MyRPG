/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/
#include <math.h>
#include "components/mobs.h"
#include "types/type.h"

static void outline_bar(node_mob_t *mob, app_t *app)
{
    sfVector2f size_outline = {43, 5};
    sfVector2f pos = sfRectangleShape_getPosition(mob->obj_shape);

    sfRectangleShape_setPosition(mob->healt.outline, (sfVector2f){pos.x + 3,
        pos.y - 10});
    sfRectangleShape_setSize(mob->healt.outline, size_outline);
    sfRectangleShape_setFillColor(mob->healt.outline, sfTransparent);
    sfRectangleShape_setOutlineColor(mob->healt.outline, sfBlack);
    sfRectangleShape_setOutlineThickness(mob->healt.outline, 1);
    sfRenderWindow_drawRectangleShape(app->window,
        mob->healt.outline, NULL);
}

sfColor h_color(int healt)
{
    int r, g, b;
    float ratio = (float)healt / 100.0;

    if (ratio < 0.5) {
        r = 255;
        g = (int)(ratio * 2 * 255);
        b = 0;
    } else {
        r = (int)((1.0 - ratio) * 2 * 255);
        g = 255;
        b = 0;
    }
    return sfColor_fromRGB(r, g, b);
}

void dying_mob(node_mob_t *mob, app_t *app)
{
    if (mob->state.die == true) {
        if (mob->annimation.index == 14) {
            sfRectangleShape_destroy(mob->obj_shape);
            sfClock_destroy(mob->clock);
            list_mob_remove(app->element->mobs, mob);
            free(mob);
        }
    }
    if (mob->healt.curent == 0 && mob->state.die == false){
        mob->irect.top = 768 + 55;
        mob->annimation.index = 0;
        mob->annimation.max = 14;
        sfRectangleShape_destroy(mob->healt.bar);
        sfRectangleShape_destroy(mob->healt.outline);
        mob->state.die = true;
    }
}

void mob_attacked(list_mobs_t *list, app_t *app)
{
    node_mob_t *tmp = list->first;

    while (tmp != NULL) {
        sfTime time = tmp->time_hit;
        sfTime g_time = sfClock_getElapsedTime(app->state->clock);
        float seconds = time.microseconds / 1000000.0;
        float g_seconds = g_time.microseconds / 1000000.0;
        float diff = g_seconds - seconds;

        if (tmp->healt.curent > 0.0 && mob_intersect_player(app, tmp) &&
        app->element->player->character->annimation.index == 2 && diff > 0.2) {
            tmp->healt.curent -= 10;
            tmp->time_hit = g_time;
        }
        tmp = tmp->next;
    }
}

void mob_health_bar(node_mob_t *mob, app_t *app)
{
    sfVector2f size_bar = {43, 5};
    float h_precent = (float)mob->healt.curent / (float)mob->healt.max;
    sfVector2f pos = sfRectangleShape_getPosition(mob->obj_shape);
    sfVector2f pos_healt = {pos.x + 3 , pos.y - 10};

    sfRectangleShape_setSize(mob->healt.bar,
        (sfVector2f){size_bar.x *h_precent, size_bar.y});
    sfRectangleShape_setPosition(mob->healt.bar, pos_healt);
    sfRectangleShape_setFillColor(mob->healt.bar, h_color(mob->healt.curent));
    sfRenderWindow_drawRectangleShape(app->window,
        mob->healt.bar, NULL);
    outline_bar(mob, app);
}
