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
#include "event/setting/bouton.h"

void components_setting_bouton_quit(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 200,
        850};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 772, .top = 163, .width = 22},
        C_SIZE_SMALL);
    obj->events.onclick = &event_setting_close_windows_onclick;
    list_component_append(list, obj);
}

void components_setting_bouton_quit_title(app_t *app,
ressources_t ressources, renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = sfRectangleShape_getPosition(
        list->last->object->rectangle);
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    position.x += 135;
    position.y -= 13;
    new_component_set(obj, rect, C_TYPES_TEXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Close the game", sfBlack, 35);
    obj->id = ID_VOLUME_CURSOR;
    list_component_append(list, obj);
}

void components_setting_bouton_resume(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 200,
        850};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_NONE, FT_ARIAL };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 837, .top = 164, .width = 22},
        C_SIZE_SMALL);
    obj->events.onclick = &event_close_onclick;
    list_component_append(list, obj);
}

void components_setting_bouton_resume_title(app_t *app,
ressources_t ressources, renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = sfRectangleShape_getPosition(
        list->last->object->rectangle);
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };

    (void) app;
    position.x += 85;
    position.y -= 18;
    new_component_set(obj, rect, C_TYPES_TEXT, style);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106},
        C_SIZE_MAX);
    set_component_text(obj, "Resume", sfBlack, 36);
    obj->id = ID_VOLUME_CURSOR;
    list_component_append(list, obj);
}
