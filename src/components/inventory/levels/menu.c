/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** menu
*/

#include <stdio.h>
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"
#include "app/constants.h"
#include "parsing/buttons.h"
#include "types/node.h"

void components_levels(app_t *app,ressources_t ressources,
                            list_components_t *list)
{
    char *path = "assets/scripts/inventory/levels.txt";

    parsing_buttons(app, ressources, list, path);
}
