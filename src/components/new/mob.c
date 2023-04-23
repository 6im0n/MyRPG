/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** mob
*/

#include "types/type.h"

static void mob_annimation_edit(node_mob_t *mob)
{
    sfIntRect rect = mob->irect;
    sfIntRect rect_a = mob->annimation.rect;

    rect_a.height *= mob->annimation.index;
    rect_a.top *= mob->annimation.index;
    rect_a.left *= mob->annimation.index;
    rect_a.width *= mob->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    sfRectangleShape_setTextureRect(mob->obj_shape, rect);
    mob->annimation.index++;
}

void new_mob_annimation(node_mob_t *mob,
sfIntRect annimation, int index, int max)
{
    if (!mob)
        return;
    mob->clock = sfClock_create();
    mob->annimation.index = index;
    mob->annimation.max = max;
    mob->annimation.rect = annimation;
    mob_annimation_edit(mob);
}
