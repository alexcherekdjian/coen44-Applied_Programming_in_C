/* Name: Alex Cherekdjian
Date: October 31, 2016
Title: Matrix Vector Calculations
File: Lab 7 EC
Description: This program computes a variety of different calculations with vector components using matrices and allows the user to input how many dimensions each vector will contain*/

#include <stdio.h>
#include "stdafx.h"

// declaring global variables
float vectorsum(float repONE[], float repTWO[], float ans[]);
float vectordiff(float repONE[], float repTWO[], float ans[]);
float vectorminmax(float repONE[], float repTWO[], float min[], float max[]);

int DIMENSION;

int main() {
	//asking user how many dimensions and assigning DIMENSIONS to value given
	printf("How many dimensions: ");
	scanf_s("%d", &DIMENSION);

	float vectorONE[1000], vectorTWO[1000], ans[1000], max[1000], min[1000];
	int i;

	// prompting for components for each dimension
	printf("Vector 1\n");
	for (i = 0; i < DIMENSION; i++) {
		printf("Component %d: ", i + 1);
		scanf_s("%f", &vectorONE[i]);
	}

	printf("\nVector 2\n");
	for (i = 0; i < DIMENSION; i++) {
		printf("Component %d: ", i + 1);
		scanf_s("%f", &vectorTWO[i]);
	}

	// printing original vectors
	printf("\n\nVector 1\n");
	for (i = 0; i < DIMENSION; i++) {
		printf("%.2f ", vectorONE[i]);
	}
	printf("\n\nVector 2\n");
	for (i = 0; i < DIMENSION; i++) {
		printf("%.2f ", vectorTWO[i]);
	}

	//running calculations
	vectorsum(vectorONE, vectorTWO, ans);
	vectordiff(vectorONE, vectorTWO, ans);
	vectorminmax(vectorONE, vectorTWO, max, min);

	return 0;
}

float vectorsum(float repONE[], float repTWO[], float ans[]) {
	int i;
	float SUM[1000];

	// adding first numbers of matrix together
	for (i = 0; i < DIMENSION; i++) {
		ans[i] = repONE[i] + repTWO[i];
	}

	for (i = 0; i < DIMENSION; i++) {
		SUM[i] = ans[i];
	}

	// printing results to user
	printf("\n\nVector Sum\n");
	for (i = 0; i < DIMENSION; i++) {
		printf("%.2f ", SUM[i]);
	}

	return 0;
}

float vectordiff(float repONE[], float repTWO[], float ans[]) {
	int i;
	float DIFF[1000];

	// subtracting numbers of matrix
	for (i = 0; i < DIMENSION; i++) {
		ans[i] = repONE[i] - repTWO[i];
	}
	for (i = 0; i < DIMENSION; i++) {
		DIFF[i] = ans[i];
	}
	
	// printing results to user
	printf("\n\nVector Diff\n");
	for (i = 0; i < DIMENSION; i++) {
		printf("%.2f ", DIFF[i]);
	}

	return 0;
}

float vectorminmax(float repONE[], float repTWO[], float min[], float max[]) {
	int i;

	// comparing values of matrix and deciding which is a max or a min
	max[0] = repONE[0];
	for (i = 1; i < DIMENSION; i++) {
		if (max[0] > repONE[i]) {
		}else {
			max[0] = repONE[i];
		}
	}
	for (i = 0; i < DIMENSION; i++) {
		if (max[0] > repTWO[i]) {
		}else {
			max[0] = repTWO[i];
		}
	}

	min[0] = repONE[0];
	for (i = 1; i < DIMENSION; i++) {
		if (min[0] < repONE[i]) {
		}else {
			min[0] = repONE[i];
		}
	}
	for (i = 0; i < DIMENSION; i++) {
		if (min[0] < repTWO[i]) {
		}else {
			min[0] = repTWO[i];
		}
	}

	// printing results to user
	printf("\n\nVector Max\n");
	printf("%.2f ", max[0]);

	printf("\n\nVector Min\n");
	printf("%.2f\n\n", min[0]);

	return 0;
}
