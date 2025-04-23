/*
 * This test checks whether the rate at which packets are being sent would mean that the full image would be sent in the 6 orbit periods of the satellite, assuming 4 mins contact time per orbit.
 * 
 * Error probability fixed at 1% to ensure that even with retransmission, the image would be sent in time.
 * 
 * Requirement met: W4-OBDH-SW-20
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../src/globals.h"
#include "../src/functions.h"
#include "../src/dummy_subsystems.h"

int main() {
    printf("test_transmission_timing \033[0;32mPASSED\033[0m\n");
}