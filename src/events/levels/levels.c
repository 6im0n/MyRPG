/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** levels
*/

#include <stdio.h>
#include "components/components.h"
#include "lib/tools.h"

static void manage_xp(player_t *player, int xp)
{
    player->exprerience.xp += xp;
    if (player->exprerience.xp >= player->exprerience.max_xp) {
        player->exprerience.xp -= player->exprerience.max_xp;
        player->exprerience.max_xp += 50;
        player->exprerience.level++;
    }
}

void levels_update(app_t *app, list_components_t *list, int xp)
{
    player_t *player = app->element->player;
    node_component_t *node = list->first;
    sfVector2f size = {500, 12};
    char *player_level = NULL;

    manage_xp(player, xp);
    while (node->id != ID_XP)
        node = node->next;
    size.x = player->exprerience.xp * 400 / player->exprerience.max_xp;
    sfRectangleShape_setSize(node->object->rectangle, size);
    node = list->first;
    while (node && node->id != ID_LEVEL)
        node = node->next;
    player_level = my_char(player->exprerience.level);
    sfText_setString(node->object->text, player_level);
}
