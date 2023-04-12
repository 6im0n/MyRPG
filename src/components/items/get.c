/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get
*/

#include "types/type.h"
#include "types/list.h"
#include "components/new.h"
#include "components/misc/item.h"

static void append_peppa_pig(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {200, 835};
    sfVector2f size = {80, 80};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_SWORD_PIG,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0}, rect);
    new_items_texture(item, ressources, TX_PEPPA_PIG, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

static void append_chalic(list_item_t *list, ressources_t *ressources)
{
    node_item_t *item = malloc(sizeof(node_item_t));
    sfVector2f position = {100, 835};
    sfVector2f size = {100, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    item = new_items(item, I_CHALICE,
        (sfIntRect){.height = 65, .left = 0, .top = 0, .width = 63}, rect);
    new_items_texture(item, ressources, TX_CHALICE, position);
    new_items_size(item, size);
    list_item_append(list, item);
}

void app_create_all_item(elements_t *element,
ressources_t *ressources)
{
    append_peppa_pig(element->items, ressources);
    append_chalic(element->items, ressources);
    append_sword(element->items, ressources);
}
