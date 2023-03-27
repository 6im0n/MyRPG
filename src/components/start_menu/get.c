/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/types.h"
#include "components/components.h"

static component_t *component_pure_new(sfVector2u size)
{
    component_t *component = malloc(sizeof(component_t));
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

void component_pure_free(component_t *component_pure)
{
    if (!component_pure)
        return;
    free(component_pure);
}

component_t *components_get_start_menu(app_t *app)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    component_t *menu = component_pure_new(size);

    if (!menu)
        return menu;
    return menu;
}
