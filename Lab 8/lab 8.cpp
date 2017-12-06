// Alex Cherekdjian & Vincent Sicat
// COEN 44 Lab
// LAB #8
// November 14, 2016
/* Description: This code resembles a hotel reservation service menu allowing the user to make reservations, cancel reservations, add a reservation
onto the waitlist, delete a waitlist request, list current requests, and quit the program.*/

#include "stdafx.h"
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#define MAXROOMS 3

int runFunc(int res_ID[MAXROOMS], int waitlist_ID[MAXROOMS], char names_reserved[MAXROOMS][15], char names_waitlist[MAXROOMS][15]);
int cancelFunc(int res_ID[MAXROOMS], int waitlist_ID[MAXROOMS], char names_reserved[MAXROOMS][15], char names_waitlist[MAXROOMS][15]);
int waitCancelFunc(int waitlist_ID[MAXROOMS], char names_waitlist[MAXROOMS][15]);
int list_funct(int reserved[MAXROOMS], int waitlist[MAXROOMS], char names_reserved[MAXROOMS][15], char names_waitlist[MAXROOMS][15], int res_ID[MAXROOMS], int waitlist_ID[MAXROOMS]);

int res_id = 0;// counter for reservation id
int wait_id = 0; // counter for waitlist
int ID = 1; //assignable ID's
char input; // input from user needed in order to run commands

int main()
{
	int reserved[MAXROOMS] = { 1, 2, 3 }, waitlist[MAXROOMS] = { 1, 2, 3 };
	// Reserved array holds Room numbers and Waitlist array holds Waitlist numbers
	char names_reserved[MAXROOMS][15] = { "" };
	char names_waitlist[MAXROOMS][15] = { "" };
	// names_reserved array holds character strings for the reservation names
	// names_waitlist array holds character strings for the waitlist names
	int res_ID[MAXROOMS] = { 0 }, waitlist_ID[MAXROOMS] = { 0 };
	// res_ID array holds all Reservations IDs for guests with a room
	// waitlist_ID array holds all Reservation IDs for guests on waitlist

	do {
		printf("Input (R)eserve, (C)ancel, (W)ait list request removal, (L)ist, (Q)uit: "); // printts initial request for input
		scanf(" %s", &input);
		if (input <= 'Z' && input >= 'A') // changes input to lowercase
			input = input + 32;

		if (strlen(&input) != 1) {
			printf("\nError. Invalid command. Try again.\n\n"); // if string length does not equal a character = error
		}
		else
			switch (input) {
			case ('r'): runFunc(res_ID, waitlist_ID, names_reserved, names_waitlist); // run reservation function
				break;
			case ('c'): cancelFunc(res_ID, waitlist_ID, names_reserved, names_waitlist); // run cancel reservation function
				break;
			case ('w'): waitCancelFunc(waitlist_ID, names_waitlist); // run waitlist cancelation function
				break;
			case ('l'): list_funct(reserved, waitlist, names_reserved, names_waitlist, res_ID, waitlist_ID); // run the list function
				break;
			case ('q'): // break the loop and quit the program
				break;
			default: printf("\nError. Invalid command. Try again.\n\n"); // anything else is an invalid command
				break;
			}
	} while (input != 'q');
	printf("\n\nThank you for using V & A technologies. Goodnight!\n"); // when quit print nice message :)
	return 0;
}

int runFunc(int res_ID[MAXROOMS], int waitlist_ID[MAXROOMS], char names_reserved[MAXROOMS][15], char names_waitlist[MAXROOMS][15]) {

	char waitingListResponse;

	if (wait_id == MAXROOMS) { //if waitlist id's are full then whole list is full
		printf("\nOur reservation and waitlist are full. Please try again another time.\n\n");
	}

	if (res_id == MAXROOMS && wait_id < MAXROOMS) { // all rooms booked thus go to waitlist id's
		printf("\nWe are sorry, but all are rooms are booked. :(\nHow about the waiting list? (Y)es (N)o: ");
		scanf(" %c", &waitingListResponse); // get waitlist response and do actions as follows
		printf("\n");

		if (waitingListResponse == 'y') { // if yes ask for a res name and give a res id
			printf("Your reservation id number is: %d\n", ID);
			waitlist_ID[wait_id] = ID; // put id in array
			ID++; // increment id
			printf("Input reservation name: "); //name
			scanf("%s", names_waitlist[wait_id]); // put name in waitlist array
			printf("Your reservation has been recorded!\n\n");
			wait_id++;
		}
		if ((waitingListResponse != 'y' && waitingListResponse != 'n')) { // if neither no or yes, error command
			printf("Error. Invalid command. Try again.\n\n");
		}
	}
	if (res_id < MAXROOMS) { //normal reservation function
		printf("\nYour reservation id number is: %d\n", ID); //give res id
		res_ID[res_id] = ID;
		ID++;
		printf("Input reservation name: "); //prompting for reservation name
		scanf("%s", names_reserved[res_id]);
		printf("Your reservation has been recorded! \n\n");
		res_id++;
	}
	return (0);
}

int cancelFunc(int res_ID[MAXROOMS], int waitlist_ID[MAXROOMS], char names_reserved[MAXROOMS][15], char names_waitlist[MAXROOMS][15]) {

	int removal_ID, comp; // declaring local variables for removal id and comparison id
	int l = 0;

	if (res_id < 1) //if no reservations print error message
		printf("\nPlease make a reservation first. \n\n");
	else {
		printf("\nWhich reservation ID would you like to remove: ");
		scanf(" %d", &removal_ID); //read id to removalid
		comp = removal_ID; //copy removal id to comp for test at end of function

		for (l = 0; l < MAXROOMS; l++) { //cycle through array and search for id
			if (res_ID[l] == removal_ID) { // if equal, set resid to 0 and removal id to resid
				res_ID[l] = 0;
				removal_ID = res_ID[l];
				printf("Your reservation has been removed.\n\n");
				if (waitlist_ID[0] == 0) // if waitlist = 0 then decrement reservation id
					res_id--;
				else // else decrement waitlist id
					wait_id--;
				for (l; l < MAXROOMS; l++) { // cycle all entries up one
					res_ID[l] = res_ID[l + 1];
					res_ID[l + 1] = 0;
					strcpy(names_reserved[l], names_reserved[l + 1]); // copying names up one in reservations array
					strcpy(names_reserved[l + 1], "");
				}
				strcpy(names_reserved[MAXROOMS - 1], names_waitlist[0]); // manually moving all waitlist id's up one and names up one
				res_ID[MAXROOMS - 1] = waitlist_ID[0];
				strcpy(names_waitlist[0], names_waitlist[1]);
				waitlist_ID[0] = waitlist_ID[1];
				strcpy(names_waitlist[1], names_waitlist[2]);
				waitlist_ID[1] = waitlist_ID[2];
				strcpy(names_waitlist[2], "");
				waitlist_ID[2] = 0;
				break;
			}
		}
		if (removal_ID == comp) // if removal id is equal to comparison variable, nothing was changed this print error message
			printf("Sorry, however that ID is not in our reservations list.\n\n");
	}
	return 0;
}

int waitCancelFunc(int waitlist_ID[MAXROOMS], char names_waitlist[MAXROOMS][15]) {

	int removal_ID, comp;  // declaring local variables for removal id and comparison id
	int l = 0;

	if (wait_id < 1) //if no waitlist reservations print error message
		printf("\nThere is no waitlist at this moment. \n\n");
	else {
		printf("\nWhich reservation ID would you like to remove: ");
		scanf(" %d", &removal_ID); // get removal id
		comp = removal_ID; // set comparrison id to removal id
		for (l = 0; l < MAXROOMS; l++) { // cycle through waitlist id's and find a match
			if (waitlist_ID[l] == removal_ID) {
				waitlist_ID[l] = 0; // if match found, set waitlist id to 0 and set the name equal to nothing
				removal_ID = waitlist_ID[l];
				strcpy(names_waitlist[l], "");
				printf("Your reservation has been removed.\n\n"); // print confirmation

				waitlist_ID[l] = waitlist_ID[l + 1]; // manually shuffling all waitlist names and ids up one 
				waitlist_ID[l + 1] = 0;
				strcpy(names_waitlist[l], names_waitlist[l + 1]);
				strcpy(names_waitlist[l + 1], "");
				wait_id--; // since waitlist opened up, decrement id's by one
				break;
			}
		}
		if (removal_ID == comp) // if comparison id is equal to removal id, nothing changed thus print error message
			printf("Sorry, however that ID is not in our reservations list.\n\n");
	}
	return 0;
}

int list_funct(int reserved[], int waitlist[], char names_reserved[][15], char names_waitlist[][15], int res_ID[], int waitlist_ID[])
{
	int a;

	if (res_id == 0 && wait_id == 0) // if nothing was reserved yet print error message
		printf("\nNo reservations inputed. Please input a reservation.\n\n");
	else { // if a reservation print
		printf("\nReservation List");
		printf("\nRm # |      Name      | Res ID |\n");
		for (a = 0; a < MAXROOMS; a++) { // cycle through array of reservations and print until resID = 0
			if (res_ID[a] == 0)
				break;
			else {
				printf("%4d | %9s      | %4d   |\n", reserved[a], names_reserved[a], res_ID[a]);
			}
		}

		if (waitlist_ID[0] != 0) {// print only if there are waitlist entries
			printf("\nWaitlist");
			printf("\nWt # |      Name      | Wait ID|\n");
		}

		for (a = 0; a < MAXROOMS; a++) { // cycle through array of waitlist reservations and print until waitID = 0
			if (waitlist_ID[a] == 0)
				break;
			else {
				printf("%4d | %9s      | %4d   |\n", waitlist[a], names_waitlist[a], waitlist_ID[a]);
			}
		}
		printf("\n");
	}
	return 0;
}

/*

PART 2 Answer:

For a week, we would need another array to hold the days of that week as well as a function to shuffle the week once the week is over. We would also need a seperate ask function to ask the user which
day of the week they would like to reserve a room in. This would be the same concept for a month and a year, just a lot more code. The code would need to notify the user of the price of that room. One
possible solution to this issue would be to add an extra extra array that corresponds to each of the rooms and holds all of the prices for each room respectively. The code would then have to interact 
with this array in the sense of printing those values correctly to the user. 

*/