/* Name: Alex Cherekdjian
Date: October 3, 2016
Title: Carbon Dioxide Fee Calculation
File: Lab4
Description: This program computes the amount of carbon dioxide produced each year by a car as well as the offset fee the owner
will pay due to the car's carbon emission and family income. */
#include "stdafx.h"
#include <stdio.h>

double
getCO2Vehicle(double miles, double gasMileage, double CO2Gal)
{
	//dividing the total amount of miles by the gas mileage & multiplying by estimated grams CO2 for 1 vehicle
	double kgCarbonDioxideVehicle = (miles / gasMileage)*CO2Gal;
	return (kgCarbonDioxideVehicle);
}

double
getFee(double one, double two)
{
	//multiplying the amount of CO2 produced by vehicle by the tentative fee
	double gettingFee = one * two;
	return (gettingFee);
}

double
getFeePaid(double FI, double PL, double MFL, double initialFee, double vehicle)
{
	if (FI <= PL) //if family income less than or equal to poverty line
	{
		printf("The amount of CO2 generated is %f kg, and your fee is $0.", vehicle);
	}
	else if (FI > PL && FI < PL * 2) //if family income is greater than poverty line and less than two times poverty line
	{
		initialFee *= 0.50;
		printf("The amount of CO2 generated is %f kg, and your fee is $%f.", vehicle, initialFee);
	}
	else if (FI >= 2 * PL && FI < 2 * MFL) //if family income is greater than or equal to poverty line & less than two times mfl
	{
		printf("The amount of CO2 generated is %f kg, and your fee is $%f.", vehicle, initialFee);
	}
	else if (FI >= 2 * MFL && FI < 3 * MFL) //if family income is greater than or equal to two times mfl & less than three times mfl
	{
		initialFee *= 2;
		printf("The amount of CO2 generated is %f kg, and your fee is $%f.", vehicle, initialFee);
	}
	else if (FI >= 3 * MFL && FI < 4 * MFL) { //if family income is greater than or equal to three times mfl & less than four times mfl
		initialFee *= 4.5;
		printf("The amount of CO2 generated is %f kg, and your fee is $%f.", vehicle, initialFee);
	}
	else { // if nothing else, then family income is greater than four times mfl
		initialFee *= 10;
		printf("The amount of CO2 generated is %f kg, and your fee is $%f.", vehicle, initialFee);
	}
	return (0);
}
int main() {
	for (int i = 0; i <= 4; i++) {

		// assigning variables that are inputed by user
		double milesDrivenYear = 0;
		double aveGasMileage = 0;
		double familyIncome = 0;
		//assigning variables that are constants

		double kgCO2Gal = 8.887;
		double tFee = 1.00;
		double medianFamilyIncome = 71015;
		double povertyLine = 23850;

		//assigning variables that are calculated through functions
		double CO2Vehicle = 0;
		double feeInitial = 0;

		//asking for values for variables
		printf("Input the number of miles driven each year: ");
		scanf_s("%lff", &milesDrivenYear);

		printf("Input the average gas mileage of the vehicle: ");
		scanf_s("%lff", &aveGasMileage);

		printf("Input your family income: ");
		scanf_s("%lff", &familyIncome);

		// calculates the amount of CO2
		CO2Vehicle = getCO2Vehicle(milesDrivenYear, aveGasMileage, kgCO2Gal);

		//calculates the initial fee before taking into account the family income
		feeInitial = getFee(CO2Vehicle, tFee);

		// calculates and prints to the user the final fee taking into account the family income
		getFeePaid(familyIncome, povertyLine, medianFamilyIncome, feeInitial, CO2Vehicle);

		printf("\n\n");
	}
	return 0;
}