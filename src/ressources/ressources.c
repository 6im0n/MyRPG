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
    sfSoundBuffer **sounds = ressources_import_sounds();
    ressources_t ressources = { textures, sounds };

    return (ressources);
}

void ressources_unload(ressources_t *ressources)
{
    if (ressources) {
        ressources_destroy_textures(ressources->textures);
        ressources_destroy_sounds(ressources->sounds);
    }
}
