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

void bouton_play(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2,
        700};
    sfVector2f size = {340, 90};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    new_component_set(obj, rect, C_TYPES_BUTTON, TX_MENU_ALL);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 27, .left = 163, .top = 210, .width = 90},
        C_SIZE_BIG);
    list_component_append(list, obj);
}

void bouton_help(app_t *app, ressources_t ressources,
renderer_objects_t objects, list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {1500,
        240};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};

    (void) app;
    new_component_set(obj, rect, C_TYPES_BUTTON, TX_MENU_ALL);
    new_component_type(ressources, obj, objects, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 709, .top = 164, .width = 22},
        C_SIZE_SMALL);
    obj->events.onclick = &event_bouton_play_onclick;
    list_component_append(list, obj);
}
