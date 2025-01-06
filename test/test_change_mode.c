#include <stdio.h>
#include <stdlib.h>

#include "../src/functions.h"
#include "../src/globals.h"
#include "../src/dummy_subsystems.h"

int main() {
    change_op_mode(1, 30.0f, 69);

    if (OPERATING_MODE != NORMAL) {
        fprintf(stderr, "Change mode HEARTBEAT->NORMAL failed. Expected 1 got %d\n", OPERATING_MODE);
        exit(1);
    }
}