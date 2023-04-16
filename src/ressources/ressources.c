/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** ressources
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "app/ressources.h"

ressources_t ressources_load(app_t *app)
{
    sfTexture **textures = ressources_import_textures(app);
    sfSoundBuffer **sounds = ressources_import_sounds(app);
    sfFont **fonts = ressources_import_fonts(app);
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
