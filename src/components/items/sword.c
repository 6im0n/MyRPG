/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sword
*/

#include "types/type.h"
#include "types/list.h"
#include "components/new.h"

static void append_sword_lv1(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {100, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SWORD_LEV1,
        (sfIntRect){.height = 60, .left = 35, .top = 40, .width = 60}, rect);
    item->name = "Sword 1";
    item->sharpness = "Sharpness: ";
    item->weight = "Weight: ";
    item->skill.speed = 1;
    item->skill.strength = 1;
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    sfRectangleShape_setRotation(item->shape, 35);
    list_item_append(list, item);
}

static void append_sword_lv2(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {88, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SWORD_LEV2,
        (sfIntRect){.height = 72, .left = 108, .top = 33, .width = 60}, rect);
    item->name = "Sword 2";
    item->sharpness = "Sharpness: 5/10";
    item->weight = "Weight: ";
    item->skill.speed = 3;
    item->skill.strength = 5;
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    sfRectangleShape_setRotation(item->shape, 35);
    list_item_append(list, item);
}

static void append_sword_lv3(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {88, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SWORD_LEV3,
        (sfIntRect){.height = 78, .left = 188, .top = 30, .width = 60}, rect);
    item->name = "Sword 3";
    item->sharpness = "Sharpness: ";
    item->weight = "Weight: ";
    concat_item_skills(item, item->skill);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_sword_lv4(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {300, 835};
    sfVector2f size = {85, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SWORD_LEV4,
        (sfIntRect){.height = 83, .left = 260, .top = 30, .width = 60}, rect);
    item->name = "Sword 4";
    item->sharpness = "Sharpness: ";
    item->weight = "Weight: ";
    concat_item_skills(item, item->skill);
    new_items_texture(item, ressources, TX_WEAPONS, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

void append_sword(list_item_t *list, ressources_t *ressources)
{
    append_sword_lv1(list, ressources);
    append_sword_lv2(list, ressources);
    append_sword_lv3(list, ressources);
    append_sword_lv4(list, ressources);
}
