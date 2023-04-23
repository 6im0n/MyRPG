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

    item = new_items(item, I_AXE_LEV1,
        (sfIntRect){.height = 73, .left = 332, .top = 512, .width = 60}, rect);
    item->name = "Axe 1";
    item->sharpness = "Sharpness: ";
    item->weight = "Weight: ";
    concat_item_skills(item, item->skill);
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

    item = new_items(item, I_AXE_LEV2,
        (sfIntRect){.height = 75, .left = 410, .top = 512, .width = 60}, rect);
    item->name = "Axe 2";
    item->sharpness = "Sharpness: ";
    item->weight = "Weight: ";
    concat_item_skills(item, item->skill);
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

    item = new_items(item, I_AXE_LEV3,
        (sfIntRect){.height = 78, .left = 486, .top = 508, .width = 60}, rect);
    item->name = "Axe 3";
    item->sharpness = "Sharpness: ";
    item->weight = "Weight: ";
    concat_item_skills(item, item->skill);
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

    item = new_items(item, I_AXE_LEV4,
        (sfIntRect){.height = 83, .left = 559, .top = 508, .width = 60}, rect);
    item->name = "Axe 4";
    item->weight = "Weight: ";
    item->sharpness = "Sharpness: ";
    concat_item_skills(item, item->skill);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

void append_axe(list_item_t *list, ressources_t *ressources)
{
    append_lv1(list, ressources);
    append_lv2(list, ressources);
    append_lv3(list, ressources);
    append_lv4(list, ressources);
}
