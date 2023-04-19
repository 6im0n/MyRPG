/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** layers
*/

#include "types/type.h"
#include <stdio.h>

static void update_heart(app_t *app, node_layer_t *tmp, int max)
{
    int player_life = app->element->player->life;

    if (player_life >= max)
        tmp->irect.left = 581 - 1;
    else if (player_life == max - 1)
        tmp->irect.left = 581 - 1 + 16;
    else
        tmp->irect.left = 581 - 1 + 32;
    sfRectangleShape_setTextureRect(tmp->obj, tmp->irect);
}

void layer_update(app_t *app)
{
    node_layer_t *tmp = app->element->layers->first;
    int id = 0;

    while (tmp) {
        id = tmp->id - 19;
        if (id > 0 && id <= 5)
            update_heart(app, tmp, id * 2);
        tmp = tmp->next;
    }
}

void layer_render(app_t *app)
{
    node_layer_t *tmp = app->element->layers->first;

    layer_update(app);
    while (tmp) {
        sfRenderWindow_drawRectangleShape(app->window, tmp->obj, NULL);
        tmp = tmp->next;
    }
}
