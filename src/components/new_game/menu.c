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
#include "components/mobs.h"
#include "parsing/buttons.h"
#include "event/game/dialog.h"
#include <stdio.h>
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
    new_component_set(obj, rect, C_TYPES_BACKGROUND, style);
    new_component_type(ressources, obj, position);
    size = sfTexture_getSize(ressources.textures[TX_GAME_MAP]);
    real_size = (sfVector2f){size.x, size.y};
    new_component_size(obj, real_size,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

void components_new_game(app_t *app,ressources_t ressources,
list_components_t *list)
{
    game_background(app, ressources, list);
    parsing_buttons(app, ressources, list, "assets/scripts/game/new.txt");
}
