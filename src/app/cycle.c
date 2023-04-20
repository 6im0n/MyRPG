/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** cycle
*/

#include "types/type.h"

void render_cycle_day_night(app_t *app)
{
    sfRectangleShape *shape = app->state->cycle->shape;
    sfTime t = sfClock_getElapsedTime(app->state->cycle->clock);
    sfColor c = sfRectangleShape_getFillColor(shape);
    int t_set = 60 * 6;
    int c_max = 220;

    if (sfTime_asSeconds(t) < t_set / 2)
        c.a = ((sfTime_asSeconds(t) / (t_set / 2)) * c_max) - 1;
    else
        c.a = (c_max - ((sfTime_asSeconds(t) - t_set / 2) /
        (t_set / 2)) * c_max) - 1;
    if (c.a > 150)
        app->state->cycle->cycle = NIGHT;
    else
        app->state->cycle->cycle = DAY;
    if (sfTime_asSeconds(t) >= t_set - 1)
        sfClock_restart(app->state->cycle->clock);
    sfRectangleShape_setFillColor(shape, c);
    sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
}
