/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** death
*/

#include "types/type.h"

void death_render(app_t *app)
{
    sfRectangleShape *shape = app->state->cycle->shape;
    sfTime t = sfClock_getElapsedTime(app->state->cycle->clock);
    sfColor c = sfRectangleShape_getFillColor(shape);
    int t_set = 10 * 1;
    int c_max = 205;

    if (sfTime_asSeconds(t) > 4.5) {
        sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
        return;
    }
    c.a = ((sfTime_asSeconds(t) / (t_set / 2)) * c_max) - 1;
    sfRectangleShape_setFillColor(shape, c);
    sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
}
