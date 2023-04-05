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
#include "event/start_menu/bouton.h"
#include "components/get.h"

static void menu_background(app_t *app, ressources_t ressources,
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
    component_styles style = { TX_BACKGROUND_MENU, SD_NONE, FT_ARIAL };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 0, .left = 0,
        .top = 0, .width = 0}, C_SIZE_MAX);
    list_component_append(list, obj);
}

static void menu_board(app_t *app, ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {middle.x * 1.3 , middle.y * 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_IMMORTAL };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Island'or", sfBlack, 150);
    set_component_text_pos(obj, (sfVector2f){ 0, -200}, 0);
    list_component_append(list, obj);
}

static void setting_background(app_t *app, ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2, 700};
    sfVector2f size = {300, 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 504, .top = 148, .width = 35},
        C_SIZE_SMALL);
    list_component_append(list, obj);
}

void components_menu_start(app_t *app,ressources_t ressources,
                                        list_components_t *list)
{
    menu_background(app, ressources, list);
    menu_board(app, ressources, list);
    setting_background(app, ressources, list);
    components_menu_start_bouton_play(app, ressources, list);
    // components_menu_start_bouton_help(app, ressources, list);
    components_menu_start_bouton_setting(app, ressources, list);
    components_menu_start_bouton_quit(app, ressources, list);
    components_menu_start_annimation(ressources, list);
}
