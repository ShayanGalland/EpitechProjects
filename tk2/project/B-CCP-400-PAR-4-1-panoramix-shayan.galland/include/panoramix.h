/*
** EPITECH PROJECT, 2023
** project
** File description:
** in c
*/

#ifndef PANORAMIX_H_
#define PANORAMIX_H_
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

typedef struct {
    int id;
    int fights;
    int *pot_size;
    int *nb_refills;
    sem_t *pot_mutex;
    sem_t *refilled;
    sem_t *druid_awake;
    pthread_mutex_t *print_mutex;
} villager_t;

typedef struct {
    int *pot_size;
    int *nb_refills;
    sem_t *druid_awake;
    sem_t *refilled;
    pthread_mutex_t *print_mutex;
} druid_t;

typedef struct {
    int nb_villagers;
    int nb_fights;
    int local_pot_size;
    int local_nb_refills;
    pthread_mutex_t local_print_mutex;
    sem_t local_pot_mutex;
    sem_t local_refilled;
    sem_t local_druid_awake;
} panoramix_data_t;

void *druid(void *arg);
void *villager(void *arg);
void panoramix(int nb_fights, int nb_villagers,
int local_pot_size, int local_nb_refills);

#endif