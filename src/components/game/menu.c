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

static void game_background(app_t *app, ressources_t ressources,
list_components_t *list)
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

static void init_game_player(app_t *app, ressources_t ressources)
{
    sfVector2f size = {70, 100};
    sfFloatRect player_frect = {0, 0, 0, 0};
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfIntRect in_rect = {16 + 48, 20, 17, 24};
    app->element->player->character->clock = sfClock_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, middle);
    sfRectangleShape_setTexture(rect, ressources.textures[TX_PLAYER], sfFalse);
    sfRectangleShape_setTextureRect(rect, in_rect);
    player_frect = sfRectangleShape_getGlobalBounds(rect);
    app->element->player->character->shape = rect;
    app->element->player->character->irect = in_rect;
    app->element->player->character->frect = player_frect;
    app->element->player->character->key.down = false;
    app->element->player->character->key.up = false;
    app->element->player->character->key.left = false;
    app->element->player->character->key.right = false;
}

static void init_player_animation(app_t *app)
{
    new_player_annimation(app, (sfIntRect){.height = 0, .left = 48,
        .top = 0, .width = 0}, 0, 4);
    app->element->player->character->annimation.speed = 0.3;
}

void components_game(app_t *app,ressources_t ressources,
list_components_t *list)
{
    game_background(app, ressources, list);
    init_player_animation(app);
    init_game_player(app, ressources);
}
