#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/**
 * Validates the strength of a given password.
 * @param password The password string to validate
 * @return An integer strength score based on the criteria met
 */
int passwordStrengthValidator(char password[]) {
    int length = strlen(password);
    if (length < 8) {
        return 0;
    }

    int strength = 1;
    int hasUpper = 0;
    int hasLower = 0;
    int hasAlpha = 0;
    int hasDigit = 0;
    int hasAlnum = 0;
    int hasSpecial = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper++;
            if (hasUpper == 1) {
                strength++;
                hasUpper++;
            }
        } if (islower(password[i])) {
            hasLower++; 
            if (hasLower == 1) {
                strength++;
                hasLower++;
            }  
        } if (isalpha(password[i])) {
            hasAlpha++;
            if (hasAlpha == 2) {
                strength++;
                hasAlpha++;
            }
        } if (isdigit(password[i])) {
            hasDigit++;
            if (hasDigit == 3) {
                strength++;
                hasDigit++;
            }
        } if (isalnum(password[i])) {
            hasAlnum++;
            if (hasAlnum == 4) {
                strength++;
                hasAlnum++;
            }
        } else {
            hasSpecial++;
            if (hasSpecial == 5) {
                strength++;
                hasSpecial++;
            }
        }
    }
    return strength;
}