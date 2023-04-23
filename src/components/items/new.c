/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new
*/

#include "types/type.h"
#include "types/list.h"
#include "ressources/loaders/items.h"

node_item_t *new_items(node_item_t *item, item_t id, sfIntRect irect,
sfFloatRect frect)
{
    skills_t skill = {
        items_loaders[id][IS_SPEED],
        items_loaders[id][IS_STRENGHT],
        items_loaders[id][IS_RESISTANCE]
    };

    if (!item)
        return NULL;
    item->shape = sfRectangleShape_create();
    item->next = NULL;
    item->item = id;
    item->skill = skill;
    item->frect = frect;
    item->irect = irect;
    item->name = NULL;
    item->sharpness = NULL;
    item->weight = NULL;
    return item;
}

void new_items_texture(node_item_t *item, ressources_t *ressources,
texture_t item_texture, sfVector2f position)
{
    sfTexture *texture = ressources->textures[item_texture];
    sfVector2f origin = { item->frect.width / 2, item->frect.height / 2 };

    sfRectangleShape_setTexture(item->shape,
        texture, sfFalse);
    sfRectangleShape_setPosition(item->shape, position);
    sfRectangleShape_setOrigin(item->shape, origin);
}

void new_items_size(node_item_t *item, sfVector2f size)
{
    sfRectangleShape_setSize(item->shape, size);
    if (item->irect.width != 0 && item->irect.height != 0)
        sfRectangleShape_setTextureRect(item->shape, item->irect);
}
