/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** textures
*/

#include "app/app.h"
#include "app/constants.h"
#include "ressources/loaders/textures.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

sfTexture **ressources_import_textures(app_t *app)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * TX_LEN);

    if (!textures)
        return NULL;
    for (int i = 0; i < TX_LEN; i++) {
        loader_text_display(app, app->loader->logo, textures_loaders[i]);
        textures[i] = sfTexture_createFromFile(textures_loaders[i], NULL);
    }
    return (textures);
}

void ressources_destroy_textures(sfTexture **textures)
{
    for (int i = 0; i < TX_LEN; i++) {
        sfTexture_destroy(textures[i]);
    }
    free(textures);
}
