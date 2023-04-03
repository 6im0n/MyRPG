/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

//==================================================
// PLAYER
//==================================================

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

//==================================================
// STATE
//==================================================

typedef enum e_stage_type {
    S_MENU_START,
    S_SETTINGS,
    S_MENU_HELP,
    S_INVENTORY,
    S_MENU_LOAD_GAME,
    S_CURSOR,
    S_LEN
} stage_t;

typedef struct s_sounds {
    sfSound *music;
    sfSound *sound;
    int stage_level;
    int volume_music;
    int volume_sound;
    bool mute;
} sounds_t;

typedef struct s_states {
    stage_t stage;
    stage_t back;
    sfClock *clock;
    bool transition;
    sounds_t *sound;
    int framerate;
} state_t;

//==================================================
// APP
//==================================================

typedef struct s_mouse {
    bool custom;
    bool pressed;
    sfVector2f press_position;
    sfVector2f last_move_position;
    sfVector2f move_diff;
    sfVector2f position;
} mouse_t;

typedef struct s_app {
    sfRenderWindow *window;
    mouse_t mouse;
    state_t *state;
    player_t *player;
} app_t;

typedef struct s_event {
    sfEvent original;
    mouse_t *mouse;
} event_t;

//==================================================
// RESSOURCES
//==================================================

typedef struct s_ressources {
    sfTexture **textures;
    sfSoundBuffer **sounds;
    sfFont **fonts;
} ressources_t;

//==================================================
// RENDERERING
//==================================================

typedef struct s_render_objects {
    sfRenderWindow *window;
    sfView *view;
    sfSprite *sprite;
    sfText *text;
    sfCircleShape *circle;
    sfRectangleShape *rectangle;
    sfClock *clock;
    sfSound *sound;
} renderer_objects_t;

typedef struct s_renderer {
    renderer_objects_t *objects;
    ressources_t *ressources;
} renderer_t;

#endif /* !TYPES_H_ */
