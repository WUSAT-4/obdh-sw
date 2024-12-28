#include <stdlib.h>

#include "dummy_subsystems.h"

float get_battery_gauge() {
    return (float) rand()/(float)(RAND_MAX/100);
}

void get_image_data(int*** image_buffer, int row, int col) {
    int **image = *image_buffer;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            image[i][j] = (int) rand()/(int)(RAND_MAX/256);
        }
    }
}

float get_temperature() {
    return (float) rand()/(float)(RAND_MAX/70);
}