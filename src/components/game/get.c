/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/type.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"

list_components_t *components_get_game(app_t *app,
ressources_t ressources, list_components_t *list)
{
    if (!list)
        return NULL;
    components_game(app, ressources, list);
    return list;
}
