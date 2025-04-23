#ifndef WUSAT_GLOBALS_H
#define WUSAT_GLOBALS_H

#define BATTERY_SAFE 40
#define BATTERY_SURVIVAL 20
#define POWER_GEN_LOW 50
#define HEADER_SIZE 16
#define PACKET_SIZE 65536
#define IMAGE_HEIGHT 1944
#define IMAGE_WIDTH 2592

typedef enum {
    HEARTBEAT = 0,
    NORMAL = 1,
    SAFE = 2,
    SURVIVAL = 3
} op_mode_t;

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool_t;

typedef struct __attribute__((__packed__)) {
    short ack;
    float pcb_temp;
    float fdspp_temp;
    float battery_gauge;
    bool_t panel_deployed;
    op_mode_t operating_mode;
    int* image_data;
} wusat_app_t;

typedef struct __attribute__((__packed__)) {
    uint8_t c_flags;
    uint8_t header_len;
    uint8_t seq_num;
    uint8_t ack_num;
    uint16_t checksum;
} rudp_header_t;

extern op_mode_t OPERATING_MODE;
extern char *data_buffer;

#endif