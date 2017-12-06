/* Name: Alex Cherekdjian
Date: October 3, 2016
Title: Life Expectancy Calculations
File: Lab 6
Description: This program computes a variety of different calculations with life expectancy data using matrices. */

#include <stdio.h>
#include "stdafx.h"

int main() {
	// declaring variables
	float originalData[7][2][4], calcONE[7][2], calcTWO[7][2], calc1DIFF[7][2], calc2DIFF[7][2];
	float femaleBlack, femaleWhite, maleBlack, maleWhite;
	float calc1, calc1A, calc2, calc2A, calc1diff, calc1Adiff, calc2diff, calc2Adiff;
	int i, year, YEAR[7][1];
	// prompting user 7 times for data sets
	for (i = 0; i<7; i++) {
		printf("Decade: ");
		scanf_s("%d", &year);
		YEAR[i][0] = year;
		
		printf("Female Black: ");
		scanf_s("%f", &femaleBlack);
		originalData[i][0][0] = femaleBlack;
		originalData[i][0][2] = femaleBlack;

		printf("Female White: ");
		scanf_s("%f", &femaleWhite);
		originalData[i][0][1] = femaleWhite;
		originalData[i][1][2] = femaleWhite;

		printf("Male Black: ");
		scanf_s("%f", &maleBlack);
		originalData[i][1][0] = maleBlack;
		originalData[i][0][3] = maleBlack;

		printf("Male White: ");
		scanf_s("%f", &maleWhite);
		originalData[i][1][1] = maleWhite;
		originalData[i][1][3] = maleWhite;

		printf("\n");
	}
	// first calculation of women vs men of the same race (1) = white (1A) = black
	for (i = 0; i<7; i++) {
		calc1 = originalData[i][0][1] - originalData[i][1][1];
		calc1A = originalData[i][0][0] - originalData[i][1][0];
		if (calc1<0) {
			calc1 *= -1;
		}
		if (calc1A<0) {
			calc1A *= -1;
		}
		calcONE[i][0] = calc1;
		calcONE[i][1] = calc1A;
	}
	// second calculation of women vs women (2) of different race and man vs man (2A) of the second race
	for (i = 0; i<7; i++) {
		calc2 = originalData[i][0][2] - originalData[i][1][2];
		calc2A = originalData[i][0][3] - originalData[i][1][3];
		if (calc2<0) {
			calc2 *= -1;
		}
		if (calc2A<0) {
			calc2A *= -1;
		}
		calcTWO[i][0] = calc2;
		calcTWO[i][1] = calc2A;
	}
	// percent difference of female black (1) and female white (1A)
	for (i = 0; i<7; i++) {
		calc1diff = ((originalData[i][0][0] - originalData[i + 1][0][0]) / (originalData[i][0][0])) * 100;
		calc1Adiff = ((originalData[i][0][1] - originalData[i + 1][0][1]) / (originalData[i][0][1])) * 100;
		calc1diff *= -1;
		calc1Adiff *= -1;
		calc1DIFF[i + 1][0] = calc1diff;
		calc1DIFF[i + 1][1] = calc1Adiff;
	}
	// percent difference of male black (2) and male white (2A)
	for (i = 0; i<7; i++) {
		calc2diff = ((originalData[i][1][0] - originalData[i + 1][1][0]) / (originalData[i][1][0])) * 100;
		calc2Adiff = ((originalData[i][1][1] - originalData[i + 1][1][1]) / (originalData[i][1][1])) * 100;
		calc2diff *= -1;
		calc2Adiff *= -1;
		calc2DIFF[i + 1][0] = calc2diff;
		calc2DIFF[i + 1][1] = calc2Adiff;
	}
	// printing original data
	printf("\nOriginal Data\n");
	printf("        Female          Male\n");
	printf("Year    Black   White   Black   White\n");
	for (i = 0; i<7; i++) {
		printf("%.2d    %.2f   %.2f   %.2f   %.2f\n", YEAR[i][0], originalData[i][0][0], originalData[i][0][1], originalData[i][1][0], originalData[i][1][1]);
	}
	// printing difference data
	printf("\nDifference Data\n");
	printf("        W Vs M          W Vs W  M Vs M\n");
	printf("       (same race)     (diff race)\n");
	printf("Year    Black   White   Female  Male\n");
	for (i = 0; i<7; i++) {
		printf("%.2d    %.2f    %.2f    %.2f    %.2f\n", YEAR[i][0], calcONE[i][1], calcONE[i][0], calcTWO[i][0], calcTWO[i][1]);
	}
	// printing percent difference data
	printf("\nPercent Difference Data\n");
	printf("        Female          Male\n");
	printf("Year    Black   White   Black   White\n");
	printf("%.2d\n", YEAR[0][0]);
	for (i = 1; i<7; i++) {
		printf("%.2d    %.2f%%   %.2f%%   %.2f%%   %.2f%%\n", YEAR[i][0], calc1DIFF[i][0], calc1DIFF[i][1], calc2DIFF[i][0], calc2DIFF[i][1]);
	}
	return 0;
}