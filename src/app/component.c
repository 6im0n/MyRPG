/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** Get componenent
*/

#include <stdlib.h>
#include "types/types.h"
#include "types/list.h"
#include "components/components.h"

main_components_t app_components_load(app_t *app, ressources_t ressources,
renderer_objects_t objects)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    list_components_t *mstart_menu = list_components_init();
    main_components_t components = { NULL, NULL };
    node_component_t *first = component_pure_new(size);

    list_component_append(mstart_menu, first);
    components.start_menu = mstart_menu;
    components_get_start_menu(app, ressources, objects, mstart_menu);
    return components;
}
