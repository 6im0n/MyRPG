/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** Get componenent
*/

#include <stdlib.h>
#include "types/types.h"
#include "components/components.h"

main_components_t app_components_load(app_t *app)
{
    component_t *start_menu = components_get_start_menu(app);
    component_t *game = NULL;
    main_components_t components = { start_menu, game };

    return components;
}
