/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/mobs.h"
#include "types/list.h"

static mobs_component_t *init_character(ressources_t *ressources)
{
    mobs_component_t *character = malloc(sizeof(mobs_component_t));
    sfFloatRect frect = {0, 0, 0, 0};
    sfIntRect irect = {0, 0, 0, 0};
    if (!character)
        return NULL;
    character->texture = ressources->textures[TX_APP_ICON];
    character->shape = sfRectangleShape_create();
    character->frect = frect;
    character->irect = irect;
    return character;
}

mobs_t *mobs_create(ressources_t *ressources)
{
    mobs_component_t *character = init_character(ressources);
    mobs_t *mobs = malloc(sizeof(mobs_t));

    if (!mobs)
        return NULL;
    mobs->character = character;
    return mobs;
}

void mobs_destroy(mobs_t *mobs)
{
    sfRectangleShape_destroy(mobs->character->shape);
    free(mobs->character);
    free(mobs);
}
