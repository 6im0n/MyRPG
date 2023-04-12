/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** mob
*/

#include "types/type.h"

static void mobs_annimation_edit(node_mobs_t *mobs)
{
    sfIntRect rect = mobs->irect;
    sfIntRect rect_a = mobs->annimation.rect;

    rect_a.height *= mobs->annimation.index;
    rect_a.top *= mobs->annimation.index;
    rect_a.left *= mobs->annimation.index;
    rect_a.width *= mobs->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    sfRectangleShape_setTextureRect(mobs->shape,
    rect);
    mobs->annimation.index++;
}

void new_mobs_annimation(node_mobs_t *mobs, sfIntRect annimation, int index, int max)
{
    if (!mobs)
        return;
    mobs->clock = sfClock_create();
    mobs->annimation.index = index;
    mobs->annimation.max = max;
    mobs->annimation.rect = annimation;
    mobs_annimation_edit(mobs);
}
