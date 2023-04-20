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
    #include "ressources/textures.h"
    #include "components/popup.h"
    #include "ressources/quests.h"

typedef enum e_id_component {
    ID_UNDEFINED,
    ID_SLOT_1,
    ID_SLOT_2,
    ID_SLOT_3,
    ID_SLOT_4,
    ID_SLOT_5,
    ID_SLOT_6,
    ID_SLOT_7,
    ID_SLOT_8,
    ID_SELECTOR,
    ID_MAIN_INV_SELECTOR,
    ID_FPS_CURSOR,
    ID_MUSIC_CURSOR,
    ID_SOUND_CURSOR,
    ID_CURSOR,
    ID_S_PLAYER,
    ID_RESUME,
    ID_XP,
    ID_LEVEL,
    ID_LEN
} component_id_t;

//==================================================
// PLAYER
//==================================================

typedef enum e_item {
    I_NONE,
    I_SWORD_PIG,
    I_SWORD_LEV1,
    I_KNIFE_LEV1,
    I_HAMMER_LEV1,
    I_SPEAR_LEV1,
    I_AXE_LEV1,
    I_SWORD_LEV2,
    I_KNIFE_LEV2,
    I_HAMMER_LEV2,
    I_SPEAR_LEV2,
    I_AXE_LEV2,
    I_SWORD_LEV3,
    I_KNIFE_LEV3,
    I_HAMMER_LEV3,
    I_SPEAR_LEV3,
    I_AXE_LEV3,
    I_SWORD_LEV4,
    I_KNIFE_LEV4,
    I_HAMMER_LEV4,
    I_SPEAR_LEV4,
    I_AXE_LEV4,
    I_CHALICE,
    I_HEALT_POTION
} item_t;

typedef struct s_node_item {
    struct s_node_item *next;
    item_t item;
    component_id_t slot;
    sfRectangleShape *shape;
    sfFloatRect frect;
    sfIntRect irect;
    char *name;
    struct s_node_item *prev;
} node_item_t;

typedef struct s_list_item {
    node_item_t *first;
    int len;
    node_item_t *last;
    component_id_t last_select;
    component_id_t select;
    component_id_t selector;
} list_item_t;

typedef struct s_exprerience {
    int xp;
    int level;
    float max_xp;
} experience_t;

typedef struct s_skills {
    int speed;
    int strength;
    int resitance;
} skills_t;

typedef struct s_character_annimation {
    sfIntRect rect;
    int index;
    int max;
    float speed;
    float max_speed;
    sfClock *clock;
} character_annimation_t;

typedef struct s_key_player {
    bool up;
    bool down;
    bool left;
    bool right;
    int old_key;
} key_player_t;

typedef struct s_player_states {
    bool idle;
    bool walk;
    bool attack;
    bool die;
    bool hit;
} player_states_t;

typedef struct s_character {
    sfTexture *texture;
    sfRectangleShape *shape;
    sfFloatRect frect;
    sfIntRect irect;
    sfTime time;
    sfTime time_hit;
    player_states_t state;
    character_annimation_t annimation;
    key_player_t key;
    texture_t tx;
} character_t;

typedef struct s_colors {
    sfColor top ;
    sfColor bottom;
    sfColor right;
    sfColor left;
} colors_t;

typedef struct s_player {
    list_item_t *inventory;
    character_t *character;
    skills_t skills;
    experience_t exprerience;
    sfView *view;
    sfImage *collisions;
    colors_t colors;
    int life;
} player_t;

//==================================================
// QUESTS
//==================================================

typedef struct s_node_quests_text {
    char *title;
    char *description;
    char *detail;
    char *objectif;
    char *reward;
} node_quests_text_t;

typedef struct s_node_quests {
    struct s_node_quests *next;
    node_quests_text_t *text;
    int current;
    int goal;
    bool finish;
    sfRectangleShape *shape;
    sfText *txt;
    quests_t id;
    struct s_node_quests *prev;
} node_quests_t;

typedef struct s_list_quests {
    node_quests_t *first;
    int len;
    node_quests_t *last;
} list_quests_t;

//==================================================
// MOBS
//==================================================
typedef struct healt_s {
    float curent;
    float max;
    sfRectangleShape *bar;
    sfRectangleShape *outline;
    sfFloatRect frect;
} healt_t;

typedef struct s_mobs_annimation {
    sfIntRect rect;
    int index;
    int max;
    float speed;
    float max_speed;
} mobs_annimation_t;

typedef struct s_mob_states {
    bool idle;
    bool walk;
    bool attack;
    bool die;
    bool hit;
} mob_states_t;

typedef struct s_node_mob {
    float radius;
    sfTexture *texture;
    sfRectangleShape *shape;
    sfFloatRect frect;
    sfIntRect irect;
    sfTime time;
    sfClock *clock;
    skills_t skills;
    healt_t healt;
    mob_states_t state;
    mobs_annimation_t annimation;
    struct s_node_mob *next;
    struct s_node_mob *prev;
} node_mob_t;

typedef struct list_mobs {
    int len;
    struct s_node_mob *first;
    struct s_node_mob *last;
} list_mobs_t;

//==================================================
// GAME
//==================================================
typedef struct s_game_elements {
    list_item_t *items;
    player_t *player;
    list_mobs_t *mobs;
    list_quests_t *quests;
    list_pop_up_t *pop_up;
} elements_t;

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
    S_GAME,
    S_NEW_GAME,
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

typedef struct s_loader_components {
    sfRectangleShape *shape;
    sfRectangleShape *cursor;
    sfRectangleShape *logo;
    sfText *text;
} loader_t;

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
    sfView *background;
    sfView *view;
    sfRectangleShape *layer;
    elements_t *element;
    loader_t *loader;
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
