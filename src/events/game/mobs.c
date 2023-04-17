/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/type.h"

static bool mob_intersect_player(app_t *app, node_mob_t *mob)
{
    sfFloatRect rect;
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;
    rect = sfRectangleShape_getGlobalBounds(mob->shape);
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

void mobs_attack(node_mob_t *mob,
app_t *app)
{
    if (mob_intersect_player(app, mob)) {
        sfRectangleShape_setOutlineColor(mob->shape, sfRed);
        sfRectangleShape_setOutlineThickness(mob->shape, 2);
    } else {
        sfRectangleShape_setOutlineColor(mob->shape, sfTransparent);
        sfRectangleShape_setOutlineThickness(mob->shape, 0);
    }
}