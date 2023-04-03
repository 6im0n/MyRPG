/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "ressources/textures.h"
    #include "ressources/sounds.h"
    #include "ressources/fonts.h"

typedef enum e_item {
    I_NONE,
    I_SWORD,
    I_HEALT_POTION
} item_t;

typedef struct s_node_item {
    struct s_node_item *next;
    item_t *item;
    sfRectangleShape *shape;
    sfFloatRect *frect;
    sfIntRect *irect;
    struct s_node_item *prev;
} node_item_t;

typedef struct s_list_item {
    node_item_t *first;
    int len;
    node_item_t *last;
} list_item_t;

typedef struct s_exprerience {
    int xp;
    int level;
} experience_t;

typedef struct s_skills {
    int speed;
    int strength;
    int resitance;
} skills_t;

typedef struct s_character {
    sfTexture *texture;
    sfRectangleShape *shape;
    sfFloatRect frect;
    sfIntRect irect;
} character_t;

typedef struct s_player {
    list_item_t *inventory;
    character_t *character;
    skills_t skills;
    experience_t exprerience;
} player_t;

/**
 * @brief Create a player
 * @return player_t*
 */
player_t player_create(ressources_t *ressources);

/**
 * @brief Destroyed a player
 * @param player 
 */
void player_destroy(player_t *player);

#endif /* !PLAYER_H_ */
