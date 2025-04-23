#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "dummy_subsystems.h"
#include "globals.h"

float get_battery_gauge() {
    return (float) rand()/(float)(RAND_MAX/100);
}

void get_image_data(int*** image_buffer) {
    int **image = *image_buffer;

    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = (int) rand()/(int)(RAND_MAX/256);
        }
    }
}

float get_temperature() {
    return (float) rand()/(float)(RAND_MAX/70);
}

unsigned long get_timestamp() {
    return (unsigned long) time(NULL);
}