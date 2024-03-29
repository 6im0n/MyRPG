/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"
#include "event/game/global.h"
#include "components/mobs.h"
#include "types/type.h"
#include "parsing/buttons.h"
#include "types/node.h"

static void game_background(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f middle = {0, 0};
    sfVector2f position = {middle.x, middle.y };
    sfVector2u size = {0, 0};
    sfVector2f real_size = {0, 0};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_GAME_MAP, SD_NONE, FT_DROID };

    (void) app;
    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    size = sfTexture_getSize(ressources.textures[TX_GAME_MAP]);
    real_size = (sfVector2f){size.x, size.y};
    new_component_size(obj, real_size,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

static void init_game_player(app_t *app, ressources_t ressources)
{
    sfVector2f size = {125 / 2.5, 100 / 2.5};
    sfFloatRect player_frect = {0, 0, 0, 0};
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f middle = {2420, 6375};
    sfIntRect in_rect = {7 + 0, 20, 34, 28};

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setPosition(shape, middle);
    sfRectangleShape_setTexture(shape, ressources.textures[TX_PLAYER_1],
        sfFalse);
    sfRectangleShape_setTextureRect(shape, in_rect);
    player_frect = sfRectangleShape_getGlobalBounds(shape);
    app->element->player->character->time = sfTime_Zero;
    app->element->player->character->state =
        (player_states_t){true, false, false, false, false};
    app->element->player->character->shape = shape;
    app->element->player->character->irect = in_rect;
    app->element->player->character->frect = player_frect;
}

static void init_player_animation(app_t *app)
{
    new_player_annimation(app, (sfIntRect){.height = 0, .left = 48,
        .top = 0, .width = 0}, 0, 4);
    app->element->player->character->annimation.speed = 0.1;
}

void components_game(app_t *app, ressources_t ressources,
list_components_t *list)
{
    app->element->mobs = list_mob_init();
    game_background(app, ressources, list);
    init_game_player(app, ressources);
    init_player_animation(app);

    parsing_buttons(app, ressources, list, "assets/scripts/game/object.txt");
    parsing_buttons(app, ressources, list, "assets/scripts/game/beacon.txt");
    parsing_buttons(app, ressources, list, "assets/scripts/game/shrine.txt");
    parsing_buttons(app, ressources, list, "assets/scripts/game/particule.txt");
    parsing_buttons(app, ressources, list, "assets/scripts/game/quest.txt");
}
