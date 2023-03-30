/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Get componenent
*/

#include <stdlib.h>
#include "types/types.h"
#include "types/list.h"
#include "components/components.h"
#include "components/get.h"

static void append_menu_start(app_t *app, ressources_t ressources,
renderer_objects_t objects, main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fstart_menu = component_pure_new(size);
    list_components_t *mstart_menu = list_components_init();

    list_component_append(mstart_menu, fstart_menu);
    components->start_menu = mstart_menu;
    components_get_start_menu(app, ressources, objects, mstart_menu);
}

static void append_menu_help(app_t *app, ressources_t ressources,
renderer_objects_t objects, main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fhelp_menu = component_pure_new(size);
    list_components_t *mhelp_menu = list_components_init();

    list_component_append(mhelp_menu, fhelp_menu);
    components->help_menu = mhelp_menu;
    components_get_help_menu(app, ressources, objects, mhelp_menu);
}

main_components_t app_components_load(app_t *app, ressources_t ressources,
renderer_objects_t objects)
{
    main_components_t components = { NULL, NULL, NULL };

    append_menu_start(app, ressources, objects, &components);
    append_menu_help(app, ressources, objects, &components);
    return components;
}
