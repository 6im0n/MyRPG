/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** mobs
*/
#include <SFML/Graphics.h>
#include "components/mobs.h"
#include "types/type.h"

static node_mob_t *init_game_mobs(node_mob_t *mob,
    sfVector2f position, ressources_t ressources)
{
    sfVector2f size = {70, 55};
    sfFloatRect mob_frect = {0, 0, 0, 0};
    sfRectangleShape *shape = sfRectangleShape_create();
    sfIntRect in_rect = {73, 0 + 55, 100, 80};

    mob->clock = sfClock_create();
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setTexture(shape, ressources.textures[TX_MOBS], sfFalse);
    sfRectangleShape_setTextureRect(shape, in_rect);
    mob_frect = sfRectangleShape_getGlobalBounds(shape);
    mob->skills.speed = 8;
    mob->radius = 100;
    mob->shape = shape;
    mob->irect = in_rect;
    mob->frect = mob_frect;
    return mob;
}

static node_mob_t *init_mobs_animation(node_mob_t *mob)
{
    new_mobs_annimation(mob, (sfIntRect){.height = 0, .left = 224,
        .top = 0, .width = 0}, 0, 7);
    mob->annimation.speed = 0.1;
    return mob;
}

void add_new_mob(app_t *app, ressources_t ressources, sfVector2f position)
{
    node_mob_t *mob = NULL;

    if (app->element->mobs->first == NULL)
        app->element->mobs = list_mobs_init();
    mob = node_mobs_init(ressources);
    mob = init_game_mobs(mob, position, ressources);
    mob = init_mobs_animation(mob);
    list_mobs_append(app->element->mobs, mob);
}
