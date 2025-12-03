// Run this program to test

// OnlineGDB users: To change between "template.h" and "solution.h", run those files first then run this test file
// Local IDE/Git users: To change between "template.c" and "solution.c", run those files first then run this test file

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
    printf("Running Alien Language tests (file-based)...\n");
    printf("====================================================\n\n");

    const char *filename = "decoder.txt";
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("ERROR: Could not open '%s' for reading. Make sure the student's program created it.\n", filename);
        return 2;
    }

    char orig[2048];
    char actual[4096];

    // Read line 1: original sentence
    if (!fgets(orig, sizeof(orig), f)) {
        printf("ERROR: '%s' does not contain line 1 (original sentence).\n", filename);
        fclose(f);
        return 2;
    }
    // strip trailing newline if present
    orig[strcspn(orig, "\r\n")] = '\0';

    // Read line 2: student's encoded output
    if (!fgets(actual, sizeof(actual), f)) {
        printf("ERROR: '%s' does not contain line 2 (encoded sentence).\n", filename);
        fclose(f);
        return 2;
    }
    actual[strcspn(actual, "\r\n")] = '\0';
    fclose(f);

    char expected[4096];
    compute_expected(orig, expected, sizeof(expected));

    // Print original, expected and actual once (include lengths for clarity)
    printf("Original (line 1): %s\n", orig);
    printf("Expected encoding (len=%zu): %s\n", strlen(expected), expected);
    printf("Actual encoding   (len=%zu): %s\n", strlen(actual), actual);

    if (strcmp(expected, actual) == 0) {
        printf("\nRESULT: PASS — encoded output matches expected.\n");
        return 0;
    } else {
        printf("\nRESULT: FAIL — encoded output does not match expected.\n");
        return 1;
    }
}
