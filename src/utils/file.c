/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

static int file_size(char *filepath)
{
    char buffer[1024];
    int readed = 0;
    size_t total = 0;
    FILE *fp = fopen(filepath, "r");

    while (fgets(buffer, sizeof(buffer), fp))
    {
        readed = strlen(buffer);
        total += readed;
    }
    fclose(fp);
    return total;
}

char *file_load(char *filepath)
{
    FILE *fp = fopen(filepath, "r");
    char buffer[1024];
    int size = file_size(filepath);
    char *file = malloc(sizeof(char) * (size + 1));
    int file_index = 0;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        int read = strlen(buffer);
        for (int i = 0; i < read; i++)
        {
            file[file_index] = buffer[i];
            file_index++;
        }
    }
    fclose(fp);
    file[file_index] = '\0';
    return file;
}
