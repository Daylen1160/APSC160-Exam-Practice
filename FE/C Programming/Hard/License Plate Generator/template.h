/**
 * @file template.h
 * @brief License Plate Generator Template
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define NUMPLATES 5
#define PLATELENGTH 8
#define NUMLETTERS 3
#define NUMDIGITS 3

void licensePlateGenerator(char licensePlates[][PLATELENGTH]);

/**
 * @brief Generate 5 unique license plates in the format "LLL-DDD"
 * @param[out] licensePlates 2D array to store the generated license plates
 * @modifies licensePlates with generated plates
 */
void licensePlateGenerator(char licensePlates[][PLATELENGTH]) {
    // TODO: Implement this method
}