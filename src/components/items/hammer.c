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

    item = new_items(item, I_HAMMER_LEV1,
        (sfIntRect){.height = 60, .left = 332, .top = 162, .width = 60}, rect);
    item->name = "Hammer 1";
    item->sharpness = "Sharpness: 3/10";
    item->weight = "Weight: 3/10";
    item->skill.speed = 3;
    item->skill.strength = 3;
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

    item = new_items(item, I_HAMMER_LEV2,
        (sfIntRect){.height = 72, .left = 410, .top = 153, .width = 60}, rect);
    item->name = "Hammer 2";
    item->name = "Sword 3";
    item->sharpness = "Sharpness: 5/10";
    item->weight = "Weight: 5/10";
    item->skill.speed = 5;
    item->skill.strength = 5;
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

    item = new_items(item, I_HAMMER_LEV3,
        (sfIntRect){.height = 78, .left = 486, .top = 153, .width = 60}, rect);
    item->name = "Hammer 3";
    item->sharpness = "Sharpness: 7/10";
    item->weight = "Weight: 7/10";
    item->skill.speed = 7;
    item->skill.strength = 7;
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

    item = new_items(item, I_HAMMER_LEV4,
        (sfIntRect){.height = 83, .left = 559, .top = 150, .width = 60}, rect);
    item->name = "Hammer 4";
    item->sharpness = "Sharpness: 10/10";
    item->weight = "Weight: 10/10";
    item->skill.speed = 10;
    item->skill.strength = 10;
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

void append_hammer(list_item_t *list, ressources_t *ressources)
{
    append_lv1(list, ressources);
    append_lv2(list, ressources);
    append_lv3(list, ressources);
    append_lv4(list, ressources);
}
