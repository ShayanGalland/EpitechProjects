#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include "myteams.h"

// Packet structure:
// 1 byte: ID
// 2 byte: Size of the packet
// n bytes: Payload
#define HEADER_SIZE 3

#define MAX_PACKET_SIZE 1024

#define ERROR_RESPONSE_PACKET_ID 0x01
#define ERROR_CODE_UNKNOWN_TEAM 1    // got uuid too
#define ERROR_CODE_UNKNOWN_CHANNEL 2 // got uuid too
#define ERROR_CODE_UNKNOWN_THREAD 3  // got uuid too
#define ERROR_CODE_UNKNOWN_USER 4    // got uuid too
#define ERROR_CODE_UNAUTHORIZED 5
#define ERROR_CODE_ALREADY_EXISTS 6

#define LOGIN_REQUEST_PACKET_ID 0x02  // Payload: username(str)
#define LOGIN_RESPONSE_PACKET_ID 0x03 // Payload: uuid(str)

#define LOGOUT_REQUEST_PACKET_ID 0x04 // Payload: None

#define USERS_REQUEST_PACKET_ID 0x05 // Payload: None
#define USERS_RESPONSE_PACKET_ID 0x06

#define USER_REQUEST_PACKET_ID 0x07  // Payload: uuid
#define USER_RESPONSE_PACKET_ID 0x08 // Payload: uuid, username, status

#define SEND_PRIVATE_MESSAGE_REQUEST_PACKET_ID 0x09      // Payload: uuid, message
#define PRIVATE_MESSAGE_RECEIVED_RESPONSE_PACKET_ID 0x10 // Payload: uuid, message

#define MESSAGES_REQUEST_PACKET_ID 0x11  // Payload: uuid
#define MESSAGES_RESPONSE_PACKET_ID 0x12 // Payload: uuid, body

#define CREATE_REQUEST_PACKET_ID 0x13
#define CREATE_TEAM_RESPONSE_PACKET_ID 0x19
#define CREATE_CHANNEL_RESPONSE_PACKET_ID 0x20
#define CREATE_THREAD_RESPONSE_PACKET_ID 0x21
#define CREATE_REPLY_RESPONSE_PACKET_ID 0x22

#define LIST_REQUEST_PACKET_ID 0x14
#define LIST_TEAMS_RESPONSE_PACKET_ID 0x23
#define LIST_CHANNELS_RESPONSE_PACKET_ID 0x24
#define LIST_THREADS_RESPONSE_PACKET_ID 0x25
#define LIST_REPLIES_RESPONSE_PACKET_ID 0x26

#define INFO_REQUEST_PACKET_ID 0x15
#define INFO_USER_RESPONSE_PACKET_ID 0x27
#define INFO_TEAM_RESPONSE_PACKET_ID 0x28
#define INFO_CHANNEL_RESPONSE_PACKET_ID 0x29
#define INFO_THREAD_RESPONSE_PACKET_ID 0x30

#define SUBSCRIBE_REQUEST_PACKET_ID 0x16
#define SUBSCRIBE_RESPONSE_PACKET_ID 0x31

#define SUBSCRIBED_REQUEST_PACKET_ID 0x17
#define SUBSCRIBED_RESPONSE_PACKET_ID 0x33
#define SUBSCRIBED_USERS_RESPONSE_PACKET_ID 0x34

#define UNSUBSCRIBED_REQUEST_PACKET_ID 0x18
#define UNSUBSCRIBED_RESPONSE_PACKET_ID 0x32

#define TEAM_CREATED_RESPONSE_PACKET_ID 0x35
#define CHANNEL_CREATED_RESPONSE_PACKET_ID 0x36
#define THREAD_CREATED_RESPONSE_PACKET_ID 0x37
#define REPLY_RECEIVED_RESPONSE_PACKET_ID 0x38

#endif