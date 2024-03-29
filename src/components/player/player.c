/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "components/player.h"
#include "types/list.h"
#include "ressources/loaders/textures.h"

static character_t *init_character(ressources_t *ressources)
{
    character_t *character = malloc(sizeof(character_t));
    sfFloatRect frect = {0, 0, 0, 0};
    sfIntRect irect = {0, 0, 0, 0};

    if (!character)
        return NULL;
    character->texture = ressources->textures[TX_APP_ICON];
    character->shape = sfRectangleShape_create();
    character->frect = frect;
    character->irect = irect;
    character->tx = TX_PLAYER_2;
    character->key = (key_player_t){false, false, false, false, 1};
    return character;
}

static experience_t init_experience(void)
{
    experience_t xp;
    xp.level = 0;
    xp.xp = 0;
    xp.max_xp = 100.0;
    xp.update = 0;
    xp.skill = 0;
    return xp;
}

static skills_t init_skills(void)
{
    skills_t skills;
    skills.resitance = 0;
    skills.speed = 20;
    skills.strength = 0;
    return skills;
}

player_t *player_create(ressources_t *ressources)
{
    list_item_t *inventory = list_item_init();
    character_t *character = init_character(ressources);
    skills_t skills = init_skills();
    experience_t xp = init_experience();
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->character = character;
    player->inventory = inventory;
    player->exprerience = xp;
    player->skills = skills;
    player->view = sfView_create();
    player->collisions = sfImage_createFromFile(textures_loaders[TX_COLLISION]);
    player->colors = (colors_t) {sfBlack, sfBlack, sfBlack, sfBlack};
    player->life = 10;
    player->front = false;
    player->heart = sfSound_create();
    player->playing = false;
    return player;
}

void player_destroy(player_t *player)
{
    sfRectangleShape_destroy(player->character->shape);
    sfView_destroy(player->view);
    sfSound_destroy(player->heart);
    free(player->character);
    free(player);
}
