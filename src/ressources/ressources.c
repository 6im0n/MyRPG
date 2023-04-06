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
    sfFont **fonts = ressources_import_fonts();
    ressources_t ressources = { textures, sounds, fonts };

    return (ressources);
}

void ressources_unload(ressources_t *ressources)
{
    if (ressources) {
        ressources_destroy_textures(ressources->textures);
        ressources_destroy_sounds(ressources->sounds);
        ressources_destroy_fonts(ressources->fonts);
    }
}
