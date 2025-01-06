#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "globals.h"
#include "dummy_subsystems.h"

op_mode_t OPERATING_MODE = HEARTBEAT;
int payload_size = (int) PACKET_SIZE - (int) HEADER_SIZE;
char *data_buffer;

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

void fill_buffer() {
    data_buffer = malloc((PACKET_SIZE - HEADER_SIZE) * sizeof(char));
    char * heartbeat_signal = "Hello, is anyone there";

    if (OPERATING_MODE == HEARTBEAT) {
        memcpy(data_buffer, heartbeat_signal, strlen(heartbeat_signal));
        return;
    }

    if (OPERATING_MODE == NORMAL) {
        int **image = malloc(IMAGE_HEIGHT * sizeof(int*));

        for (int i = 0; i < IMAGE_HEIGHT; i++) {
            image[i] = malloc(IMAGE_WIDTH * sizeof(int));
        }

        get_image_data(&image);
    }
}