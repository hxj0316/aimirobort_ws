#pragma once
// MESSAGE COMMAND_LONG PACKING

#define MAVLINK_MSG_ID_COMMAND_LONG 30

MAVPACKED(
typedef struct __mavlink_command_long_t {
 float param1; /*<  Parameter 1 (for the specific command).*/
 float param2; /*<  Parameter 2 (for the specific command).*/
 float param3; /*<  Parameter 3 (for the specific command).*/
 float param4; /*<  Parameter 4 (for the specific command).*/
 float param5; /*<  Parameter 5 (for the specific command).*/
 float param6; /*<  Parameter 6 (for the specific command).*/
 float param7; /*<  Parameter 7 (for the specific command).*/
 uint16_t command; /*<  Command ID (of command to send).*/
 uint8_t target_system; /*<  System which should execute the command*/
 uint8_t confirm; /*<  0: the system do not send confirmation. 1-255: the system must send back the confirmation.*/
}) mavlink_command_long_t;

#define MAVLINK_MSG_ID_COMMAND_LONG_LEN 32
#define MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN 32
#define MAVLINK_MSG_ID_30_LEN 32
#define MAVLINK_MSG_ID_30_MIN_LEN 32

#define MAVLINK_MSG_ID_COMMAND_LONG_CRC 198
#define MAVLINK_MSG_ID_30_CRC 198



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND_LONG { \
    30, \
    "COMMAND_LONG", \
    10, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_command_long_t, target_system) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_command_long_t, command) }, \
         { "confirm", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_command_long_t, confirm) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_command_long_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_command_long_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_long_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_long_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_command_long_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_command_long_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_command_long_t, param7) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND_LONG { \
    "COMMAND_LONG", \
    10, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_command_long_t, target_system) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_command_long_t, command) }, \
         { "confirm", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_command_long_t, confirm) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_command_long_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_command_long_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_long_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_long_t, param4) }, \
         { "param5", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_command_long_t, param5) }, \
         { "param6", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_command_long_t, param6) }, \
         { "param7", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_command_long_t, param7) }, \
         } \
}
#endif

/**
 * @brief Pack a command_long message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System which should execute the command
 * @param command  Command ID (of command to send).
 * @param confirm  0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param param1  Parameter 1 (for the specific command).
 * @param param2  Parameter 2 (for the specific command).
 * @param param3  Parameter 3 (for the specific command).
 * @param param4  Parameter 4 (for the specific command).
 * @param param5  Parameter 5 (for the specific command).
 * @param param6  Parameter 6 (for the specific command).
 * @param param7  Parameter 7 (for the specific command).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint16_t command, uint8_t confirm, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, confirm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.confirm = confirm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
}

/**
 * @brief Pack a command_long message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System which should execute the command
 * @param command  Command ID (of command to send).
 * @param confirm  0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param param1  Parameter 1 (for the specific command).
 * @param param2  Parameter 2 (for the specific command).
 * @param param3  Parameter 3 (for the specific command).
 * @param param4  Parameter 4 (for the specific command).
 * @param param5  Parameter 5 (for the specific command).
 * @param param6  Parameter 6 (for the specific command).
 * @param param7  Parameter 7 (for the specific command).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_long_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint16_t command,uint8_t confirm,float param1,float param2,float param3,float param4,float param5,float param6,float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, confirm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.confirm = confirm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND_LONG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
}

/**
 * @brief Encode a command_long struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_long_t* command_long)
{
    return mavlink_msg_command_long_pack(system_id, component_id, msg, command_long->target_system, command_long->command, command_long->confirm, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
}

/**
 * @brief Encode a command_long struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command_long C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_long_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_long_t* command_long)
{
    return mavlink_msg_command_long_pack_chan(system_id, component_id, chan, msg, command_long->target_system, command_long->command, command_long->confirm, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
}

/**
 * @brief Send a command_long message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System which should execute the command
 * @param command  Command ID (of command to send).
 * @param confirm  0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 * @param param1  Parameter 1 (for the specific command).
 * @param param2  Parameter 2 (for the specific command).
 * @param param3  Parameter 3 (for the specific command).
 * @param param4  Parameter 4 (for the specific command).
 * @param param5  Parameter 5 (for the specific command).
 * @param param6  Parameter 6 (for the specific command).
 * @param param7  Parameter 7 (for the specific command).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_long_send(mavlink_channel_t chan, uint8_t target_system, uint16_t command, uint8_t confirm, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, confirm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, buf, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#else
    mavlink_command_long_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.param5 = param5;
    packet.param6 = param6;
    packet.param7 = param7;
    packet.command = command;
    packet.target_system = target_system;
    packet.confirm = confirm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, (const char *)&packet, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#endif
}

/**
 * @brief Send a command_long message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_command_long_send_struct(mavlink_channel_t chan, const mavlink_command_long_t* command_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_command_long_send(chan, command_long->target_system, command_long->command, command_long->confirm, command_long->param1, command_long->param2, command_long->param3, command_long->param4, command_long->param5, command_long->param6, command_long->param7);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, (const char *)command_long, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMMAND_LONG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_command_long_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint16_t command, uint8_t confirm, float param1, float param2, float param3, float param4, float param5, float param6, float param7)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_float(buf, 16, param5);
    _mav_put_float(buf, 20, param6);
    _mav_put_float(buf, 24, param7);
    _mav_put_uint16_t(buf, 28, command);
    _mav_put_uint8_t(buf, 30, target_system);
    _mav_put_uint8_t(buf, 31, confirm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, buf, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#else
    mavlink_command_long_t *packet = (mavlink_command_long_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->param5 = param5;
    packet->param6 = param6;
    packet->param7 = param7;
    packet->command = command;
    packet->target_system = target_system;
    packet->confirm = confirm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND_LONG, (const char *)packet, MAVLINK_MSG_ID_COMMAND_LONG_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LONG_LEN, MAVLINK_MSG_ID_COMMAND_LONG_CRC);
#endif
}
#endif

#endif

// MESSAGE COMMAND_LONG UNPACKING


/**
 * @brief Get field target_system from command_long message
 *
 * @return  System which should execute the command
 */
static inline uint8_t mavlink_msg_command_long_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field command from command_long message
 *
 * @return  Command ID (of command to send).
 */
static inline uint16_t mavlink_msg_command_long_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field confirm from command_long message
 *
 * @return  0: the system do not send confirmation. 1-255: the system must send back the confirmation.
 */
static inline uint8_t mavlink_msg_command_long_get_confirm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field param1 from command_long message
 *
 * @return  Parameter 1 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from command_long message
 *
 * @return  Parameter 2 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from command_long message
 *
 * @return  Parameter 3 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from command_long message
 *
 * @return  Parameter 4 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field param5 from command_long message
 *
 * @return  Parameter 5 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field param6 from command_long message
 *
 * @return  Parameter 6 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field param7 from command_long message
 *
 * @return  Parameter 7 (for the specific command).
 */
static inline float mavlink_msg_command_long_get_param7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a command_long message into a struct
 *
 * @param msg The message to decode
 * @param command_long C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_long_decode(const mavlink_message_t* msg, mavlink_command_long_t* command_long)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    command_long->param1 = mavlink_msg_command_long_get_param1(msg);
    command_long->param2 = mavlink_msg_command_long_get_param2(msg);
    command_long->param3 = mavlink_msg_command_long_get_param3(msg);
    command_long->param4 = mavlink_msg_command_long_get_param4(msg);
    command_long->param5 = mavlink_msg_command_long_get_param5(msg);
    command_long->param6 = mavlink_msg_command_long_get_param6(msg);
    command_long->param7 = mavlink_msg_command_long_get_param7(msg);
    command_long->command = mavlink_msg_command_long_get_command(msg);
    command_long->target_system = mavlink_msg_command_long_get_target_system(msg);
    command_long->confirm = mavlink_msg_command_long_get_confirm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMMAND_LONG_LEN? msg->len : MAVLINK_MSG_ID_COMMAND_LONG_LEN;
        memset(command_long, 0, MAVLINK_MSG_ID_COMMAND_LONG_LEN);
    memcpy(command_long, _MAV_PAYLOAD(msg), len);
#endif
}
