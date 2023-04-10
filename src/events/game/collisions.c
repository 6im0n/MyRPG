/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** collisions
*/

#include <stdio.h>
#include "types/type.h"

void collisions(bool *array, sfVector2f position, player_t *player)
{
    sfColor top = sfImage_getPixel(player->collisions, position.x + 17.5 - 0, position.y + 25 - 10);
    sfColor bottom = sfImage_getPixel(player->collisions, position.x + 17.5 + 0, position.y + 25 + 25);
    sfColor left = sfImage_getPixel(player->collisions, position.x - 17.5 + 17.5, position.y + 25 + 25);
    sfColor right = sfImage_getPixel(player->collisions, position.x + 17.5 + 17.5, position.y + 25 + 25);

    printf("Positon: x: %.2f | y: %.2f\n", position.x, position.y);
    if (top.a != 255)
        array[0] = true;
    if (bottom.a != 255)
        array[1] = true;
    if (right.a != 255)
        array[2] = true;
    if (left.a!= 255)
        array[3] = true;
}
