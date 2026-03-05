#include <stdio.h>

int minimumBurlesToSpend(int[], int);

/**
 * @param: citizens[] - array of ints representing each citizen's welfare
 * @param: citizensSize - size of citizens[]
 * @returns: the minimum number of burles to spend to equalize welfare
 * */
int minimumBurlesToSpend(int citizens[], int citizensSize) {
	if (citizensSize == 0) {
		return 0;
	}

	int maxWelfare = citizens[0];
	for (int i = 1; i < citizensSize; i++) {
		if (citizens[i] > maxWelfare) {
			maxWelfare = citizens[i];
		}
	}

	int giveCounter = 0;
	for (int i = 0; i < citizensSize; i++) {
		giveCounter += maxWelfare - citizens[i];
	}
	return giveCounter;
}