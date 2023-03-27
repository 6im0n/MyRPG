/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** ressources
*/

#include <SFML/Graphics.h>
#include "app/ressources.h"

ressources_t ressources_load(void)
{
    sfTexture **textures = ressources_import_textures();
    ressources_t ressources = { textures };

    return (ressources);
}

void ressources_unload(ressources_t *ressources)
{
    if (ressources) {
        ressources_destroy_textures(ressources->textures);
    }
}
