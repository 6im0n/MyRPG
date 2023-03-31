/*
** EPITECH PROJECT, 2022
** my_nbrleng.c
** File description:
** Return len of a number.
*/

static int loop(int nb, int index)
{
    int ok = nb / 10;

    if (ok > 9)
        index = loop(ok, index);
    return (index + 1);
}

int my_nbrlen(int nb)
{
    int index = 0;

    if (nb < 10 && nb > -10)
        return (1);
    if (nb < 0)
        index += loop(-nb, index);
    else
        index += loop(nb, index);

    return (index + 1);
}
