/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include <stdio.h>
#include "components/mobs.h"
#include "types/type.h"
#include <math.h>

bool finish_animation(node_mob_t *mob)
{
    if (mob->annimation.index > mob->annimation.max){
        mob->annimation.index = 0;
        mob->state.attack = 0;
        mob->state.hit = false;
        return true;
    }
    return false;
}

static bool mob_intersect_player(app_t *app, node_mob_t *mob)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;

    rect = sfRectangleShape_getGlobalBounds(mob->obj_shape);
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

static void remove_player_life(app_t *app, node_mob_t *mob)
{
    if (mob->annimation.index == 8 && !mob->state.hit) {
        mob->state.hit = true;
        app->element->player->life--;
    }
}

void mobs_attack(node_mob_t *mob,
app_t *app)
{
    if (mob_intersect_player(app, mob)) {
        if (mob->state.attack != 1 && mob->annimation.index != 0){
            mob->state.attack = 1;
        }
        mob->irect.top = 384 + 55;
        mob->annimation.max = 16;
        remove_player_life(app, mob);
        return;
    }
    if (mob->state.walk == 1)
        return;
    if (mob->state.attack != 0 && !finish_animation(mob)) {
        return;
    } else {
        mob->state.attack = 0;
        mob->irect.top = 55;
        mob->annimation.max = 7;
    }
}
