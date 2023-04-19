/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** layers
*/

#include "types/type.h"
#include "types/list.h"
#include "types/node.h"

static void init_game_layer(node_layer_t *layer, ressources_t ressources,
                            int index)
{
    sfVector2f size = {50, 50};
    sfFloatRect layer_frect = {0, 0, 0, 0};
    sfIntRect in_rect = {581 - 1, 68 + 15, 7 + 2, 7 + 2};
    sfTexture *texture = ressources.textures[TX_UI_MENU_ALL];
    sfVector2f position = {20 + (index * 65), 20};

    sfRectangleShape_setSize(layer->obj, size);
    sfRectangleShape_setPosition(layer->obj, position);
    sfRectangleShape_setTexture(layer->obj, texture, sfFalse);
    sfRectangleShape_setTextureRect(layer->obj, in_rect);
    layer_frect = sfRectangleShape_getGlobalBounds(layer->obj);
    layer->irect = in_rect;
    layer->frect = layer_frect;
}

void layers_init(app_t *app, ressources_t ressources)
{
    node_layer_t *layer = NULL;

    for (int i = 0; i < 5; i++) {
        layer = layer_node_init();
        init_game_layer(layer, ressources, i);
        layer->id = ID_HEART_1 + i;
        list_layer_append(app->element->layers, layer);
    }
}
