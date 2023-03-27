/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** app icon construction
*/

#include "types/type.h"
#include "ressources/textures.h"

void app_set_icon(sfRenderWindow *window, ressources_t *ressources)
{
    sfImage *icon = sfTexture_copyToImage(ressources->textures[TX_APP_ICON]);
    const sfUint8 * icon_Pixel = sfImage_getPixelsPtr(icon);
    int width = sfImage_getSize(icon).x;
    int height = sfImage_getSize(icon).y;

    sfRenderWindow_setIcon(window, width, height, icon_Pixel);
}
