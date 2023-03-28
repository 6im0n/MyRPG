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

main_components_t app_components_load(app_t *app)
{
    list_components_t *mstart_menu = list_components_init();
    main_components_t components = { NULL, NULL };
    node_component_t *first = components_get_start_menu(app);

    list_component_append(mstart_menu, first);
    components.start_menu = mstart_menu;
    return components;
}
