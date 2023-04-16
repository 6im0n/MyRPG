/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** prompt
*/

#include "app/app.h"
#include "lib/tools.h"
#include "lib/str.h"

static void edit_quests_text(node_quests_t *node,
char * text, sfVector2f pos, int size)
{
    sfText_setString(node->txt, text);
    sfText_setPosition(node->txt, pos);
    sfText_setCharacterSize(node->txt, size);
}

static char *prompt_title(node_quests_t *node)
{
    char *current = node->text->detail;
    char *goal = NULL;
    int lenc = my_strlen(current);
    int leng = 0;
    char *prompt = NULL;

    if (node->finish == true)
        goal = " (Finished)";
    else
        goal = " (In progress)";
    leng = my_strlen(goal);
    prompt = malloc(sizeof(char) + lenc + leng + 1);
    if (!prompt)
        return NULL;
    my_strcpy(prompt, current);
    my_strcat(prompt, goal);
    return prompt;
}

static char *prompt_objectif(node_quests_t *node)
{
    char *current = my_char(node->current);
    char *goal = my_char(node->goal);
    int lenc = my_strlen(current);
    int leng = my_strlen(goal);
    char *prompt = malloc(sizeof(char) + lenc + leng + 4);

    if (!prompt)
        return NULL;
    my_strcpy(prompt, current);
    my_strcat(prompt, " / ");
    my_strcat(prompt, goal);
    return prompt;
}

static char *prompt_reward(node_quests_t *node)
{
    char *current = "Reward: ";
    char *goal = node->text->reward;
    int lenc = my_strlen(current);
    int leng = my_strlen(goal);
    char *prompt = malloc(sizeof(char) + lenc + leng + 1);

    if (!prompt)
        return NULL;
    my_strcpy(prompt, current);
    my_strcat(prompt, goal);
    return prompt;
}

void quests_set_text_position(app_t *app, node_quests_t *node)
{
    sfVector2f pos = sfRectangleShape_getPosition(node->shape);
    sfVector2f pos_title = { pos.x + 20, pos.y };
    sfVector2f pos_desc = { pos_title.x + 5, pos_title.y + 40 };
    sfVector2f pos_obj = { pos_desc.x, pos_title.y + 80 };
    sfVector2f pos_robj = { pos_obj.x, pos_obj.y + 10 };
    sfVector2f pos_rew = { pos_robj.x, pos_robj.y + 40 };
    sfVector2f pos_det = { pos_rew.x + 100, pos_rew.y + 30 };

    edit_quests_text(node, node->text->title, pos_title, 32);
    sfRenderWindow_drawText(app->window, node->txt, NULL);
    edit_quests_text(node, node->text->description, pos_desc, 20);
    sfRenderWindow_drawText(app->window, node->txt, NULL);
    edit_quests_text(node, node->text->objectif, pos_obj, 20);
    sfRenderWindow_drawText(app->window, node->txt, NULL);
    edit_quests_text(node, prompt_objectif(node), pos_robj, 35);
    sfRenderWindow_drawText(app->window, node->txt, NULL);
    edit_quests_text(node, prompt_reward(node), pos_rew, 20);
    sfRenderWindow_drawText(app->window, node->txt, NULL);
    edit_quests_text(node, prompt_title(node), pos_det, 20);
    sfRenderWindow_drawText(app->window, node->txt, NULL);
}
