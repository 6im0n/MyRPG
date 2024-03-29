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
#include "types/node.h"

node_component_t *component_pure_new(sfVector2u size)
{
    node_component_t *component = node_component_init();
    sfFloatRect rect = { size.y, 0, 0, size.x};

    if (!component)
        return NULL;
    component->type = C_UNDEFINED;
    component->object = NULL;
    component->state = 0;
    component->events = (component_events_t) { NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL };
    component->features.rendered_rect = rect;
    component->next = NULL;
    return component;
}

void components_get_start_menu(app_t *app,
ressources_t ressources, list_components_t *list)
{
    if (!list)
        return;
    components_menu_start(app, ressources, list);
}
