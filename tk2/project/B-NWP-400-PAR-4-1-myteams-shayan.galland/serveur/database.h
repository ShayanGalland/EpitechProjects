#ifndef _DATABASE_H
#define _DATABASE_H

#include "time.h"

typedef struct database database_t;

typedef struct team team_t;
typedef struct user user_t;

typedef struct channel channel_t;
typedef struct thread thread_t;
typedef struct reply reply_t;

typedef struct private_message private_message_t;

struct database
{
    user_t **users;
    team_t **teams;
    channel_t **channels;
    thread_t **threads;
    reply_t **replies;
    private_message_t **private_messages;
};

struct user
{
    char *uuid;
    char *username;

    char **teams;

    int status;
};

struct team
{
    char *uuid;
    char *name;
    char *description;
};

struct channel
{
    char *uuid;
    char *name;
    char *description;

    char *team_uuid;
};

struct thread
{
    char *uuid;
    char *title;
    char *body;
    time_t timestamp;

    char *channel_uuid;
    char *user_uuid;
};

struct reply
{
    char *body;
    char *thread_uuid;
    char *user_uuid;
    time_t timestamp;
};

struct private_message
{
    char *sender_uuid;
    char *receiver_uuid;
    char *message;
    time_t timestamp;
};

database_t *create_database();
void load_database(database_t *database);
void save_database(database_t *database);

char *my_generate_uuid();
int count_null_array(void **array);

user_t *create_user(database_t *database, char *username);
user_t *find_user(database_t *database, char *uuid_or_username);
int is_subscribed(database_t *database, char *user_uuid, char *team_uuid);
void add_subscribed_team_to_user(database_t *database, char *user_uuid, char *team_uuid);
void remove_subscribed_team_to_user(database_t *database, char *user_uuid, char *team_uuid);

team_t *create_team(database_t *database, char *name, char *description);
team_t *find_team(database_t *database, char *uuid);
team_t *find_team_by_name(database_t *database, char *name);

channel_t *create_channel(database_t *database, team_t *team, char *name, char *description);
channel_t *find_channel(database_t *database, char *uuid);
channel_t *find_channel_by_name(database_t *database, char *name);

thread_t *create_thread(database_t *database, char *user_uuid, channel_t *channel, char *title, char *body);
thread_t *find_thread(database_t *database, char *uuid);
thread_t *find_thread_by_title(database_t *database, char *title);

reply_t *create_reply(database_t *database, char *user_uuid, thread_t *thread, char *body);

private_message_t *create_private_message(database_t *database, char *sender_uuid, char *receiver_uuid, char *message);

#endif