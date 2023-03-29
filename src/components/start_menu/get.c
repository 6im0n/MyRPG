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
#include <stdio.h>

node_component_t *component_pure_new(sfVector2u size)
{
    node_component_t *component = malloc(sizeof(node_component_t));
    sfFloatRect rect = { size.y, 0, 0, size.x};

    if (!component)
        return NULL;
    component->type = C_UNDEFINED;
    component->object = NULL;
    component->state = 0;
    component->rendered_rect = rect;
    component->next = NULL;
    return component;
}

list_components_t *components_get_start_menu(app_t *app,
ressources_t ressources, renderer_objects_t objects,
list_components_t *mstart_menu)
{
    node_component_t *menu_board = malloc(sizeof(node_component_t));

    (void) app;
    if (!mstart_menu)
        return NULL;
    new_component_set(menu_board, (sfFloatRect){ 10, 0, 0, 0},
    C_TYPES_RECTANGLE, TX_DIALOG_MENU_BGR);
    new_component_type(ressources, menu_board, objects, (sfVector2f){0, 0});
    new_component_size(menu_board, (sfVector2f){1750, 1700},
        (sfIntRect){.height = 250, .left = 125, .top = 0, .width = 125});
    list_component_append(mstart_menu, menu_board);

    return mstart_menu;
}
