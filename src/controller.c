#include "functions.h"
#include "globals.h"

op_mode_t OPERATING_MODE = HEARTBEAT;

void change_op_mode(bool_t heartbeat_received, float power_gen, int battery_level) {
    op_mode_t nxt_mode = OPERATING_MODE;

    if (OPERATING_MODE == HEARTBEAT) {
        if (heartbeat_received == TRUE) {
            nxt_mode = NORMAL;
        }
    } else if (OPERATING_MODE == NORMAL) {
        if (power_gen <= POWER_GEN_LOW || battery_level <= BATTERY_SAFE) {
            nxt_mode = SAFE;
        }
    } else if (OPERATING_MODE == SAFE) {
        if (power_gen > POWER_GEN_LOW && battery_level > BATTERY_SAFE) {
            nxt_mode = NORMAL;
        } else if (battery_level <= BATTERY_SURVIVAL) {
            nxt_mode = SURVIVAL;
        }
    } else {
        if (battery_level > BATTERY_SURVIVAL) {
            nxt_mode = SAFE;
        }
    }

    OPERATING_MODE = nxt_mode;
}