/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/type.h"
#include <math.h>

static bool mobs_next_to_player(app_t *app, node_mob_t *mob)
{
    sfFloatRect rect;
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;
    int radius = mob->radius;

    if (mob->radius == 0)
        return false;
    rect = sfRectangleShape_getGlobalBounds(mob->shape);
    rect.top -= radius;
    rect.left -= radius;
    rect.width += radius * 2;
    rect.height += radius * 2;
    mob->prox_shape = sfCircleShape_create();
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

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

static bool finish_animation(node_mob_t *mob)
{
    if (mob->annimation.index > mob->annimation.max){
        mob->annimation.index = 0;
        return true;
    }
    return false;
}

void mobs_attack(node_mob_t *mob,
app_t *app)
{
    if (mob_intersect_player(app, mob)) {
        if (mob->status != 1 && mob->annimation.index != 0){
            mob->status = 1;
        }
        mob->irect.top = 384 + 55;
        mob->annimation.max = 16;
        sfRectangleShape_setOutlineColor(mob->shape, sfRed);
        return;
    }
    if (mob->status != 0 && !finish_animation(mob)) {
        sfRectangleShape_setOutlineColor(mob->shape, sfYellow);
    } else {
        mob->status = 0;
        mob->irect.top = 55;
        mob->annimation.max = 7;
        sfRectangleShape_setOutlineColor(mob->shape, sfGreen);
        sfRectangleShape_setOutlineThickness(mob->shape, 2);
    }
}

void mobs_move_to_player(node_mob_t *mob,
app_t *app)
{
    if (mobs_next_to_player(app, mob)) {
        float speed = 1;

        sfVector2f pos = sfRectangleShape_getPosition(mob->shape);
        sfVector2f posp = sfRectangleShape_getPosition(
                app->element->player->character->shape);
        sfVector2f dir = {posp.x - pos.x, posp.y - pos.y};
        float length = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
        sfVector2f normalized_dir = {dir.x / length, dir.y / length};
        sfVector2f normalized_pos = {pos.x + normalized_dir.x * speed,
            pos.y + normalized_dir.y * speed };

        sfRectangleShape_setPosition(mob->shape, normalized_pos);
    }
}
