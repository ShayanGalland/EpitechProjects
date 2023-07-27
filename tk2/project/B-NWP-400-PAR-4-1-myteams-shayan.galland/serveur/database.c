#include "database.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <uuid/uuid.h>

#include "network.h"

database_t *create_database()
{
    database_t *database = malloc(sizeof(database_t));

    database->users = malloc(sizeof(user_t *));
    database->users[0] = NULL;

    database->teams = malloc(sizeof(team_t *));
    database->teams[0] = NULL;

    database->channels = malloc(sizeof(channel_t *));
    database->channels[0] = NULL;

    database->threads = malloc(sizeof(thread_t *));
    database->threads[0] = NULL;

    database->replies = malloc(sizeof(reply_t *));
    database->replies[0] = NULL;

    database->private_messages = malloc(sizeof(private_message_t *));
    database->private_messages[0] = NULL;

    return database;
}
void load_database(database_t *database)
{
    FILE *fptr = fopen("database.bin", "rb+");
    if (fptr == NULL)
        return;

    fseek(fptr, 0, SEEK_END);
    int file_len = ftell(fptr);
    rewind(fptr);

    char *read_buffer = malloc(sizeof(char) * file_len);
    fread(read_buffer, sizeof(char), file_len, fptr);
    int read_offset = 0;

    int users_count = read_uint32(read_buffer, &read_offset);
    int teams_count = read_uint32(read_buffer, &read_offset);
    int channels_count = read_uint32(read_buffer, &read_offset);
    int threads_count = read_uint32(read_buffer, &read_offset);
    int replies_count = read_uint32(read_buffer, &read_offset);
    int private_messages_count = read_uint32(read_buffer, &read_offset);

    for (int i = 0; i < users_count; i++)
    {
        user_t *new_user = malloc(sizeof(user_t));
        new_user->uuid = read_string(read_buffer, &read_offset);
        new_user->username = read_string(read_buffer, &read_offset);
        new_user->teams = malloc(sizeof(team_t *));
        new_user->teams[0] = NULL;
        new_user->status = 0;

        add_user(database, new_user);

        int teams_subscribed_count = read_uint32(read_buffer, &read_offset);
        for (int j = 0; j < teams_subscribed_count; j++)
        {
            char *teams_subscribed_uuid = read_string(read_buffer, &read_offset);
            add_subscribed_team_to_user(database, new_user->uuid, teams_subscribed_uuid);
        }

        server_event_user_loaded(new_user->uuid, new_user->username);
        read_offset++;
    }

    for (int i = 0; i < teams_count; i++)
    {
        team_t *new_team = malloc(sizeof(team_t));
        new_team->uuid = read_string(read_buffer, &read_offset);
        new_team->name = read_string(read_buffer, &read_offset);
        new_team->description = read_string(read_buffer, &read_offset);

        add_team(database, new_team);
        printf("Team loaded: %s (%s) %s\n", new_team->name, new_team->uuid, new_team->description);
        read_offset++;
    }

    for (int i = 0; i < channels_count; i++)
    {
        channel_t *new_channel = malloc(sizeof(channel_t));
        new_channel->uuid = read_string(read_buffer, &read_offset);
        new_channel->name = read_string(read_buffer, &read_offset);
        new_channel->description = read_string(read_buffer, &read_offset);
        new_channel->team_uuid = read_string(read_buffer, &read_offset);

        add_channel(database, new_channel);
        printf("Channel loaded: %s (%s) %s\n", new_channel->name, new_channel->uuid, new_channel->description);
        read_offset++;
    }

    for (int i = 0; i < threads_count; i++)
    {
        thread_t *new_thread = malloc(sizeof(thread_t));

        new_thread->uuid = read_string(read_buffer, &read_offset);
        new_thread->title = read_string(read_buffer, &read_offset);
        new_thread->user_uuid = read_string(read_buffer, &read_offset);
        new_thread->channel_uuid = read_string(read_buffer, &read_offset);
        new_thread->body = read_string(read_buffer, &read_offset);
        new_thread->timestamp = read_uint64(read_buffer, &read_offset);

        add_thread(database, new_thread);
        printf("Thread loaded: %s (%s) %s %s %s %d\n", new_thread->title, new_thread->uuid, new_thread->body, new_thread->user_uuid, new_thread->channel_uuid, new_thread->timestamp);
        read_offset++;
    }

    for (int i = 0; i < replies_count; i++)
    {
        reply_t *new_reply = malloc(sizeof(reply_t));

        new_reply->user_uuid = read_string(read_buffer, &read_offset);
        new_reply->thread_uuid = read_string(read_buffer, &read_offset);
        new_reply->body = read_string(read_buffer, &read_offset);
        new_reply->timestamp = read_uint64(read_buffer, &read_offset);

        add_reply(database, new_reply);
        printf("Reply loaded: %s (%s) %s %d\n", new_reply->user_uuid, new_reply->thread_uuid, new_reply->body, new_reply->timestamp);
        read_offset++;
    }

    for (int i = 0; i < private_messages_count; i++)
    {
        private_message_t *new_private_message = malloc(sizeof(private_message_t));

        new_private_message->sender_uuid = read_string(read_buffer, &read_offset);
        new_private_message->receiver_uuid = read_string(read_buffer, &read_offset);
        new_private_message->message = read_string(read_buffer, &read_offset);
        new_private_message->timestamp = read_uint64(read_buffer, &read_offset);

        add_private_message(database, new_private_message);
        printf("Private message loaded: %s (%s) %s %d\n", new_private_message->sender_uuid, new_private_message->receiver_uuid, new_private_message->message, new_private_message->timestamp);
        read_offset++;
    }

    free(read_buffer);
    fclose(fptr);
}
void save_database(database_t *database)
{
    FILE *fptr = fopen("database.bin", "wb+");

    int users_count = count_null_array(database->users) - 1;
    int teams_count = count_null_array(database->teams) - 1;
    int channels_count = count_null_array(database->channels) - 1;
    int threads_count = count_null_array(database->threads) - 1;
    int replies_count = count_null_array(database->replies) - 1;
    int private_messages_count = count_null_array(database->private_messages) - 1;

    char write_buffer[MAX_PACKET_SIZE];
    memset(write_buffer, 0, MAX_PACKET_SIZE);
    uint16_t write_offet = 0;

    write_uint32(write_buffer, &write_offet, users_count);
    write_uint32(write_buffer, &write_offet, teams_count);
    write_uint32(write_buffer, &write_offet, channels_count);
    write_uint32(write_buffer, &write_offet, threads_count);
    write_uint32(write_buffer, &write_offet, replies_count);
    write_uint32(write_buffer, &write_offet, private_messages_count);

    fwrite(write_buffer, sizeof(char), write_offet, fptr);

    for (int i = 0; i < users_count; i++)
    {
        memset(write_buffer, 0, MAX_PACKET_SIZE);
        write_offet = 0;
        user_t *user = database->users[i];

        write_string(write_buffer, &write_offet, user->uuid);
        write_string(write_buffer, &write_offet, user->username);

        int teams_subscribed_count = count_null_array(user->teams) - 1;
        write_uint32(write_buffer, &write_offet, teams_subscribed_count);

        for (int j = 0; j < teams_subscribed_count; j++)
        {
            write_string(write_buffer, &write_offet, user->teams[j]);
        }

        fwrite(write_buffer, sizeof(char), write_offet + 1, fptr);
    }

    for (int i = 0; i < teams_count; i++)
    {
        memset(write_buffer, 0, MAX_PACKET_SIZE);
        write_offet = 0;
        team_t *team = database->teams[i];

        write_string(write_buffer, &write_offet, team->uuid);
        write_string(write_buffer, &write_offet, team->name);
        write_string(write_buffer, &write_offet, team->description);

        fwrite(write_buffer, sizeof(char), write_offet + 1, fptr);
    }

    for (int i = 0; i < channels_count; i++)
    {
        memset(write_buffer, 0, MAX_PACKET_SIZE);
        write_offet = 0;
        channel_t *channel = database->channels[i];

        write_string(write_buffer, &write_offet, channel->uuid);
        write_string(write_buffer, &write_offet, channel->name);
        write_string(write_buffer, &write_offet, channel->description);
        write_string(write_buffer, &write_offet, channel->team_uuid);

        fwrite(write_buffer, sizeof(char), write_offet + 1, fptr);
    }

    for (int i = 0; i < threads_count; i++)
    {
        memset(write_buffer, 0, MAX_PACKET_SIZE);
        write_offet = 0;
        thread_t *thread = database->threads[i];

        write_string(write_buffer, &write_offet, thread->uuid);
        write_string(write_buffer, &write_offet, thread->title);
        write_string(write_buffer, &write_offet, thread->user_uuid);
        write_string(write_buffer, &write_offet, thread->channel_uuid);
        write_string(write_buffer, &write_offet, thread->body);
        write_uint64(write_buffer, &write_offet, thread->timestamp);

        fwrite(write_buffer, sizeof(char), write_offet + 1, fptr);
    }

    for (int i = 0; i < replies_count; i++)
    {
        memset(write_buffer, 0, MAX_PACKET_SIZE);
        write_offet = 0;

        reply_t *reply = database->replies[i];

        write_string(write_buffer, &write_offet, reply->user_uuid);
        write_string(write_buffer, &write_offet, reply->thread_uuid);
        write_string(write_buffer, &write_offet, reply->body);
        write_uint64(write_buffer, &write_offet, reply->timestamp);

        fwrite(write_buffer, sizeof(char), write_offet + 1, fptr);
    }

    for (int i = 0; i < private_messages_count; i++)
    {
        memset(write_buffer, 0, MAX_PACKET_SIZE);
        write_offet = 0;

        private_message_t *private_message = database->private_messages[i];

        write_string(write_buffer, &write_offet, private_message->sender_uuid);
        write_string(write_buffer, &write_offet, private_message->receiver_uuid);
        write_string(write_buffer, &write_offet, private_message->message);
        write_uint64(write_buffer, &write_offet, private_message->timestamp);

        fwrite(write_buffer, sizeof(char), write_offet + 1, fptr);
    }

    fclose(fptr);
}

char *my_generate_uuid()
{
    uuid_t out;
    char *uuid = malloc(sizeof(char) * 37);

    uuid_generate(out);
    uuid_unparse(out, uuid);
    return uuid;
}
int count_null_array(void **array)
{
    for (int i = 0;; i++)
    {
        if (array[i] == NULL)
            return i + 1;
    }
}

user_t *create_user(database_t *database, char *username)
{
    user_t *new_user = malloc(sizeof(user_t));

    new_user->username = strdup(username);

    new_user->teams = malloc(sizeof(team_t *));
    new_user->teams[0] = NULL;

    new_user->uuid = my_generate_uuid();

    add_user(database, new_user);

    return new_user;
}

team_t *create_team(database_t *database, char *name, char *description)
{
    team_t *new_team = malloc(sizeof(team_t));

    new_team->name = strdup(name);

    new_team->description = strdup(description);

    new_team->uuid = my_generate_uuid();

    add_team(database, new_team);

    return new_team;
}

channel_t *create_channel(database_t *database, team_t *team, char *name, char *description)
{
    channel_t *new_channel = malloc(sizeof(channel_t));

    new_channel->name = strdup(name);
    new_channel->description = strdup(description);
    new_channel->team_uuid = strdup(team->uuid);

    new_channel->uuid = my_generate_uuid();

    add_channel(database, new_channel);

    return new_channel;
}

thread_t *create_thread(database_t *database, char *user_uuid, channel_t *channel, char *title, char *body)
{
    thread_t *new_thread = malloc(sizeof(thread_t));

    new_thread->title = strdup(title);
    new_thread->body = strdup(body);
    new_thread->channel_uuid = strdup(channel->uuid);
    new_thread->user_uuid = strdup(user_uuid);

    new_thread->uuid = my_generate_uuid();

    add_thread(database, new_thread);

    return new_thread;
}

reply_t *create_reply(database_t *database, char *user_uuid, thread_t *thread, char *body)
{
    reply_t *new_reply = malloc(sizeof(reply_t));

    new_reply->body = strdup(body);
    new_reply->thread_uuid = strdup(thread->uuid);
    new_reply->user_uuid = strdup(user_uuid);

    add_reply(database, new_reply);

    return new_reply;
}

private_message_t *create_private_message(database_t *database, char *sender_uuid, char *receiver_uuid, char *message)
{
    private_message_t *private_message = malloc(sizeof(private_message_t));

    private_message->sender_uuid = strdup(sender_uuid);
    private_message->receiver_uuid = strdup(receiver_uuid);
    private_message->message = strdup(message);
    private_message->timestamp = time(NULL);

    add_private_message(database, private_message);

    return private_message;
}

void add_user(database_t *database, user_t *new_user)
{
    int users_count = count_null_array(database->users) - 1;
    database->users = realloc(database->users, sizeof(user_t *) * (users_count + 2));

    database->users[users_count] = new_user;
    database->users[users_count + 1] = NULL;
}
user_t *find_user(database_t *database, char *uuid_or_username)
{
    int users_count = count_null_array(database->users) - 1;
    for (int i = 0; i < users_count; i++)
    {
        if (strcmp(uuid_or_username, database->users[i]->uuid) == 0)
            return database->users[i];

        if (strcmp(uuid_or_username, database->users[i]->username) == 0)
            return database->users[i];
    }

    return NULL;
}
int is_subscribed(database_t *database, char *user_uuid, char *team_uuid)
{
    int is_subscribed = 0;

    user_t *user = find_user(database, user_uuid);
    int subscribed_teams_count = count_null_array(user->teams);
    for (int i = 0; i < subscribed_teams_count; i++)
    {
        if (user->teams[i] != NULL && strcmp(team_uuid, user->teams[i]) == 0)
        {
            is_subscribed = 1;
            break;
        }
    }

    return is_subscribed;
}
void add_subscribed_team_to_user(database_t *database, char *user_uuid, char *team_uuid)
{
    user_t *user = find_user(database, user_uuid);
    int subscribed_teams_count = count_null_array(user->teams) - 1;
    user->teams = realloc(user->teams, sizeof(team_t *) * (subscribed_teams_count + 2));

    user->teams[subscribed_teams_count] = strdup(team_uuid);
    user->teams[subscribed_teams_count + 1] = NULL;
}
void remove_subscribed_team_to_user(database_t *database, char *user_uuid, char *team_uuid)
{
    user_t *user = find_user(database, user_uuid);
    int subscribed_teams_count = count_null_array(user->teams) - 1;

    for (int i = 0; i < subscribed_teams_count; i++)
    {
        if (strcmp(team_uuid, user->teams[i]) == 0)
        {
            free(user->teams[i]);
            user->teams[i] = "DELETED";
        }
    }
}

void add_private_message(database_t *database, private_message_t *new_private_message)
{
    int private_messages_count = count_null_array(database->private_messages) - 1;
    database->private_messages = realloc(database->private_messages, sizeof(private_message_t *) * (private_messages_count + 2));

    database->private_messages[private_messages_count] = new_private_message;
    database->private_messages[private_messages_count + 1] = NULL;
}

void add_team(database_t *database, team_t *new_team)
{
    int teams_count = count_null_array(database->teams) - 1;
    database->teams = realloc(database->teams, sizeof(team_t *) * (teams_count + 2));

    database->teams[teams_count] = new_team;
    database->teams[teams_count + 1] = NULL;
}
team_t *find_team(database_t *database, char *uuid)
{
    int teams_count = count_null_array(database->teams) - 1;
    for (int i = 0; i < teams_count; i++)
    {
        if (strcmp(uuid, database->teams[i]->uuid) == 0)
            return database->teams[i];
    }

    return NULL;
}
team_t *find_team_by_name(database_t *database, char *name)
{
    int teams_count = count_null_array(database->teams) - 1;
    for (int i = 0; i < teams_count; i++)
    {
        if (strcmp(name, database->teams[i]->name) == 0)
            return database->teams[i];
    }

    return NULL;
}

void add_channel(database_t *database, channel_t *new_channel)
{
    int channels_count = count_null_array(database->channels) - 1;
    database->channels = realloc(database->channels, sizeof(channel_t *) * (channels_count + 2));

    database->channels[channels_count] = new_channel;
    database->channels[channels_count + 1] = NULL;
}
channel_t *find_channel(database_t *database, char *uuid)
{
    int channels_count = count_null_array(database->channels) - 1;
    for (int i = 0; i < channels_count; i++)
    {
        if (strcmp(uuid, database->channels[i]->uuid) == 0)
            return database->channels[i];
    }

    return NULL;
}
channel_t *find_channel_by_name(database_t *database, char *name)
{
    int channels_count = count_null_array(database->channels) - 1;
    for (int i = 0; i < channels_count; i++)
    {
        if (strcmp(name, database->channels[i]->name) == 0)
            return database->channels[i];
    }

    return NULL;
}

void add_thread(database_t *database, thread_t *new_thread)
{
    int threads_count = count_null_array(database->threads) - 1;
    database->threads = realloc(database->threads, sizeof(thread_t *) * (threads_count + 2));

    database->threads[threads_count] = new_thread;
    database->threads[threads_count + 1] = NULL;
}
thread_t *find_thread(database_t *database, char *uuid)
{
    int threads_count = count_null_array(database->threads) - 1;
    for (int i = 0; i < threads_count; i++)
    {
        if (strcmp(uuid, database->threads[i]->uuid) == 0)
            return database->threads[i];
    }

    return NULL;
}
thread_t *find_thread_by_title(database_t *database, char *title)
{
    int threads_count = count_null_array(database->threads) - 1;
    for (int i = 0; i < threads_count; i++)
    {
        if (strcmp(title, database->threads[i]->title) == 0)
            return database->threads[i];
    }

    return NULL;
}

void add_reply(database_t *database, reply_t *new_reply)
{
    int replies_count = count_null_array(database->replies) - 1;
    database->replies = realloc(database->replies, sizeof(reply_t *) * (replies_count + 2));

    database->replies[replies_count] = new_reply;
    database->replies[replies_count + 1] = NULL;
}