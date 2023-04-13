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
    sfVector2f size = {100, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_KNIFE_LEV1,
        (sfIntRect){.height = 60, .left = 337, .top = 37, .width = 60}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_lv2(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {88, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_KNIFE_LEV2,
        (sfIntRect){.height = 72, .left = 410, .top = 33, .width = 60}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_lv3(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {88, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_KNIFE_LEV3,
        (sfIntRect){.height = 78, .left = 486, .top = 32, .width = 60}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_lv4(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {85, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_KNIFE_LEV4,
        (sfIntRect){.height = 83, .left = 559, .top = 28, .width = 60}, rect);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

void append_knif(list_item_t *list, ressources_t *ressources)
{
    append_lv1(list, ressources);
    append_lv2(list, ressources);
    append_lv3(list, ressources);
    append_lv4(list, ressources);
}
