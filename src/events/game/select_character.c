/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** select_character
*/

#include "event/global.h"
#include "components/components.h"
#include "ressources/loaders/textures.h"

static void edit_texture_character(app_t *app, texture_t tx)
{
    sfTexture *texture = sfTexture_createFromFile(textures_loaders[tx], NULL);

    sfRectangleShape_setTexture(app->element->player->character->shape,
        texture, sfFalse);
}

static void edit_capacity_character(player_t *player,
int speed, int strength, int resitance)
{
    player->skills.speed = speed;
    player->skills.strength = strength;
    player->skills.resitance = resitance;
}

void event_character1_select_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    edit_texture_character(app, TX_PLAYER_1);
    edit_capacity_character(app->element->player, 12, 10, 8);
    component->features.select = true;
    component->next->next->features.select = false;
    component->next->next->next->next->features.select = false;
}

void event_character2_select_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    edit_texture_character(app, TX_PLAYER_2);
    edit_capacity_character(app->element->player, 8, 10, 12);
    component->prev->prev->features.select = false;
    component->features.select = true;
    component->next->next->features.select = false;
}

void event_character3_select_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    edit_texture_character(app, TX_PLAYER_3);
    edit_capacity_character(app->element->player, 10, 12, 10);
    component->prev->prev->prev->prev->features.select = false;
    component->prev->prev->features.select = false;
    component->features.select = true;
}
