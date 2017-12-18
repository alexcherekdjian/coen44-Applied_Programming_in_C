/* Name: Alex Cherekdjian
Date: October 15, 2016
Title: Number Crunching Program
File: Lab5
Description: This program computes a multitude of calculations a user may want to know when inputted three numbers such as the max value, min value, whether any numbers are equal, the average, and whether these numbers are close to each other within a certain range. */

#include <stdio.h>
#include "stdafx.h"
#define EPSILON 0.1

// defining user defined functions
float maxval(float one, float two, float three);
float minval(float one, float two, float three);
char equalval(float one, float two, float three);
float averageval(float one, float two, float three);
char nearequal(float one, float two, float three);

char alt();

int main() {

	printf("This program will calculate several properties with respect to three floating point values entered.");

	// running program
	alt();

	return 0;
}

char alt() {
	// assigning variables inputed by user
	float num1, num2, num3;
	char rep;

	// prompting user for 3 numbers
	printf("\nEnter three real numbers: ");
	scanf_s("%g %g %g", &num1, &num2, &num3);

	// calculating all values program will output
	float maxValue = maxval(num1, num2, num3);

	float minValue = minval(num1, num2, num3);

	char equalOrNot = equalval(num1, num2, num2);
	if (equalOrNot == '=')
		equalOrNot = 'Y';
	else
		equalOrNot = 'N';

	float average = averageval(num1, num2, num3);

	char almostEqual = nearequal(num1, num2, num3);

	// printing to user results
	printf("----------------------------------------------------------------\n|Val 1 Val 2 Val 3 Max  Min  Avg  All-Equal Near-Equal Epsilon |");
	printf("\n----------------------------------------------------------------\n|%g%6.3g%6.3g%6.3g%5.3g%5.3g%2.2c\t%5.2c\t    %11.6f|\n----------------------------------------------------------------", num1, num2, num3, maxValue, minValue, average, equalOrNot, almostEqual, EPSILON);
	
	// asking user if there are any more data values needed
	printf("\n\nEnter another set of data values?\n'y' or 'n': ");
	char txt[10];
	scanf_s("%s", &txt, 2);
	rep = txt[0];

	// if rep variable equals yes, it will run the function again, if no it will end
	if (rep == 'y')
		alt();

	return (0);
}

// calculating average of numbers
float averageval(float one, float two, float three) {

	float ave;

	ave = (one + two + three) / 3;

	return (ave);

}

// calculating whether any of the numbers are near equal to each other based on EPSILON
char nearequal(float one, float two, float three) {

	float oneTwo, twoThree, oneThree;
	char result;

	if (one > two)
		oneTwo = one - two;
	else
		oneTwo = two - one;
	if (two > three)
		twoThree = two - three;
	else
		twoThree = three - two;
	if (one > three)
		oneThree = one - three;
	else
		oneThree = three - one;
	if ((oneTwo < EPSILON) || (twoThree < EPSILON) || (oneThree < EPSILON))
		result = 'Y';
	else
		result = 'N';

	return (result);
}

// checking to see if any two numbers are equal
char equalval(float one, float two, float three) {

	char response;

	if ((one == two) && (two == three) && (one == three))
		response = '=';
	else if ((one == two) || (two == three) || (one == three))
		response = '#';

	return (response);

}

// checking max value
float maxval(float one, float two, float three) {

	float max;

	if (one > two)
		max = one;
	else
		max = two;
	if (max > three) {
	}
	else
		max = three;

	return (max);

}

// checking min value
float minval(float one, float two, float three) {

	float min;

	if (one < two)
		min = one;
	else
		min = two;
	if (min < three) {
	}
	else
		min = three;

	return (min);

}
