#ifndef WUSAT_GLOBALS_H
#define WUSAT_GLOBALS_H

#define BATTERY_SAFE 40
#define BATTERY_SURVIVAL 20
#define POWER_GEN_LOW 50

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


extern op_mode_t OPERATING_MODE;

#endif