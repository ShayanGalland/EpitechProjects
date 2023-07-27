/*
** EPITECH PROJECT, 2022
** music
** File description:
** music
*/

#include "include.h"

void create_sound(sfSound **sound, sfSoundBuffer **soundbuf, char *filename)
{
    *sound = sfSound_create();
    *soundbuf = sfSoundBuffer_createFromFile(filename);
    sfSound_setBuffer(*sound, *soundbuf);
}

void create_music(music_t *songs)
{
    songs->main = sfMusic_createFromFile("asset/music/main.ogg");
    sfMusic_setLoop(songs->main, sfTrue);
    create_sound(&songs->car, &songs->car_buf, "asset/music/car.ogg");
    create_sound(&songs->shoot, &songs->shoot_buf, "asset/music/shoot.ogg");
    sfSound_setLoop(songs->car, sfTrue);
}