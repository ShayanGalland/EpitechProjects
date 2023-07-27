/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#include "../include/panoramix.h"

void initialize_semaphores(panoramix_data_t *data)
{
    sem_init(&data->local_pot_mutex, 0, 1);
    sem_init(&data->local_refilled, 0, 0);
    sem_init(&data->local_druid_awake, 0, 0);
}

void create_villagers_threads(panoramix_data_t *data,
pthread_t *villagers_tid, villager_t *villagers)
{
    for (int i = 0; i < data->nb_villagers; i++) {
        villagers[i].id = i;
        villagers[i].fights = data->nb_fights;
        villagers[i].pot_size = &data->local_pot_size;
        villagers[i].nb_refills = &data->local_nb_refills;
        villagers[i].pot_mutex = &data->local_pot_mutex;
        villagers[i].refilled = &data->local_refilled;
        villagers[i].druid_awake = &data->local_druid_awake;
        villagers[i].print_mutex = &data->local_print_mutex;
        pthread_create(&villagers_tid[i], NULL,
        villager, (void *)&villagers[i]);
    }
}

void destroy_semaphores(panoramix_data_t *data)
{
    sem_destroy(&data->local_pot_mutex);
    sem_destroy(&data->local_refilled);
    sem_destroy(&data->local_druid_awake);
}

panoramix_data_t init_data(int nb_fights, int nb_villagers,
int local_pot_size, int local_nb_refills)
{
    panoramix_data_t data = {
        .nb_villagers = nb_villagers,
        .nb_fights = nb_fights,
        .local_pot_size = local_pot_size,
        .local_nb_refills = local_nb_refills,
        .local_print_mutex = PTHREAD_MUTEX_INITIALIZER
    };
    return data;
}

void panoramix(int nb_fights, int nb_villagers,
int local_pot_size, int local_nb_refills)
{
    panoramix_data_t data = init_data(nb_fights, nb_villagers,
    local_pot_size, local_nb_refills);
    pthread_t druid_tid;

    initialize_semaphores(&data);
    druid_t d = {
        .pot_size = &data.local_pot_size,
        .nb_refills = &data.local_nb_refills,
        .druid_awake = &data.local_druid_awake,
        .refilled = &data.local_refilled,
        .print_mutex = &data.local_print_mutex
    };
    pthread_create(&druid_tid, NULL, druid, (void *)&d);
    pthread_t villagers_tid[data.nb_villagers];
    villager_t villagers[data.nb_villagers];
    create_villagers_threads(&data, villagers_tid, villagers);
    for (int i = 0; i < data.nb_villagers; i++)
        pthread_join(villagers_tid[i], NULL);
    pthread_join(druid_tid, NULL);
    destroy_semaphores(&data);
}
