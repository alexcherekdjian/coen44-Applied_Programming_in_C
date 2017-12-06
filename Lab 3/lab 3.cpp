/* Name: Alex Cherekdjian
Date: October 3, 2016
Title: Carbon Dioxide Fee Calculation
File: Lab3
Description:
This program computes the amount of carbon dioxide produced each year by a car as well as the offset fee the owner will pay due to the car's carbon emission.
The program also computes the amount of carbon dioxide produced by the whole population in a year as well as the total offset fee the population will have to
pay (assuming the same values as above).
*/

#include "stdafx.h"
#include <stdio.h>

int main()
{

	//assigning variables

	double MilesPerYear = 0;

	double aveGasMileage = 0;

	double feePerKilogram = 0.25;

	double carbonDioxidePerGal = 6.453;

	double totalVehicles = 24487807;

	printf("Input number of miles driven each year here: ");
	scanf_s("%lff", &MilesPerYear); //assigning MilesPerYear value inputed above

	printf("\nInput the average gas mileage of the car here: ");
	scanf_s("%lff", &aveGasMileage);  //assigning aveGasMileage value inputed above

									  //calculating amount of CO2 produced by a single vehicle
	double kgCarbonDioxideVehicle = (MilesPerYear / aveGasMileage)*carbonDioxidePerGal;

	//calculating amount of CO2 produced by the total population
	double kgTotalCarbonDioxide = kgCarbonDioxideVehicle*totalVehicles;

	double totalcost = kgTotalCarbonDioxide*feePerKilogram;

	//printing results to user
	printf("The amount of CO2 produced each year by this car is %lf kilograms. The offset fee will be $ %lf\n", kgCarbonDioxideVehicle, kgCarbonDioxideVehicle);
	printf("Assuming the same values, the total amount of CO2 produced each year by the population is %lf kilograms. The total offset fee will be $ %lf\n", kgTotalCarbonDioxide, totalcost);

	return 0;

}



