/*
 * This test checks whether the functions in src folder can be accessed. If this test breaks, you've probably messed with the Makefile or the directory structure, or forgotten an include somewhere.
 *
 * You can delete this test and the hello() function once you're happy with everything, it's basically just a sanity check.
 * 
 * Requirement met: None
*/

#include <stdio.h>

#include "../src/functions.h"

int main() {
    hello();

    printf("test_hello_world \033[0;32mPASSED\033[0m\n");
}