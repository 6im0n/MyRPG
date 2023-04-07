/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/type.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "event/start_menu/bouton.h"
#include "components/get.h"
#include "event/annimation.h"
#include "event/game/global.h"

static void game_background(app_t *app, ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {sfRenderWindow_getSize(app->window).x,
        sfRenderWindow_getSize(app->window).y};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_GAME_MAP, SD_NONE, FT_ARIAL };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

static void game_player(app_t *app, ressources_t ressources)
{
    sfVector2f size = {70, 100};
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfIntRect rect = {.height = 24, .left = 16+48, .top = 20, .width = 17};
    app->element->player->character->clock = sfClock_create();

    app->element->player->character->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(app->element->player->character->shape, size);
    sfRectangleShape_setPosition(app->element->player->character->shape, middle);
    sfRectangleShape_setTexture(app->element->player->character->shape,
        ressources.textures[TX_PLAYER], sfFalse);
    sfRectangleShape_setTextureRect(app->element->player->character->shape, rect);

    app->element->player->character->irect = rect;
    app->element->player->character->frect = sfRectangleShape_getGlobalBounds(app->element->player->character->shape);
    app->element->player->character->key.down = false;
    app->element->player->character->key.up = false;
    app->element->player->character->key.left = false;
    app->element->player->character->key.right = false;
}


list_components_t *components_game(app_t *app,ressources_t ressources,
list_components_t *list)
{
    game_background(app, ressources, list);
    game_player(app, ressources);
    return list;
}
