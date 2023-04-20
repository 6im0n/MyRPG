/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** clear_game
*/

#include "app/app.h"
#include "types/type.h"
#include "components/components.h"
#include "types/list.h"

void clear_old_game(app_t *app)
{
    app->element->player->exprerience.level = 0;
    app->element->player->exprerience.max_xp = 0;
    app->element->player->exprerience.xp = 0;
    app->element->player->exprerience.update = 0;
    app->element->player->skills.resitance = 0;
    app->element->player->skills.speed = 20;
    app->element->player->skills.strength = 0;
    list_item_free(app->element->player->inventory);
    app->element->player->inventory = list_item_init();
    add_item_player(app, I_NONE);
    list_quests_free(app->element->quests);
    app->element->quests = list_quests_init();
}
