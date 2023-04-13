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

static void game_background(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
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
    sfVector2f size = {70 / 2.5, 100 / 2.5};
    sfFloatRect player_frect = {0, 0, 0, 0};
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f middle = {2420, 6375};
    sfIntRect in_rect = {16 + 48, 20, 17, 24};
    app->element->player->character->clock = sfClock_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setPosition(shape, middle);
    sfRectangleShape_setTexture(shape, ressources.textures[TX_PLAYER_1],
        sfFalse);
    sfRectangleShape_setTextureRect(shape, in_rect);
    player_frect = sfRectangleShape_getGlobalBounds(shape);
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
    app->element->mobs = list_mobs_init();
    game_background(app, ressources, list);
    init_game_player(app, ressources);
    init_player_animation(app);

    add_new_mob(app, ressources, (sfVector2f){2420, 6375});
    add_new_mob(app, ressources, (sfVector2f){2420 - 200, 6375 - 200});
    sfRectangleShape_setOutlineColor(app->element->player->character->shape,
                                    sfRed);
    sfRectangleShape_setOutlineThickness (
        app->element->player->character->shape, 2);
    parsing_buttons(app, ressources, list, "assets/scripts/game/object.txt");
}
