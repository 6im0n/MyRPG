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
#include "event/annimation.h"
#include "event/global.h"

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
    component_styles style = { TX_GAME_MAP, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_RECTANGLE, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

static void bouton_home(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1850,
        50};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 773, .top = 68, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Home", sfTransparent, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_help_bouton_home_onclick;
    obj->events.onhover = &event_bouton_help_onhover;
    obj->events.ondisabled = &event_bouton_help_ondisabled;
    list_component_append(list, obj);
}

static void bouton_close(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1850,
        130};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 837, .top = 164, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Close", sfTransparent, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_close_current_stage_onclick;
    obj->events.onhover = &event_bouton_help_onhover;
    obj->events.ondisabled = &event_bouton_help_ondisabled;
    list_component_append(list, obj);
}

static void annimation_altar(ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1920 / 2, 650};
    sfVector2f size = {448, 500};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_ALTAR_1, SD_NONE, FT_IMMORTAL };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 288,
        .left = 0, .top = 0, .width = 224}, C_SIZE_MAX);
    new_component_annimation(obj, (sfIntRect){.height = 0, .left = 224,
        .top = 0, .width = 0}, 25, 38);
    set_component_text(obj, "Altar", sfTransparent, 50);
    set_component_text_pos(obj, (sfVector2f){ 0, 75}, 3);
    obj->events.onhover = &event_active_annimation;
    obj->events.ondisabled = &event_disabled_annimation;
    list_component_append(list, obj);
}

void components_menu_help(app_t *app,ressources_t ressources,
list_components_t *list)
{
    menu_background(app, ressources, list);
    components_help_bouton_move(app, ressources, list);
    components_help_command_setting(app, ressources, list);
    components_help_command_inventory(app, ressources, list);
    bouton_home(app, ressources, list);
    bouton_close(app, ressources, list);
    annimation_altar(ressources, list);
}
