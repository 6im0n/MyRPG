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

void components_get_help_menu(app_t *app, ressources_t ressources,
                                list_components_t *list)
{
    if (!list)
        return;
    components_menu_help(app, ressources, list);
}
