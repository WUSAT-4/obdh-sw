#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../src/dummy_subsystems.h"
#include "../src/globals.h"

int main() {
    srand((unsigned int) time(NULL));

    int **image = malloc(IMAGE_HEIGHT * sizeof(int*));

    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        image[i] = malloc(IMAGE_WIDTH * sizeof(int));
    }

    get_image_data(&image);

    printf("Got image\n");
    
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            if (image[i][j]);
        }
    }

    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        free(image[i]);
    }

    free(image);
}