/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/types.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "event/start_menu/bouton.h"
#include "components/get.h"

static void menu_background(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
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
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 0, .left = 0, .top = 0, .width = 0},
        C_SIZE_MAX);
    list_component_append(list, obj);
}

static void bouton_home(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1850,
        50};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 773, .top = 68, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Home", sfTransparent, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_bouton_help_onclick;
    obj->events.onhover = &event_bouton_help_onhover;
    obj->events.ondisabled = &event_bouton_help_ondisabled;
    list_component_append(list, obj);
}

static void bouton_close(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1850,
        130};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 837, .top = 164, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Close", sfTransparent, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_bouton_help_close_onclick;
    obj->events.onhover = &event_bouton_help_onhover;
    obj->events.ondisabled = &event_bouton_help_ondisabled;
    list_component_append(list, obj);
}

static void sign_rpg(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2,
        800};
    sfVector2f size = {1080, 300};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,(sfIntRect){.height = 122, .left = 139,
                                        .top = 12, .width = 106}, C_SIZE_BIG);
    set_component_text(obj, "RPG", sfBlack, 300);
    set_component_text_pos(obj, (sfVector2f){ 0, -130}, 0);
    list_component_append(list, obj);
}

list_components_t *components_menu_help(app_t *app,ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    menu_background(app, ressources, objects, list);
    components_help_bouton_move(app, ressources, objects, list);
    components_help_command_setting(app, ressources, objects, list);
    components_help_command_inventory(app, ressources, objects, list);
    bouton_home(app, ressources, objects, list);
    bouton_close(app, ressources, objects, list);
    sign_rpg(app, ressources, objects, list);
    component_cursor_default(app, ressources, objects, list);
    return list;
}
