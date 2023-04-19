/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** collisions
*/

#include <stdio.h>
#include "types/type.h"

static void update_colors(player_t *player, sfVector2f position)
{
    int x = position.x + 14;
    int y = position.y + 20;
    sfColor top = sfImage_getPixel(player->collisions, x, y);
    sfColor bottom = sfImage_getPixel(player->collisions, x, y + 20);
    sfColor left = sfImage_getPixel(player->collisions, x - 14, y + 10);
    sfColor right = sfImage_getPixel(player->collisions, x + 14, y + 10);

    player->colors.top = top;
    player->colors.bottom = bottom;
    player->colors.right = right;
    player->colors.left = left;
}

static bool is_red(sfColor color, player_t *player)
{
    bool r = color.r == 255;
    bool g = color.g == 33;
    bool b = color.b == 0;
    bool a = color.a == 255;

    if (r && g && b && a && player->exprerience.level > 1)
        return true;
    return false;
}

static bool is_yellow(sfColor color, player_t *player)
{
    bool r = color.r == 255;
    bool g = color.g == 216;
    bool b = color.b == 0;
    bool a = color.a == 255;

    if (r && g && b && a && player->exprerience.level > 0)
        return true;
    return false;
}

void collisions(bool *array, sfVector2f position, player_t *player)
{
    update_colors(player, position);
    if (player->colors.top.a != 255 ||
        is_yellow(player->colors.top, player) ||
        is_red(player->colors.top, player))
        array[0] = true;
    if (player->colors.bottom.a != 255 ||
        is_yellow(player->colors.bottom, player) ||
        is_red(player->colors.bottom, player))
        array[1] = true;
    if (player->colors.right.a != 255 ||
        is_yellow(player->colors.right, player) ||
        is_red(player->colors.right, player))
        array[2] = true;
    if (player->colors.left.a != 255 ||
        is_yellow(player->colors.left, player) ||
        is_red(player->colors.left, player))
        array[3] = true;
}
