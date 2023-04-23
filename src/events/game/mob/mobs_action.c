/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include <math.h>
#include "components/mobs.h"
#include "types/type.h"

void mob_anim(node_mob_t *mob, app_t *app)
{
    if (mob->state.attack != 0 && !finish_animation(mob, app)) {
        return;
    } else {
        mob->state.attack = 0;
        mob->irect.top = 0;
        mob->annimation.max = 7;
    }
}

bool mob_next_to_player(app_t *app, node_mob_t *mob, int radius)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;

    if (radius == 0)
        return false;
    rect = sfRectangleShape_getGlobalBounds(mob->obj_shape);
    rect.top -= radius;
    rect.left -= radius;
    rect.width += radius * 2;
    rect.height += radius * 2;
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

static float update_speed_mob(app_t *app, node_mob_t *mob)
{
    float speed = (float)mob->skills.speed * 13.F;
    sfTime time = sfClock_getElapsedTime(app->state->clock);
    float seconds = time.microseconds / 1000000.0;
    sfTime old_time = mob->time;
    float seconds_old = old_time.microseconds / 1000000.0;
    float spend = seconds - seconds_old;

    mob->time = time;
    speed *= spend;
    return speed;
}

static sfVector2f normal_pos(node_mob_t *mob,
    sfVector2f posm, sfVector2f posp, float speed)
{
    sfVector2f dir = {posp.x - posm.x, posp.y - posm.y};
    float length = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
    sfVector2f normalized_dir = {dir.x / length, dir.y / length};
    sfVector2f normalized_pos = {posm.x + normalized_dir.x * speed,
        posm.y + normalized_dir.y * speed};
    if (dir.x > 0)
        mob->state.left = 0;
    else
        mob->state.left = 1;
    return normalized_pos;
}

void mob_move_to_player(node_mob_t *mob,
app_t *app)
{
    sfVector2f posm = sfRectangleShape_getPosition(mob->obj_shape);
    sfVector2f posp = sfRectangleShape_getPosition(
            app->element->player->character->shape);
    sfVector2f normalized_pos = {0, 0};
    float speed = update_speed_mob(app, mob);

    posp.x -= ((MOB_SIZE * (224.0 / 192.0)) / 2) - 50 / 2;
    posp.y -= MOB_SIZE / 2 - 40 / 2;
    if (mob_next_to_player(app, mob, mob->radius)) {
        normalized_pos = normal_pos(mob, posm, posp, speed);
        mob->state.walk = 1;
        if (normalized_pos.x < posp.x + 10 && normalized_pos.x > posp.x - 10 &&
            normalized_pos.y < posp.y + 12 && normalized_pos.y > posp.y - 12)
            return;
        if (!mob->state.attack == 1 && !finish_animation(mob, app) &&
            mob->healt.curent > 0)
            sfRectangleShape_setPosition(mob->obj_shape, normalized_pos);
        return;
    }
    mob->state.walk = 0;
}
