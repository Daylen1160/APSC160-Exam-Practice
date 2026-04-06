#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// HIJACK MACROS
int portable_rand(void);
void fake_srand(unsigned int seed);
#undef rand
#undef srand
#define rand portable_rand
#define srand fake_srand
#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution.h" to test
#include "solution.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static unsigned long int next = 1;

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void fake_srand(unsigned int seed) {
    next = 123456789;
}

int main(void) {

    FILE *finput = fopen("input.txt", "w");
    if (!finput) { perror("Failed to create input.txt"); return 1; }
    fprintf(finput, "3\n"); 
    fclose(finput);

    if (!freopen("input.txt", "r", stdin)) { perror("freopen stdin failed"); return 1; }
    
    if (!freopen("output.txt", "w", stdout)) { perror("freopen stdout failed"); return 1; }

    next = 12345;
    
    student_main();
    
    fflush(stdout);
    
    FILE *foutput = fopen("output.txt", "r");
    if (!foutput) { fprintf(stderr, "Failed to read output.txt\n"); return 1; }
    
    char buffer[1024];
    char fullOutput[4096] = "";
    while (fgets(buffer, sizeof(buffer), foutput)) {
        strcat(fullOutput, buffer);
    }
    fclose(foutput);
    
    fprintf(stderr, "--- Test Output ---\n%s\n-------------------\n", fullOutput);
    
    // Check for "Digit 3 appears"
    if (strstr(fullOutput, "Digit 3 appears")) {
        fprintf(stderr, "SUCCESS: Output format correct.\n");
    } else {
        fprintf(stderr, "FAILURE: Output format incorrect or missing.\n");
    }
    
    return 0;
}
