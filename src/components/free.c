/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** free
*/

#include <stdlib.h>
#include "types/list.h"
#include "components/components.h"

void components_free(main_components_t *components)
{
    if (components->start_menu) {
        list_components_free(components->start_menu);
    }
}
