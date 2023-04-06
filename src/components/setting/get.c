/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "types/types.h"
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"

list_components_t *components_get_setting(app_t *app,
ressources_t ressources, renderer_objects_t objects,
list_components_t *list)
{
    if (!list)
        return NULL;
    components_setting(app, ressources, objects, list);
    return list;
}
