/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include <stdio.h>
#include <math.h>
#include "components/mobs.h"
#include "types/type.h"

static void outline_bar(node_mob_t *mob, app_t *app)
{
    sfVector2f size_outline = {30, 3};
    sfVector2f pos = sfRectangleShape_getPosition(mob->obj_shape);

    sfRectangleShape_setPosition(mob->healt.outline, (sfVector2f){pos.x + 95,
        pos.y + 50});
    sfRectangleShape_setSize(mob->healt.outline, size_outline);
    sfRectangleShape_setFillColor(mob->healt.outline, sfTransparent);
    sfRectangleShape_setOutlineColor(mob->healt.outline, sfBlack);
    sfRectangleShape_setOutlineThickness(mob->healt.outline, 0.65);
    sfRenderWindow_drawRectangleShape(app->window,
        mob->healt.outline, NULL);
}

sfColor h_color(int healt)
{
    int r, g, b;
    float ratio = (float)healt / 100.0;
    int alpha = 170;

    if (ratio < 0.5) {
        r = 255;
        g = (int)(ratio * 2 * 255);
        b = 0;
    } else {
        r = (int)((1.0 - ratio) * 2 * 255);
        g = 255;
        b = 0;
    }
    return sfColor_fromRGBA(r, g, b, alpha);
}

void dying_mob(node_mob_t *mob, app_t *app)
{
    if (mob->state.die == true) {
        if (mob->annimation.index == 14) {
            app->element->player->exprerience.update += 15;
            sfRectangleShape_destroy(mob->obj_shape);
            sfClock_destroy(mob->clock);
            list_mob_remove(app->element->mobs, mob);
            free(mob);
            return;
        }
    }
    if (mob->healt.curent <= 0 && mob->state.die == false){
        mob->irect.top = 192 * 4;
        sfRectangleShape_setTextureRect(mob->obj_shape, mob->irect);
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
        player_mob_attach(app, tmp);
        tmp = tmp->next;
    }
}

void mob_health_bar(node_mob_t *mob, app_t *app)
{
    sfVector2f size_bar = {30, 3};
    float h_precent = (float)mob->healt.curent / (float)mob->healt.max;
    sfVector2f pos = sfRectangleShape_getPosition(mob->obj_shape);
    sfVector2f pos_healt = {pos.x + 95 , pos.y + 50};

    sfRectangleShape_setSize(mob->healt.bar,
        (sfVector2f){size_bar.x *h_precent, size_bar.y});
    sfRectangleShape_setPosition(mob->healt.bar, pos_healt);
    sfRectangleShape_setFillColor(mob->healt.bar, h_color(mob->healt.curent));
    sfRenderWindow_drawRectangleShape(app->window,
        mob->healt.bar, NULL);
    outline_bar(mob, app);
}
