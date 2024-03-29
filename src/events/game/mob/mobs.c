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

bool finish_animation(node_mob_t *mob, app_t *app)
{
    (void) app;
    if (mob->annimation.index > mob->annimation.max){
        mob->annimation.index = 0;
        mob->state.attack = 0;
        return true;
    }
    return false;
}

bool mob_intersect_player(app_t *app, node_mob_t *mob)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;

    rect = sfRectangleShape_getGlobalBounds(mob->obj_shape);
    rectp.height -= 25;
    rectp.width -= 25;
    rectp.left += 13;
    rectp.top += 13;
    rect.height -= 110;
    rect.width -= 150;
    rect.left += 75;
    rect.top += 55;
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

static void remove_player_life(app_t *app, node_mob_t *mob)
{
    (void) app;
    if (mob->annimation.index == 8) {
        app->element->player->life--;
        mob->state.hit = true;
    }
}

void update_hit(node_mob_t *mob, app_t *app)
{
    sfTime g_time = sfTime_Zero;
    float seconds = 0.0;
    float g_seconds = 0.0;
    float diff = 0.0;

    g_time = sfClock_getElapsedTime(app->state->clock);
    g_seconds = g_time.microseconds / 1000000.0;
    seconds = mob->cooldown.microseconds / 1000000.0;
    diff = g_seconds - seconds;
    if (diff > 3) {
        mob->state.hit = false;
        mob->cooldown = g_time;
    }
}

void mob_attack(node_mob_t *mob,
app_t *app)
{
    update_hit(mob, app);
    mob->state.intersect = mob_intersect_player(app, mob);;
    if (mob->annimation.index == 8 && !mob->state.intersect)
        mob->state.hit = true;
    if (mob->state.intersect && !mob->state.hit) {
        if (mob->state.attack != 1 && mob->annimation.index != 0)
            mob->state.attack = 1;
        mob->irect.top = 192 * 2;
        mob->annimation.max = 16;
        remove_player_life(app, mob);
        return;
    }
    if (mob->state.walk == 1)
        return;
    mob_anim(mob, app);
}
