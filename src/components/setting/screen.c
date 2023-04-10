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
#include "event/setting/bouton.h"

void components_menu_setting_selector_sound(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        320};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {100 / 1.3, 60 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 18, .left = 434,
                            .top = 103, .width = 28}, C_SIZE_TOP_MEDIUM);
    set_component_text(obj, "Music", sfBlack, 35);
    set_component_text_pos(obj, (sfVector2f){ 148, -14}, 2);
    obj->id = ID_SELECTOR;
    obj->features.select = true;
    obj->events.onclick = &event_settings_selector_mute_onclick;
    list_component_append(list, obj);
}

void components_setting_bouton_fullscreen(app_t *app, ressources_t ressources,
list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        470};
    sfVector2f size = {100 / 1.3, 60 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 18, .left = 434,
                            .top = 103, .width = 28}, C_SIZE_TOP_MEDIUM);
    set_component_text(obj, "FullScreen", sfBlack, 35);
    set_component_text_pos(obj, (sfVector2f){ 148, -14}, 2);
    obj->id = ID_SELECTOR;
    obj->features.select = false;
    obj->events.onclick = &event_settings_fullscreen_onclick;
    list_component_append(list, obj);
}

static sfVector2f find_position_framelimit(app_t *app, list_components_t *list)
{
    sfVector2f position = sfRectangleShape_getPosition(
        list->last->object->rectangle);
    sfFloatRect rect = list->last->features.rendered_rect;
    int pourcentage = (rect.width / 265) * app->state->framerate;

    position.x = rect.left + pourcentage;
    return position;
}

void components_menu_setting_selector_framelimit(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f middle = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        520};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {250 / 1.3, 15 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 4, .left = 277, .top = 166, .width = 38},
        C_SIZE_TOP_MEDIUM);
    obj->id = ID_FPS_CURSOR;
    set_component_text(obj, "Framerate", sfBlack, 35);
    set_component_text_pos(obj, (sfVector2f){ 148, -14}, 2);
    list_component_append(list, obj);
}

void components_menu_setting_selector_framelimit_cursor(app_t *app,
ressources_t ressources, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = find_position_framelimit(app, list);
    sfVector2f size = {30 / 1.3, 50 / 1.3};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_UI_MENU_ALL, SD_NONE, FT_DROID };

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 21, .left = 65, .top = 197, .width = 14},
        C_SIZE_TOP_MEDIUM);
    obj->events.onmove = &event_settings_selector_framerate_onclick;
    obj->events.onnonclick = &event_settings_selector_framerate_onnonclick;
    obj->events.ondisabled = &event_settings_selector_framerate_ondisabled;
    list_component_append(list, obj);
}
