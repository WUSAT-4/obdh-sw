#include <stdio.h>
#include <stdlib.h>

#include "../src/functions.h"

int main() {
    int result = hello();
    printf("hello() returned with exit status: %d\n", result);

    if (result != 0) {
        exit(1);
    }
}