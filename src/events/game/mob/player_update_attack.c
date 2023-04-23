/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/
#include <math.h>
#include "components/mobs.h"
#include "types/type.h"

void update_attack_player(app_t *app)
{
    player_t *player = app->element->player;

    player->inventory->first->skill.strength = player->skills.strength;
    player->skills.strength = player->skills.strength *5;
}

void player_mob_attach(app_t *app, node_mob_t *tmp)
{
    sfTime time = tmp->time_hited;
    sfTime g_time = sfClock_getElapsedTime(app->state->clock);
    float seconds = time.microseconds / 1000000.0;
    float g_seconds = g_time.microseconds / 1000000.0;
    float diff = g_seconds - seconds;
    node_item_t *data = app->element->player->inventory->first;

    if (tmp->healt.curent > 0.0 && mob_intersect_player(app, tmp) &&
    app->element->player->character->annimation.index == 2 && diff > 0.2) {
        if (app->element->player->inventory->first)
            tmp->healt.curent -= data->skill.strength * 3 +
            app->element->player->skills.strength;
        else
            tmp->healt.curent--;
        tmp->time_hited = g_time;
    }
    if (tmp->healt.curent < 0)
        tmp->healt.curent = 0;
}
