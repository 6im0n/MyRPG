/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** mobs
*/
#include <SFML/Graphics.h>
#include "components/mobs.h"
#include "types/type.h"

static void init_game_mobs(node_mob_t *mob,
    sfVector2f position, ressources_t ressources)
{
    sfVector2f size = {70, 55};
    sfFloatRect mob_frect = {0, 0, 0, 0};
    sfIntRect in_rect = {73, 0 + 55, 100, 80};
    sfTexture *texture = ressources.textures[TX_MOBS];

    sfRectangleShape_setSize(mob->obj_shape, size);
    sfRectangleShape_setPosition(mob->obj_shape, position);
    sfRectangleShape_setTexture(mob->obj_shape, texture, sfFalse);
    sfRectangleShape_setTextureRect(mob->obj_shape, in_rect);
    mob_frect = sfRectangleShape_getGlobalBounds(mob->obj_shape);
    mob->skills.speed = 8;
    mob->radius = 100;
    mob->irect = in_rect;
    mob->frect = mob_frect;
}

static void init_mobs_animation(node_mob_t *mob)
{
    new_mobs_annimation(mob, (sfIntRect){.height = 0, .left = 224,
        .top = 0, .width = 0}, 0, 7);
    mob->annimation.speed = 0.1;
}

void add_new_mob(app_t *app, ressources_t ressources, sfVector2f position)
{
    node_mob_t *mob = NULL;

    mob = node_mobs_init(ressources);
    init_game_mobs(mob, position, ressources);
    init_mobs_animation(mob);
    list_mobs_append(app->element->mobs, mob);
}
