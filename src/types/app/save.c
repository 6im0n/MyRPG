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
#include "parsing/utils.h"

static void display_data(FILE *fd, char *prefix, char *data)
{
    int len_prefix = my_strlen(prefix);
    int len_data = my_strlen(data);
    int len = len_prefix + len_data + 3;
    char *prompt = malloc(sizeof(char) * (len + 1));

    clean_char(prompt, len + 1);
    if (!prompt)
        return;
    my_strcpy(prompt, prefix);
    my_strcat(prompt, ": ");
    my_strcat(prompt, data);
    my_strcat(prompt, "\n");
    fwrite(prompt , 1 , len , fd );
    free(prompt);
}

static void display_duo_data(FILE *fd, char *prefix,
char *data_x, char *data_y)
{
    int len_prefix = my_strlen(prefix);
    int len_data_x = my_strlen(data_x);
    int len_data_y = my_strlen(data_y);
    int len = len_prefix + len_data_x + len_data_y + 4;
    char *prompt = malloc(sizeof(char) * (len + 1));

    if (!prompt)
        return;
    my_strcpy(prompt, prefix);
    my_strcat(prompt, ": ");
    my_strcat(prompt, data_x);
    my_strcat(prompt, " ");
    my_strcat(prompt, data_y);
    my_strcat(prompt, "\n");
    fwrite(prompt , 1 , len , fd );
    free(prompt);
}

static void add_item_display(node_item_t *tmp,
char *str, char *prompt, int *len)
{
    char *dup = my_strdup(prompt);

    str = my_char(tmp->item);
    *len += my_strlen(str);
    free(prompt);
    prompt = malloc(sizeof(char) * ((*len) + 3));
    if (!prompt)
        return;
    clean_char(prompt, *len + 3);
    my_strcpy(prompt, dup);
    my_strcat(prompt, str);
    if (tmp->next != NULL) {
        my_strcat(prompt, " ");
        *len += 1;
    }
    free(str);
    free(dup);
}

static void display_inventory(FILE *fd, list_item_t *inventory)
{
    node_item_t *tmp = inventory->first;
    node_item_t *tmp2 = tmp;
    int len = my_strlen("Inventory: ") + 1;
    char *prompt = malloc(sizeof(char) * (len + 2));
    char *str = NULL;

    if (!prompt)
        return;
    clean_char(prompt, len + 2);
    my_strcpy(prompt, "Inventory: ");
    printf("%s\n", prompt);
    while (tmp != NULL) {
        tmp2 = tmp->next;
        add_item_display(tmp, str, prompt, &len);
        tmp = tmp2;
    }
    my_strcat(prompt, "\n");
    fwrite(prompt , 1 , len , fd );
}

static void add_quest_display(node_quests_t *tmp,
char *str, char *prompt, int *len)
{
    char *dup = my_strdup(prompt);
    char *current = my_char(tmp->current);

    str = my_char(tmp->id);
    *len += my_strlen(str);
    *len += my_strlen(current) + 1;
    free(prompt);
    prompt = malloc(sizeof(char) * ((*len) + 1));
    if (!prompt)
        return;
    clean_char(prompt, *len + 1);
    my_strcpy(prompt, dup);
    my_strcat(prompt, str);
    my_strcat(prompt, "|");
    my_strcat(prompt, current);
    if (tmp->next != NULL) {
        my_strcat(prompt, " ");
        *len += 1;
    }
    free(current);
    free(str);
    free(dup);
}

static void display_quest(FILE *fd, list_quests_t *quests)
{
    node_quests_t *tmp = quests->first;
    node_quests_t *tmp2 = tmp;
    int len = my_strlen("Quests: ") + 1;
    char *prompt = malloc(sizeof(char) * (len + 1));
    char *str = NULL;

    if (!prompt)
        return;
    clean_char(prompt, len + 1);
    my_strcpy(prompt, "Quests: ");
    while (tmp != NULL) {
        tmp2 = tmp->next;
        add_quest_display(tmp, str, prompt, &len);
        printf("%d\n", tmp->id);
        tmp = tmp2;
    }
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
    free(speed);
    free(strength);
    free(resitance);
    free(level);
    free(xp);
}

static void save_shape(FILE *fd, player_t *player)
{
    sfVector2f pos = sfRectangleShape_getPosition(player->character->shape);
    char *data_x = my_char(pos.x);
    char *data_y = my_char(pos.y);
    char *texture_player = my_char(player->character->tx);

    display_duo_data(fd, "Position", data_x, data_y);
    display_data(fd, "Texture_player", texture_player);
    display_inventory(fd, player->inventory);
    free(data_x);
    free(data_y);
    free(texture_player);
}

void app_save_game(app_t *app)
{
    FILE *fd = fopen(SAVE_FILE, "w");
    player_t *player = app->element->player;

    if (!fd)
        return;
    save_shape(fd, player);
    save_skills(fd, player->skills, player->exprerience);
    display_quest(fd, app->element->quests);
    fclose(fd);
    (void) app;
}
