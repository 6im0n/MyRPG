/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

static int file_size(char *filepath)
{
    char * line = NULL;
    int readed = 0;
    size_t total = 0;
    size_t len = 0;
    FILE *fp = fopen(filepath, "r");

    while ((readed = getline(&line, &len, fp)) != -1)
        total += readed;
    fclose(fp);
    return (total);
}

char *file_load(char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    int size = file_size(filepath);
    char *file = malloc(sizeof(char) * (size + 1));
    int file_index = 0;
    size_t len = 0;
    int read = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        for (int i = 0 ; i < read ; i++) {
            file[file_index] = line[i];
            file_index++;
        }
    }
    fclose(fp);
    file[file_index] = '\0';
    return file;
}
