/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sword
*/

#include "types/type.h"
#include "types/list.h"
#include "components/new.h"

static void append_lv1(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SPEAR_LEV1,
        (sfIntRect){.height = 68, .left = 330, .top = 273, .width = 68}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_lv2(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SPEAR_LEV2,
        (sfIntRect){.height = 72, .left = 408, .top = 273, .width = 72}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_lv3(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SPEAR_LEV3,
        (sfIntRect){.height = 72, .left = 483, .top = 273, .width = 72}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_lv4(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SPEAR_LEV4,
        (sfIntRect){.height = 72, .left = 553, .top = 273, .width = 72}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

void append_spear(list_item_t *list, ressources_t *ressources)
{
    append_lv1(list, ressources);
    append_lv2(list, ressources);
    append_lv3(list, ressources);
    append_lv4(list, ressources);
}
