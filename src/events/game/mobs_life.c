/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/type.h"

static void outline_bar(node_mob_t *mob, app_t *app)
{
    sfVector2f size_outline = {43, 5};
    sfVector2f pos = sfRectangleShape_getPosition(mob->shape);

    sfRectangleShape_setPosition(mob->healt.outline, (sfVector2f){pos.x + 3,
        pos.y - 10});
    sfRectangleShape_setSize(mob->healt.outline, size_outline);
    sfRectangleShape_setFillColor(mob->healt.outline, sfTransparent);
    sfRectangleShape_setOutlineColor(mob->healt.outline, sfBlack);
    sfRectangleShape_setOutlineThickness(mob->healt.outline, 1);
    sfRenderWindow_drawRectangleShape(app->window,
        mob->healt.outline, NULL);
}

static sfColor h_color(int healt)
{
    if (healt > 50)
        return (sfGreen);
    if (healt > 25)
        return (sfYellow);
    return (sfRed);
}
#include <stdio.h>
void mob_attacked(node_mob_t *mob, app_t *app)
{
    sfTime time = app->element->player->character->attack.time;
    float seconds = time.microseconds / 1000000.0;

    sfTime g_time = sfClock_getElapsedTime(app->state->clock);
    float g_seconds = g_time.microseconds / 1000000.0;
    printf("time : %f\n", g_seconds);
    float diff = g_seconds - seconds;
    printf("diff : %f\n", diff);

    if (app->element->player->character->state.attack && mob->healt.curent > 0 && mob_intersect_player(app, mob) && app->element->player->character->annimation.index == 3 && diff > 2) {
        mob->healt.curent -= 10;
        app->element->player->character->attack.time = g_time;
    }
}

void mob_health_bar(node_mob_t *mob, app_t *app)
{
    sfVector2f size_bar = {43, 5};
    float h_precent = (float)mob->healt.curent / (float)mob->healt.max;
    sfVector2f pos = sfRectangleShape_getPosition(mob->shape);
    sfVector2f pos_healt = {pos.x + 3 , pos.y - 10};
    sfRectangleShape_setSize(mob->healt.bar,
        (sfVector2f){size_bar.x *h_precent, size_bar.y});
    sfRectangleShape_setPosition(mob->healt.bar, pos_healt);
    sfRectangleShape_setFillColor(mob->healt.bar, h_color(mob->healt.curent));
    sfRenderWindow_drawRectangleShape(app->window,
       mob->healt.bar, NULL);
    outline_bar(mob, app);
    mob_attacked(mob, app);
}

