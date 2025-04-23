/*
 * This test checks whether the packets are being formed correctly.
 * 
 * Requirement met: W4-OBDH-SW-10
*/

#include <stdio.h>
#include "../src/dummy_subsystems.h"

int main() {
    int **image_buffer = (int **) malloc(IMAGE_HEIGHT * sizeof(int *));

    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        image_buffer[i] = (int *) malloc(IMAGE_WIDTH * sizeof(int));
    }

    get_image_data(&image_buffer);

    make_packet(image_buffer);
    
}