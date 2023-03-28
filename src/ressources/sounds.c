/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** textures
*/

#include "app/constants.h"
#include "ressources/loaders/sounds.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

sfSound **ressources_import_sounds(void)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * SD_LEN);
    sfSound *music = sfSound_create();
    sfSoundBuffer *buffer = NULL;

    if (!sounds)
        return NULL;
    for (int i = 0; i < SD_LEN; i++) {
        buffer = sfSoundBuffer_createFromFile(sounds_loaders[i]);
        sfSound_setBuffer(music, buffer);
        sounds[i] = music;
        sfSoundBuffer_destroy(buffer);
    }
    return (sounds);
}

void ressources_destroy_sounds(sfSound **sounds)
{
    for (int i = 0; i < SD_LEN; i++) {
        sfSound_destroy(sounds[i]);
    }
    free(sounds);
}
