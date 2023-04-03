/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "components/player.h"
#include "types/list.h"

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
    return character;
}

static experience_t init_experience(void)
{
    experience_t xp;

    xp.level = 0;
    xp.xp = 0;
    return xp;
}

static skills_t init_skills(void)
{
    skills_t skills;

    skills.resitance = 0;
    skills.speed = 0;
    skills.strength = 0;
    return skills;
}

player_t player_create(ressources_t *ressources)
{
    list_item_t *inventory = list_item_init();
    character_t *character = init_character(ressources);
    skills_t skills = init_skills();
    experience_t xp = init_experience();
    player_t player = { inventory, character, skills, xp };

    return player;
}

void player_destroy(player_t *player)
{
    sfRectangleShape_destroy(player->character->shape);
    free(player->character);
    list_item_free(player->inventory);
}
