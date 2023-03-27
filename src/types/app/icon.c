/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** app icon construction
*/

#include "types/types.h"
#include "app/constants.h"

void app_set_icon(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile(WINDOW_ICON_PATH);
    const sfUint8 * icon_Pixel = sfImage_getPixelsPtr(icon);
    int width = sfImage_getSize(icon).x;
    int height = sfImage_getSize(icon).y;

    sfRenderWindow_setIcon(window, width, height, icon_Pixel);
}
