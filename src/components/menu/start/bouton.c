/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>

#include "parsing/buttons.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "event/start_menu/bouton.h"
#include "event/setting/bouton.h"
#include "event/global.h"

void components_menu_start_bouton_play(app_t *app, ressources_t ressources,
                                    list_components_t *list)
{
    parsing_buttons(app, ressources, list, "assets/scripts/menu/button/play.txt");
}

void components_menu_start_bouton_help(app_t *app, ressources_t ressources,
                                        list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 80,
        713};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_GRAB, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 709, .top = 164, .width = 22},
        C_SIZE_SMALL);
    obj->events.onclick = &event_open_help_onclick;
    list_component_append(list, obj);
}

void components_menu_start_bouton_quit(app_t *app, ressources_t ressources,
                                    list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 80,
        713};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_GRAB, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 772, .top = 163, .width = 22},
        C_SIZE_SMALL);
    obj->events.onclick = &event_quit_app_onclick;
    list_component_append(list, obj);
}

void components_menu_start_bouton_setting(app_t *app, ressources_t ressources,
                                            list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2,
        713};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_GRAB, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 645, .top = 68, .width = 22},
        C_SIZE_SMALL);
    obj->events.onclick = &event_open_setting_onclick;
    list_component_append(list, obj);
}
