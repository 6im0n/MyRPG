/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** resume
*/

#include "event/global.h"
#include "components/components.h"
#include "lib/output.h"
#include "app/constants.h"
#include <fcntl.h>
#include <stdio.h>
#include "lib/str.h"
#include "lib/tools.h"

static void display_data(FILE *fd, char *prefix, char *data)
{
    int len_prefix = my_strlen(prefix);
    int len_data = my_strlen(data);
    int len = len_prefix + len_data + 3;
    char *prompt = malloc(sizeof(char) + len);

    my_strcpy(prompt, prefix);
    my_strcat(prompt, ": ");
    my_strcat(prompt, data);
    my_strcat(prompt, "\n");
    fwrite(prompt , 1 , len , fd );
}

static void save_skills(FILE *fd, skills_t skills, experience_t exp)
{
    char *speed = my_char(skills.speed);
    char *strength = my_char(skills.strength);
    char *resitance = my_char(skills.resitance);
    char *level = my_char(exp.level);
    char *xp = my_char(exp.xp);

    display_data(fd, "Level", level);
    display_data(fd, "Xp", xp);
    display_data(fd, "Speed", speed);
    display_data(fd, "Strength", strength);
    display_data(fd, "Resitance", resitance);
}

void app_save_game(app_t *app)
{
    FILE *fd = fopen(SAVE_FILE, "w");
    player_t *player = app->element->player;

    if (!fd)
        return;
    save_skills(fd, player->skills, player->exprerience);
    fclose(fd);
    (void) app;
}

void launch_game_resume(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (component->features.select == false)
        return;
    event_play_music(component, app);
    app->state->back = app->state->stage;
    app->state->stage = S_GAME;
}

void resume_available(node_component_t *component,
event_t *event, app_t *app)
{
    int fd = open(SAVE_FILE, O_RDONLY);
    sfColor color = {0, 0, 0, 100};

    (void) event;
    (void) app;
    if (fd == -1) {
        component->features.select = false;
        sfText_setColor(component->object->text, color);
        return;
    }
    close(fd);
    component->features.select = true;
    sfText_setColor(component->object->text, sfBlack);
}
