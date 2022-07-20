#include "lfsr.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    *reg = (*reg >> 1) | (((*reg & 0x1) ^ ((*reg >> 2) & 0x1) ^
                           ((*reg >> 3) & 0x1) ^ ((*reg >> 5) & 0x1))
                          << 15);
}
