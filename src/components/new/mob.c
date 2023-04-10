/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** mob
*/

#include "types/type.h"

static void mobs_annimation_edit(app_t *app)
{
    sfIntRect rect = app->element->mobs->character->irect;
    sfIntRect rect_a = app->element->mobs->character->annimation.rect;

    rect_a.height *= app->element->mobs->character->annimation.index;
    rect_a.top *= app->element->mobs->character->annimation.index;
    rect_a.left *= app->element->mobs->character->annimation.index;
    rect_a.width *= app->element->mobs->character->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    sfRectangleShape_setTextureRect(app->element->mobs->character->shape,
    rect);
    app->element->mobs->character->annimation.index++;
}

void new_mobs_annimation(app_t *app, sfIntRect annimation, int index, int max)
{
    if (!app->element->mobs->character)
        return;
    app->element->mobs->character->clock = sfClock_create();
    app->element->mobs->character->annimation.index = index;
    app->element->mobs->character->annimation.max = max;
    app->element->mobs->character->annimation.rect = annimation;
    mobs_annimation_edit(app);
}
