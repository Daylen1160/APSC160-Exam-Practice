// OnlineGDB users: Change this to either "template.h" or "solution.h" to test
// Local IDE/Git users: Change this to either "template.c" or "solution.c" to test
#include "template.c"

// DO NOT TOUCH ANYTHING BELOW THIS LINE
#include <stdio.h>
#include <stddef.h>

int main() {
	printf("Running Holiday of Equality Test Cases...\n");
	printf("====================================================\n\n");
	int totalTests = 0;
	int passedTests = 0;

	// --- Test Case 1 ---
	totalTests++;
	int nums1[] = {0, 1, 2, 3, 4};
	int size1 = sizeof(nums1) / sizeof(nums1[0]);
	int attempt1 = minimumBurlesToSpend(nums1, size1);
	int answer1 = 10;

	if (attempt1 == answer1) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt1);
		printf("  Expected: %d\n\n", answer1);
	}
	printf("----------------------------------------\n");

	// --- Test Case 2 ---
	totalTests++;
	int nums2[] = {1, 1, 0, 1, 1};
	int size2 = sizeof(nums2) / sizeof(nums2[0]);
	int attempt2 = minimumBurlesToSpend(nums2, size2); 
	int answer2 = 1;

	if (attempt2 == answer2) { 
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt2);
		printf("  Expected: %d\n\n", answer2);
	}
	printf("----------------------------------------\n");

	// --- Test Case 3: All citizens are equal ---
	totalTests++;
	int nums3[] = {5, 5, 5, 5};
	int size3 = sizeof(nums3) / sizeof(nums3[0]);
	int attempt3 = minimumBurlesToSpend(nums3, size3);
	int answer3 = 0;

	if (attempt3 == answer3) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt3);
		printf("  Expected: %d\n\n", answer3);
	}
	printf("----------------------------------------\n");

	// --- Test Case 4: Only one citizen ---
	totalTests++;
	int nums4[] = {100};
	int size4 = sizeof(nums4) / sizeof(nums4[0]);
	int attempt4 = minimumBurlesToSpend(nums4, size4);
	int answer4 = 0;

	if (attempt4 == answer4) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt4);
		printf("  Expected: %d\n\n", answer4);
	}
	printf("----------------------------------------\n");

	// --- Test Case 5: Empty array (tests edge case) ---
	totalTests++;
	int* nums5 = NULL;
	int size5 = 0;
	int attempt5 = minimumBurlesToSpend(nums5, size5);
	int answer5 = 0;

	if (attempt5 == answer5) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt5);
		printf("  Expected: %d\n\n", answer5);
	}
	printf("----------------------------------------\n");

	// --- Test Case 6: Max value at the beginning ---
	totalTests++;
	int nums6[] = {50, 10, 20};
	int size6 = sizeof(nums6) / sizeof(nums6[0]);
	int attempt6 = minimumBurlesToSpend(nums6, size6);
	int answer6 = 70;

	if (attempt6 == answer6) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt6);
		printf("  Expected: %d\n\n", answer6);
	}
	printf("----------------------------------------\n");

	// --- Test Case 7: All citizens have zero ---
	totalTests++;
	int nums7[] = {0, 0, 0};
	int size7 = sizeof(nums7) / sizeof(nums7[0]);
	int attempt7 = minimumBurlesToSpend(nums7, size7);
	int answer7 = 0;

	if (attempt7 == answer7) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt7);
		printf("  Expected: %d\n\n", answer7);
	}
	printf("----------------------------------------\n");

	// --- Test Case 8: Large numbers (from constraints) ---
	totalTests++;
	int nums8[] = {1000000, 0, 500000};
	int size8 = sizeof(nums8) / sizeof(nums8[0]);
	int attempt8 = minimumBurlesToSpend(nums8, size8);
	int answer8 = 1500000;

	if (attempt8 == answer8) {
		passedTests++;
		printf("Test Case %d: PASS\n", totalTests);
	} else {
		printf("Test Case %d: FAIL\n", totalTests);
		printf("  Output: %d\n", attempt8);
		printf("  Expected: %d\n\n", answer8);
	}
	printf("----------------------------------------\n");

	printf("\nSUMMARY: Passed %d/%d tests.\n", passedTests, totalTests);
	return 0;
}