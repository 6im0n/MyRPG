/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** levels
*/

#include "components/components.h"

void levels_update(app_t *app, list_components_t *list)
{
    player_t *player = app->element->player;
    node_component_t *node = list->first;
    sfVector2f size = {400, 12};

    while (node->id != ID_XP)
        node = node->next;
    size.x = player->exprerience.xp * 400 / 100.0;
    sfRectangleShape_setSize(node->object->rectangle, size);
}
