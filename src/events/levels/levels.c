/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** levels
*/

#include <stdio.h>
#include "components/components.h"
#include "lib/tools.h"
#include "lib/str.h"
#include "parsing/utils.h"

static void update_skills(player_t *player, node_component_t *node,
                        sfVector2f size)
{
    while (node && node->id != ID_XP)
        node = node->next;
    size.x = player->exprerience.xp * 400 / player->exprerience.max_xp;
    sfRectangleShape_setSize(node->object->rectangle, size);
    node = node->next;
    size.x = player->skills.resitance * 400 / 100;
    if (player->skills.resitance <= 100)
        sfRectangleShape_setSize(node->object->rectangle, size);
    sfRectangleShape_setFillColor(node->object->rectangle, sfGreen);
    node = node->next;
    size.x = player->skills.speed * 400 / 100;
    if (player->skills.speed <= 100)
        sfRectangleShape_setSize(node->object->rectangle, size);
    sfRectangleShape_setFillColor(node->object->rectangle, sfBlue);
    node = node->next;
    size.x = player->skills.strength * 400 / 100;
    if (player->skills.strength <= 100)
        sfRectangleShape_setSize(node->object->rectangle, size);
    sfRectangleShape_setFillColor(node->object->rectangle, sfRed);
}

static void manage_xp(player_t *player, int xp)
{
    player->exprerience.xp += xp;
    while (player->exprerience.xp >= player->exprerience.max_xp) {
        player->exprerience.xp -= player->exprerience.max_xp;
        player->exprerience.max_xp += 50;
        player->exprerience.level++;
    }
}

static void update_text(list_components_t *list, player_t *player)
{
    node_component_t *node = list->first;
    char *player_level = NULL;
    char *final = NULL;
    int size = 0;

    while (node && node->id != ID_LEVEL)
        node = node->next;
    player_level = my_char(player->exprerience.level);
    size = (my_strlen(player_level) + 7);
    final = malloc(sizeof(char) * (size + 1));
    if (!final)
        return;
    clean_char(final, size + 1);
    my_strcpy(final, "Level ");
    my_strcat(final, player_level);
    sfText_setString(node->object->text, final);
    free(final);
}

void levels_update(app_t *app, list_components_t *list, int xp)
{
    player_t *player = app->element->player;
    node_component_t *node = list->first;

    if (xp > 0)
        manage_xp(player, xp);
    update_skills(player, node, (sfVector2f){500, 12});
    update_text(list, player);
}
