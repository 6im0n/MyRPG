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