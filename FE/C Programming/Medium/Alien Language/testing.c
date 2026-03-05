// Rename main() to student_main() so we can call it
#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

// DO NOT MODIFY BELOW THIS LINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Compute expected encoding according to problem rules:
// - Letters (A-Z or a-z): treated the same. Convert to uppercase, then map to char with value (ASCII_upper - 32).
// - Digits: replaced with the character whose ASCII value equals the length of the sentence.
// - Everything else: left unchanged.
void compute_expected(const char *orig, char *out, size_t outsize) {
    size_t len = strlen(orig);
    size_t pos = 0;
    for (size_t i = 0; i < len && pos + 1 < outsize; ++i) {
        unsigned char c = (unsigned char)orig[i];
        if (isalpha(c)) {
            unsigned char up = (unsigned char)toupper(c);
            unsigned char mapped = (unsigned char)((int)up - 32);
            out[pos++] = (char)mapped;
        } else if (isdigit(c)) {
            unsigned char mapped = (unsigned char)len;
            out[pos++] = (char)mapped;
        } else {
            out[pos++] = orig[i];
        }
    }
    out[pos] = '\0';
}

int main(void) {
    printf("Running Alien Language tests...\n");
    printf("====================================================\n\n");

    // 1. Setup Input for student_main
    const char *input_filename = "_input_test.txt";
    // We use a sentence with mixed case, digits, and punctuation for a good test.
    const char *test_sentence = "The Quick Brown Fox Jumps Over 13 Lazy Dogs.";
    
    FILE *infile = fopen(input_filename, "w");
    if (!infile) {
        printf("Error creating test input file.\n");
        return 1;
    }
    fprintf(infile, "%s\n", test_sentence);
    fclose(infile);

    // 2. Redirect stdin to the file so scanf works without user interaction
    if (!freopen(input_filename, "r", stdin)) {
        printf("Error redirecting stdin.\n");
        return 1;
    }

    // 3. Run student's main
    printf("Invoking your main() with input: \"%s\"\n", test_sentence);
    printf("(Your program output starts below)\n");
    printf("----------------------------------------\n");
    
    // We expect student_main to return 0, but whatever it returns is fine.
    int ret = student_main();
    
    // Flush stdout to ensure student output is printed before our validation output
    fflush(stdout);
    
    printf("\n----------------------------------------\n");
    printf("(Student program finished with exit code %d)\n", ret);

    // 4. Validate output file (decoder.txt)
    const char *filename = "decoder.txt";
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("\nERROR: Could not open '%s' for reading.\n", filename);
        printf("Make sure your program creates '%s' and writes to it!\n", filename);
        // Clean up
        remove(input_filename);
        return 2;
    }

    char orig[2048] = {0};
    char actual[4096] = {0};

    // Read line 1: original sentence (from decoder.txt)
    if (!fgets(orig, sizeof(orig), f)) {
        printf("\nERROR: '%s' is empty or missing the original sentence (Line 1).\n", filename);
        fclose(f);
        remove(input_filename);
        return 3;
    }
    // Remove newline
    orig[strcspn(orig, "\r\n")] = '\0';

    // Read line 2: encoded sentence (from decoder.txt)
    if (!fgets(actual, sizeof(actual), f)) {
        printf("\nERROR: '%s' is missing the encoded sentence (Line 2).\n", filename);
        fclose(f);
        remove(input_filename);
        return 3;
    }
    actual[strcspn(actual, "\r\n")] = '\0';
    fclose(f);
    
    // Cleanup
    remove(input_filename);

    // 5. Compare
    char expected[4096];
    compute_expected(orig, expected, sizeof(expected));

    printf("\nValidation Results:\n");
    printf("-------------------\n");
    printf("Line 1 (Original): \"%s\"\n", orig);
    printf("Line 2 (Actual):   \"%s\"\n", actual);
    printf("Line 2 (Expected): \"%s\"\n", expected);

    if (strcmp(actual, expected) == 0) {
        printf("Test Case 1: PASS\n");
        printf("----------------------------------------\n");
        printf("\nSummary: 1/1 test cases passed.\n");
        printf("====================================================\n");
        return 0;
    } else {
        printf("Test Case 1: FAIL\n");
        printf("  Expected: \"%s\"\n", expected);
        printf("  Actual:   \"%s\"\n", actual);
        printf("----------------------------------------\n");
        printf("\nSummary: 0/1 test cases passed.\n");
        printf("====================================================\n");
        return 1;
    }
}
