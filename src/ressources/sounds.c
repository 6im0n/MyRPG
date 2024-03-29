/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** textures
*/

#include "app/app.h"
#include "app/constants.h"
#include "ressources/loaders/sounds.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

sfSoundBuffer **ressources_import_sounds(app_t *app)
{
    sfSoundBuffer **sounds = malloc(sizeof(sfSoundBuffer*) * SD_LEN);

    if (!sounds)
        return NULL;
    for (int i = 0; i < SD_LEN; i++) {
        loader_text_display(app, app->loader->logo, sounds_loaders[i]);
        sounds[i] = sfSoundBuffer_createFromFile(sounds_loaders[i]);
    }
    return (sounds);
}

void ressources_destroy_sounds(sfSoundBuffer **sounds)
{
    for (int i = 0; i < SD_LEN; i++) {
        sfSoundBuffer_destroy(sounds[i]);
    }
    free(sounds);
}
