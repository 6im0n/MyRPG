/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** save
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

static void display_duo_data(FILE *fd, char *prefix,
char *data_x, char *data_y)
{
    int len_prefix = my_strlen(prefix);
    int len_data_x = my_strlen(data_x);
    int len_data_y = my_strlen(data_y);
    int len = len_prefix + len_data_x + len_data_y + 4;
    char *prompt = malloc(sizeof(char) + len);

    my_strcpy(prompt, prefix);
    my_strcat(prompt, ": ");
    my_strcat(prompt, data_x);
    my_strcat(prompt, " ");
    my_strcat(prompt, data_y);
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

static void save_shape(FILE *fd, player_t *player)
{
    sfVector2f pos = sfRectangleShape_getPosition(player->character->shape);
    char *data_x = my_char(pos.x);
    char *data_y = my_char(pos.y);
    char *texture_player = my_char(player->character->tx);

    display_duo_data(fd, "Position", data_x, data_y);
    display_data(fd, "Texture_player", texture_player);
}

void app_save_game(app_t *app)
{
    FILE *fd = fopen(SAVE_FILE, "w");
    player_t *player = app->element->player;

    if (!fd)
        return;
    save_shape(fd, player);
    save_skills(fd, player->skills, player->exprerience);
    fclose(fd);
    (void) app;
}
