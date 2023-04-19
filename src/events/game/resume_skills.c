/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** resume_skills
*/

#include "components/components.h"
#include "components/player.h"
#include "lib/tools.h"
#include "lib/str.h"

static void get_inventory(app_t *app, char *str)
{
    int i = 9 + 2;
    int type = 0;

    while (str[i - 1] != '\0') {
        type = my_int(str + i);
        add_item_player(app, type);
        i += my_nbrlen(type);
        i++;
    }
}

static void get_quest(app_t *app, char *str)
{
    int i = 5 + 2;
    int type = 0;

    if (my_strlen(str) <= 9)
        return;
    while (str[i - 1] != '\0') {
        type = my_int(str + i);
        quest_append(app, type);
        i += my_nbrlen(type);
        i++;
        type = my_int(str + i);
        app->element->quests->last->current = type;
        i += my_nbrlen(type);
        i++;
    }
}

void get_skills(app_t *app, char *str)
{
    player_t *player = app->element->player;
    int level = my_strlen("Level");
    int speed = my_strlen("Speed");
    int strength = my_strlen("Strength");
    int resitance = my_strlen("Resitance");

    if (my_strncmp("Level", str, level) == 0)
        player->exprerience.level = my_int(str + level + 2);
    if (my_strncmp("Xp", str, 2) == 0)
        player->exprerience.update = my_int(str + 2 + 2);
    if (my_strncmp("Speed", str, speed) == 0)
        player->skills.speed = my_int(str + speed + 2);
    if (my_strncmp("Strength", str, strength) == 0)
        player->skills.strength = my_int(str + strength + 2);
    if (my_strncmp("Resitance", str, resitance) == 0)
        player->skills.resitance = my_int(str + resitance + 2);
    if (my_strncmp("Quest", str, 5) == 0)
        get_quest(app, str);
    if (my_strncmp("Inventory", str, 9) == 0)
        get_inventory(app, str);
}
