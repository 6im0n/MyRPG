/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef COMPONENTS_H_
    #define COMPONENTS_H_

    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include "ressources/textures.h"
    #include "ressources/sounds.h"
    #include "ressources/fonts.h"

typedef struct s_node_components node_component_t;

typedef enum e_component_size {
    C_SIZE_SMALL,
    C_SIZE_MEDIUM,
    C_SIZE_BIG,
    C_SIZE_MAX,
    C_SIZE_TOP_MEDIUM,
    C_SIZE_LEN
} component_size_t;

typedef enum e_component_type {
    C_UNDEFINED,
    C_TYPES_RECTANGLE,
    C_TYPES_BUTTON,
    C_TYPES_BTN_TXT,
    C_TYPES_SIGN,
    C_TYPES_CIRCLE,
    C_TYPES_TEXT,
    C_TYPES_SPRITE,
    C_TYPES_BACKGROUND,
    C_TYPES_CURSOR,
    C_TYPES_LEN
} component_type_t;

typedef void (*component_handler_t)(node_component_t *component,
event_t *event, app_t *app);

typedef struct s_component_events {
    component_handler_t onclick;
    component_handler_t onhover;
    component_handler_t onmove;
    component_handler_t onnonclick;
    component_handler_t onkeypress;
    component_handler_t onkeyrelease;
    component_handler_t ondisabled;
    component_handler_t next_to;
} component_events_t;

typedef struct s_component_styles {
    texture_t texture;
    sound_t sound;
    font_t font;
} component_styles;

typedef struct s_component_features {
    component_styles styles;
    component_size_t size;
    sfFloatRect rendered_rect;
    sfIntRect texture_rect;
    bool select;
    int radius;
} component_feat_t;

typedef struct s_component_annimation {
    sfIntRect rect;
    int index;
    int max;
    float speed;
    float max_speed;
} component_annimation_t;

typedef struct s_node_components {
    int state;
    component_id_t id;
    component_type_t type;
    renderer_objects_t *object;
    component_feat_t features;
    component_annimation_t annimation;
    component_events_t events;
    struct s_node_components *next;
    struct s_node_components *prev;
} node_component_t;

typedef struct s_list_components {
    node_component_t *first;
    node_component_t *last;
    int len;
    stage_t id;
} list_components_t;

typedef struct s_main_components {
    list_components_t *start_menu;
    list_components_t *help_menu;
    list_components_t *load_game;
    list_components_t *game;
    list_components_t *new_game;
    list_components_t *inventory;
    list_components_t *setting;
    list_components_t *cursor;
} main_components_t;

//==================================================
// PARSING
//==================================================

typedef enum e_disabled {
    DISABLED_ANIMATION,
    QUEST_MAIN_FIRST_DIALOG,
    DISABLED_LEN
} disabled_t;

typedef enum e_nextto {
    QUEST_MAIN_FIRST_DIALOG_NEXTTO,
    QUEST_MAIN_FIRST_OBJ_DIALOG_NEXTTO,
    NEXT_TO_LEN
} next_to_t;

typedef enum e_hover {
    ACTIVE_ANIMATION,
    HOVER_LEN
} hover_t;

typedef enum e_keypressed {
    QUEST_MAIN_FIRST_DIALOG_PRESSED,
    KEYPRESSED_LEN
} keypressed_t;

typedef enum e_keyreleased {
    KEYRELEASED_LEN
} keyreleased_t;

typedef enum e_nonclicked {
    NONCLICKED_LEN
} nonclicked_t;

typedef enum e_moved {
    MOVED_LEN
} moved_t;

typedef enum e_clicked {
    MENU_LOAD_GAME,
    MENU_HELP,
    QUIT_APP,
    MENU_SETTINGS,
    MENU_OPEN_HOME,
    GAME_LUNCH,
    CHARACTER_SELECT_1,
    CHARACTER_SELECT_2,
    CHARACTER_SELECT_3,
    CLICKED_LEN
} clicked_t;

typedef struct function_s {
    clicked_t clicked;
    hover_t hover;
    moved_t moved;
    nonclicked_t nonclicked;
    keypressed_t pressed;
    keyreleased_t released;
    disabled_t disabled;
    next_to_t next_to;
} function_t;

typedef struct animation_s {
    sfIntRect rect;
    int index;
    int max;
    float speed;
} animation_t;

typedef struct parsing_s {
    char types[15];
    sfVector2f position;
    sfVector2f size;
    sfIntRect rect;
    component_type_t type;
    component_size_t c_size;
    component_styles style;
    function_t function;
    animation_t animation;
    component_id_t id;
    int radius;
    char *text;
    int text_size;
    sfVector2f text_pos;
    int text_pos_type;
} parsing_t;

/**
 * @brief Load component
 * @param app App
 * @param ressources ressources
 * @param objects objects
 * @return main_components_t
 */
main_components_t app_components_load(app_t *app, ressources_t ressources);

/**
 * @brief Free component
 * @param components main components structure
 */
void components_free(main_components_t *components);

/**
 * @brief Init pure component
 * @param size App size
 * @return node_component_t*
 */
node_component_t *component_pure_new(sfVector2u size);

/**
 * @brief Dispatch event
 * @param components
 * @param event
 * @param app
 */
void components_dispatch_event(list_components_t *components,
event_t *event, app_t *app);

void component_render_annimation(app_t *app,
node_component_t *component);

/**
 * @brief Append menu to app menu
 * @param components
 * @param event
 * @param app
 */
void append_menu(app_t *app, ressources_t ressources,
main_components_t *components);

//==================================================
// STATE
//==================================================

    #define ST_SET(component, x) (component->state | (1 << x))
    #define ST_UNSET(component, x) (component->state & (~(1 << x)))

    #define ST_DISABLED 0
    #define ST_SET_DISABLED(component, x) (\
    x ? (ST_SET(component, ST_DISABLED)) : (ST_UNSET(component, ST_DISABLED)))
    #define ST_IS_DISABLED(component) (component->state & (1 << ST_DISABLED))

    #define ST_HOVER 1
    #define ST_SET_HOVER(component, x) (\
    x ? (ST_SET(component, ST_HOVER)) : (ST_UNSET(component, ST_HOVER)))
    #define ST_IS_HOVER(component) (component->state & (1 << ST_HOVER))

    #define ST_CLICKED 2
    #define ST_SET_CLICKED(component, x) (\
    x ? (ST_SET(component, ST_CLICKED)) : (ST_UNSET(component, ST_CLICKED)))
    #define ST_IS_CLICKED(component) (component->state & (1 << ST_CLICKED))

    #define ST_PRESSED 3
    #define ST_SET_PRESSED(component, x) (\
    x ? (ST_SET(component, ST_PRESSED)) : (ST_UNSET(component, ST_PRESSED)))
    #define ST_IS_PRESSED(component) (component->state & (1 << ST_PRESSED))

    #define ST_R_CLICKED 4
    #define ST_SET_R_CLICKED(component, x) (\
    x ? (ST_SET(component, ST_R_CLICKED)) : \
(ST_UNSET(component, ST_R_CLICKED)))
    #define R_CLICKED(component) (component->state & (1 << ST_R_CLICKED))

    #define ST_MOVED 5
    #define ST_SET_MOVED(component, x) (\
    x ? (ST_SET(component, ST_MOVED)) : (ST_UNSET(component, ST_MOVED)))
    #define ST_IS_MOVED(component) (component->state & (1 << ST_MOVED))

    #define ST_NEAR 6
    #define ST_SET_NEAR(component, x) (\
    x ? (ST_SET(component, ST_NEAR)) : (ST_UNSET(component, ST_NEAR)))
    #define ST_IS_NEAR(component) (component->state & (1 << ST_NEAR))

#endif /* !COMPONENTS_H_ */
