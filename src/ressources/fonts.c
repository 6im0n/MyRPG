/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** fonts
*/

#include "app/app.h"
#include "app/ressources.h"
#include "app/constants.h"
#include "ressources/loaders/fonts.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

sfFont **ressources_import_fonts(app_t *app)
{
    sfFont **fonts = malloc(sizeof(sfFont *) * FT_LEN);

    if (!fonts)
        return NULL;
    for (int i = 0; i < FT_LEN; i++) {
        loader_text_display(app, app->loader->logo, fonts_loaders[i]);
        fonts[i] = sfFont_createFromFile(fonts_loaders[i]);
    }
    return (fonts);
}

void ressources_destroy_fonts(sfFont **fonts)
{
    for (int i = 0; i < FT_LEN; i++) {
        sfFont_destroy(fonts[i]);
    }
    free(fonts);
}
