#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dummy_subsystems.h"

int main() {
    srand((unsigned int) time(NULL));

    int image_height = 1944;
    int image_width = 2592;

    int **image = malloc(image_height * sizeof(int*));

    for (int i = 0; i < image_height; i++) {
        image[i] = malloc(image_width * sizeof(int));
    }

    get_image_data(&image, image_height, image_width);

    printf("Got image\n");
    
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            if (image[i][j]);
        }
    }

    for (int i = 0; i < image_height; i++) {
        free(image[i]);
    }

    free(image);
}