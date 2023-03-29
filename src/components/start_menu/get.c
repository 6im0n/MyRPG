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
    if (!mstart_menu)
        return NULL;
    components_start_menu(app, ressources, objects, mstart_menu);
    return mstart_menu;
}
