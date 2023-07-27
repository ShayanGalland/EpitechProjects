/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/panoramix.h"

void *druid(void *arg)
{
    druid_t *d = (druid_t *)arg;

    pthread_mutex_lock(d->print_mutex);
    printf("Druid: I'm ready ... but sleepy ...\n");
    pthread_mutex_unlock(d->print_mutex);
    while (*(d->nb_refills) > 0) {
        sem_wait(d->druid_awake);
        pthread_mutex_lock(d->print_mutex);
        printf("Druid: Ah! Yes , yes , I'm awake! Working on it! Beware I ");
        printf("can only make %d more refills", *(d->nb_refills) - 1);
        printf(" after this one.\n");
        pthread_mutex_unlock(d->print_mutex);
        *d->pot_size = *d->pot_size;
        (*d->nb_refills)--;
        sem_post(d->refilled);
    }
    pthread_mutex_lock(d->print_mutex);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    pthread_mutex_unlock(d->print_mutex);
    return NULL;
}

int villager_bis(int servings_left, villager_t *v)
{

    return servings_left;
}

void *villager(void *arg)
{
    villager_t *v = (villager_t *)arg;

    pthread_mutex_lock(v->print_mutex);
    printf("Villager %d: Going into battle!\n", v->id);
    pthread_mutex_unlock(v->print_mutex);

    while (v->fights > 0) {
        sem_wait(v->pot_mutex);
        if (*v->pot_size == 0) {
            pthread_mutex_lock(v->print_mutex);
            printf("Villager %d: Hey Pano wake up! We need more potion.\n", v->id);
            pthread_mutex_unlock(v->print_mutex);
            sem_post(v->druid_awake);
            sem_wait(v->refilled);
        }
        (*v->pot_size)--;
        sem_post(v->pot_mutex);

        pthread_mutex_lock(v->print_mutex);
        printf("Villager %d: I need a drink ... I see %d servings left.\n", v->id, *v->pot_size);
        pthread_mutex_unlock(v->print_mutex);

        pthread_mutex_lock(v->print_mutex);
        printf("Villager %d: Take that roman scum! Only %d left.\n", v->id, v->fights - 1);
        pthread_mutex_unlock(v->print_mutex);
        v->fights--;
    }

    pthread_mutex_lock(v->print_mutex);
    printf("Villager %d: I'm going to sleep now.\n", v->id);
    pthread_mutex_unlock(v->print_mutex);
    return NULL;
}


int main(int argc, char *argv[])
{
    int nb_villagers = 0;
    int local_pot_size = 0;
    int nb_fights = 0;
    int local_nb_refills = 0;

    if (argc != 5)
        return 84;
    nb_villagers = atoi(argv[1]);
    local_pot_size = atoi(argv[2]);
    nb_fights = atoi(argv[3]);
    local_nb_refills = atoi(argv[4]);
    if (nb_villagers <= 0 || local_pot_size <= 0 ||
    nb_fights <= 0 || local_nb_refills <= 0)
        return 84;
    panoramix(nb_fights, nb_villagers,
    local_pot_size, local_nb_refills);
    return 0;
}