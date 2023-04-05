/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** parsing
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "lib/str.h"
#include "utils/file.h"
#include "types/type.h"
#include "components/components.h"

static void clean_char(char *data, int size)
{
    for (int i = 0; i < size; i++) {
        data[i] = '\0';
    }
}

void get_position(char *nb, parsing_t *element, app_t *app)
{
    int number = 0;

    number = my_strtoint(nb);
    if (nb[0] == '.') {
        if (element->position.x == -1)
            element->position.x = sfRenderWindow_getSize(app->window).x * (number / 100.0);
        else
            element->position.y = sfRenderWindow_getSize(app->window).y * (number / 100.0);
    } else {
        if (element->position.x == -1)
            element->position.x = number;
        else
            element->position.y = number;
    }
}

void get_size(char *nb, parsing_t *element, app_t *app)
{
    int number = 0;

    number = my_strtoint(nb);
    if (nb[0] == '.') {
        if (element->size.x == -1)
            element->size.x = sfRenderWindow_getSize(app->window).x * (number / 100.0);
        else
            element->size.y = sfRenderWindow_getSize(app->window).y * (number / 100.0);
    } else {
        if (element->size.x == -1)
            element->size.x = number;
        else
            element->size.y = number;
    }
}

void get_rect(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->rect.left == -1) {
        element->rect.left = number;
        return;
    }
    if (element->rect.top == -1) {
        element->rect.top = number;
        return;
    }
    if (element->rect.width == -1) {
        element->rect.width = number;
        return;
    }
    if (element->rect.height == -1) {
        element->rect.height = number;
        return;
    }
}

void get_style(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->style.texture == TX_LEN) {
        element->style.texture = number;
        return;
    }
    if (element->style.sound == SD_LEN) {
        element->style.sound = number;
        return;
    }
    if (element->style.font == FT_LEN) {
        element->style.font = number;
        return;
    }
}

void get_type(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->type == C_TYPES_LEN) {
        element->type = number;
        return;
    }
}

void get_c_size(char *nb, parsing_t *element)
{
    int number = 0;

    number = my_strtoint(nb);
    if (element->c_size == C_SIZE_LEN) {
        element->c_size = number;
        return;
    }
}

static void manage_data(char *nb, parsing_t *element, app_t *app)
{
    if (my_strcmp(element->types, "position") == 0)
        get_position(nb, element, app);
    if (my_strcmp(element->types, "size") == 0)
        get_size(nb, element, app);
    if (my_strcmp(element->types, "rect") == 0)
        get_rect(nb, element);
    if (my_strcmp(element->types, "style") == 0)
        get_style(nb, element);
    if (my_strcmp(element->types, "type") == 0)
        get_type(nb, element);
    if (my_strcmp(element->types, "c_size") == 0)
        get_c_size(nb, element);
}


void manage_number(char *file, parsing_t *element, app_t *app, int *index)
{
    char nb[6];
    int nb_index = 0;

    clean_char(nb, 6);
    *index += 1;
    do {
        *index += 1;
        if (file[*index] == ' ' || file[*index] == '\n') {
            manage_data(nb, element, app);
            clean_char(nb, 6);
            nb_index = 0;
        } else {
            nb[nb_index] = file[*index];
            nb_index++;
        }
    } while (file[*index] != '\n');
}

void display_parsing(parsing_t *elements)
{
    printf("Position: %f | %f\n", elements->position.x, elements->position.y);
    printf("Size: %f | %f\n", elements->size.x, elements->size.y);
    printf("style: %d | %d | %d\n", elements->style.texture, elements->style.sound, elements->style.font);
    printf("Rect: %f | %f | %f | %f\n", elements->rect.left, elements->rect.top, elements->rect.width, elements->rect.height);
    printf("Type: %d\n", elements->type);
    printf("c_size: %d\n", elements->c_size);
}

void parsing_buttons(app_t *app, ressources_t ressources,
                    list_components_t *list, char *filepath)
{
    parsing_t element = {{'\0'}, {-1, -1}, {-1, -1}, {-1, -1, -1, -1}, C_TYPES_LEN, C_SIZE_LEN,
                        {TX_LEN, SD_LEN, FT_LEN}};
    (void) ressources;
    (void) list;
    char *file = file_load(filepath);
    int type_index = 0;
    int index = 0;

    clean_char(element.types, 15);
    while (file[index] != '\0') {
        if (file[index] == ':') {
            manage_number(file, &element, app, &index);
            type_index = 0;
            clean_char(element.types, 15);
        } else {
            element.types[type_index] = file[index];
            type_index++;
        }
        index++;
    }
    display_parsing(&element);
}
