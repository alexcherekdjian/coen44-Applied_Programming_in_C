// Alex Cherekdjian
// Professor Danielson
// COEN Lab #9
// November 26, 2016
/* This function is designed to get inputs from the user in order to estimate a value
to a certain percentage */

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// globally defining counters and exponents for functions
int countFrac = 0, countLog = 0;
int n = 1; // power counter for logCalc
int j = 1; // power counter for fracCalc
float ansLog, prevAnsLog;
float ansFrac, prevAnsFrac;

// defining structure consisting of counter and answer to function
typedef struct {
	int count;
	float ans;
} return_t;

// programmer defined functions that return structures
return_t *logApprox(float x, float precision);
return_t *fracApprox(float x, float precision);

int main() {
	// defining x, the value to approx, precision and input of whether the user wants to do another calculation
	float x, precision;
	char input;

	// run until quit operation is enacted
	do {

		// prompting for inputs
		printf("x = ");
		scanf("%f", &x);

		// check x to see if in bounds, if not ask for another until it is
		while (x >= 1 || x <= -1) {
			printf("\nSorry, but x needs to be in the bounds (-1 < x > 1)\n\n");
			printf("x = ");
			scanf("%f", &x);
		}

		printf("\nprecision = ");
		scanf("%f", &precision);

		// running calculations and storing them in proper structures
		return_t *ansLog = logApprox(x, precision);
		return_t *ansFrac = fracApprox(x, precision);

		// printing results
		printf("\n\n1/(1-x) Approx: %f", ansFrac->ans);
		printf("\nIterations: %d", ansFrac->count);

		printf("\n\nln((1 + x)/(1 - x)) Approx: %f", ansLog->ans);
		printf("\nIterations: %d", ansLog->count);

		// asking user if another calculation is needed
		printf("\n\nRun another calculation? (Y)es (N)o? ");
		scanf(" %c", &input);
		// making input lower case
		if (input <= 'Z' && input >= 'A')
			input = input + 32;

		// if anything but y is entered then exit the program
		if (input != 'y')
			break;

	} while (true);

	printf("\n\nGoodbye :)\n");

	return 0;
}

return_t *logApprox(float x, float precision) {
	// initializing variable
	if (countLog == 0) {
		ansLog = 2 * x;
		countLog++;
	}

	// quit statement: if abs is less than precision then quit
	if (fabsf(prevAnsLog - ansLog) < precision) {
	}
	else { // else continue another iteration
		countLog++;
		n += 2;
		prevAnsLog = ansLog;
		ansLog += 2 * powf(x, n) / n;
		logApprox(x, precision);
	}

	// create answer structure
	return_t *ans = (return_t*)malloc(sizeof(return_t));
	ans->ans = ansLog;
	ans->count = countLog;
	return ans;
}

return_t *fracApprox(float x, float precision) {
	// initializing variable
	if (countFrac == 0) {
		ansFrac = 1;
		countFrac++;
	}

	// quit statement: if abs is less than precision then quit
	if (fabsf(prevAnsFrac - ansFrac) < precision) {
	}
	else { // else continue another iteration
		countFrac++;
		prevAnsFrac = ansFrac;
		ansFrac += powf(x, j);
		j++;
		fracApprox(x, precision);
	}

	// create answer structure
	return_t *ans = (return_t*)malloc(sizeof(return_t));
	ans->ans = ansFrac;
	ans->count = countFrac;
	return ans;
}
