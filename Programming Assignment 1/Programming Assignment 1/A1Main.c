#include<stdio.h>
#include<math.h>

/* The following is a list of colour codes and their corresponding colour. These are used to modify output text colour:
	Red "\x1b[31m"
	Yellow "\x1b[33m"
	Green "\x1b[32m"
	Magenta "\x1b[35m"
	White "\x1b[37m"
*/

int main() {
	int choice = 0; //Creates a 'choice' variable to hold the user's input regarding which sequence they would like to initiate
	int clear = 0; //Creats a 'clear' variable which fufills and eliminates additional invalid input 


	//Asks the user which sequence (what action) they would like to initiate, and has that sequence commence
	do { //Loops until user has inputted a valid value
		choice = 0; //Sets 'choice' to 0 to ensure the loop can end if no int is provided


		//Informs the user about what actions they can take, and asks them to input a number corresponding to one of the listed options
		printf("\x1b[33m(Please input the number corresponding to the sequence you would like to run)"); //Asks the user to input a number corresponding to the sequence they would like to choose
		printf("\n\x1b[37mWhat would you like to look at?\n      Display creator's name\t\t(\x1b[35m1\x1b[37m)\n      Calculate triangles' third side\t(\x1b[35m2\x1b[37m)\n      Input a couple floats\t\t(\x1b[35m3\x1b[37m)\n      Calculate overall pay\t\t(\x1b[35m4\x1b[37m)\n      Calculate discounted price\t(\x1b[35m5\x1b[37m)\n"); //This asks the user which sequence they would like to choose, and shows them which number corresponds to each sequence
		scanf_s("%d", &choice); //Gets the user to input, and fills choice if the input is an int


		//Checks if input is valid. If it is not it displays an error message and loops
		do { //Keeps looping until any leftover input is cleaned up
			(clear = getchar()); //Sets 'clear' to the next input the system picks up (fufilling that input in the process)
		} while (clear != '\n' && clear != EOF); //Keeps looping until no additional input is found

		if (choice > 5 || choice == 0) { printf("\x1b[31m\n\nINVALID INPUT\n\n\x1b[37m"); } //If input is not valid, displays error message

	} while (choice > 5 || choice == 0); //If input is not valid, loops


	printf("\n\n\n"); //Seperates the chosen sequence from the sequence select sequence



	//This first sequence prints my (the creator's) name in a few ways
	if (choice == 1) {

		
		printf("Ethan Bentley\n"); //Prints my (creator's) first and last name on one line
		printf("Ethan\nBentley\n"); //Prints my (creator's) first and last name separately on 2 lines
		printf("Ethan "); printf("Bentley\n"); //Prints my (creator's) first and last name on one line, but with two seperate 'printf' calls for each name
	}



	//This second sequence takes two angles from a triangle and finds the third
	else if (choice == 2) {
		float triang[3]; //Creates a 1d array containing 3 rows to hold the 3 angles of the triangle


		printf("This sequence takes two angles of a triangle (provided by you) and tells you the third!\n"); //Informs the user on what this sequence does
		do {
			printf("     Please input your two angles (as numbers greater than 0, adding to less than 180), one after the other:\n"); //Tells the user what they can input to get the third angle of their triangle

			//Asks the user for their angles, and stores their values in the first and second rows of the 'triang' array
			printf("\nEnter the first angle: ");
			scanf_s("%f", &triang[0]);

			if (triang[0] <= 0 || triang[0] > 178) { //Checks if the first angle is a possible angle for a triangle (between 1 & 178). If not, displays an error and loops

				printf("\x1b[31m\n\nINVALID INPUT\n\x1b[37m");
				printf("\x1b[32m\n\nINPUTTED VALUE SHOULD NOT EXCEED 178, BE LESS THAN 1, AND IT SHOULD BE A NUMBER\n\n\n\n\x1b[37m");
			}
			else {
				do { //Keeps looping until any leftover input is cleaned up
					(clear = getchar()); //Sets 'clear' to the next input the system picks up
				} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found (checks if clear has been set to a new line and has reached the end of the file)

				printf("Enter the second angle: ");
				scanf_s("%f", &triang[1]);

				if (triang[1] <= 0 || triang[1] > 178) { //Checks if the second angle is a possible angle for a triangle (between 1 & 178). If not, displays an error and loops

					printf("\x1b[31m\n\nINVALID INPUT\n\x1b[37m");
					printf("\x1b[32m\n\nINPUTTED VALUE SHOULD NOT EXCEED 178, BE LESS THAN 1, AND IT SHOULD BE A NUMBER\n\n\n\n\x1b[37m");
				}
				else {
					/* Adding the following would be useful for someone seeking to expand this sequence (it pervents folloing scan calls from being filled by previous inputs)
					do { //Keeps looping until any leftover input is cleaned up
						(clear = getchar()); //Sets 'clear' to the next input the system picks up
					} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found
					*/

					triang[2] = 180; //Resets 'triang[2]' so that it will trigger the catch if it is not changed

					//Informs the user and loops the sequence if their inputted values is or exceeds 180
					if ((triang[0] + triang[1]) >= 180) {
						printf("\x1b[31m\n\nINVALID INPUT\n\x1b[37m");
						printf("\x1b[32m\n\nINPUTTED VALUES SHOULD NOT ADD TO ABOVE 179\n\n\n\n\x1b[37m");
					}
					else {

						triang[2] = (180 - (triang[0] + triang[1])); //Sets 'triang[2]' to what the thrid angle would be (assuming proper inputs)
					}
				}
				}
				do { //Keeps looping until any leftover input is cleaned up
					(clear = getchar()); //Sets 'clear' to the next input the system picks up
				} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found
			


		} while ((triang[0] + triang[1] + triang[2]) != 180); //If the three angles do no add up to 180, loops and asks the user for their angles again. Otherwise the sequence continue


		printf("The third angle is: %0.f", triang[2]); printf(" degrees\n"); //Informs the user of the third angle's degree
	}



	//This sequence has the user inputting two float values. Those values' sum, product, and quotient are then outputted back to the user
	else if (choice == 3) {
		float userinput[2] = { 0, 0 }; //Defines the float array 'userinput', used to hold the user's 2 inputted floats and the results derived from them


		printf("This sequence takes 2 floats (numbers including decimals) (provided by you) and then outputs their sum, product, and quotient (The first inputted will be the dividend, your second the divisor (1st / 2nd))\n"); //Informs the user what this sequence does
		do {
			userinput[0, 1] =  0;
		printf("     Please input your 2 floats, one after the other (Must be above 0)\n"); //Asks the user for their input of two floats
		printf("\nWhat is your first float?: "); //Asks the user for their first float value
		scanf_s("%f", &userinput[0]); //Checks for and sets 'userinput[0]' to the user's first float value

		do { //Keeps looping until any leftover input is cleaned up
			(clear = getchar()); //Sets 'clear' to the next input the system picks up
		} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found

		if (userinput[0] == 0) { //Checks if the user inputted a valid float value. If not, displays an error message and goes straight to looping
			printf("\x1b[31m\n\nINVALID INPUT\n\x1b[37m");
			printf("\x1b[32m\n\nINPUTTED VALUES SHOULD BE A NON 0 FLOAT VALUE\n\n\n\n\x1b[37m");
			}
		else {

			printf("\nWhat is your second float?: "); //Asks the user for their second float value
			scanf_s("%f", &userinput[1]); //Checks for and sets' userinput[1]' to the user's second float value

			do { //Keeps looping until any leftover input is cleaned up
				(clear = getchar()); //Sets 'clear' to the next input the system picks up
			} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found

			if (userinput[1] == 0) { //Checks if the user inputted a valid float value. If not, displays an error message
				printf("\x1b[31m\n\nINVALID INPUT\n\x1b[37m");
				printf("\x1b[32m\n\nINPUTTED VALUES SHOULD BE A NON 0 FLOAT VALUE\n\n\n\n\x1b[37m");
			}
		}
		
		} while (userinput[0] == 0 || userinput[1] == 0); //Checks if either of the user's floats has a value of 0. If so, it loops and again asks the user for their floats. Otherwize the sequence continues
		

		//Calculates and displays the sum of the user's two inputted floats
		printf("\nThe sum of your floats is: \t\x1b[33m%f\x1b[37m\n", (userinput[0] + userinput[1]));


		//Calculates and displays the product of the user's two inputted floats
		printf("The product of your floats is: \t\x1b[33m%f\x1b[37m\n", (userinput[0] * userinput[1]));


		//Calculates and displays the quotient of the user's two inputted floats
		printf("The quotient of your floats is: \x1b[33m%f\x1b[37m\n", (userinput[0] / userinput[1]));
	}



	//This sequence has the user inputting how much an employee is paid and how many hours they work. It then takes those values and outputs to the user the total that would have been made
	else if (choice == 4) {
		float hoursworked = 0.0; //Defines 'hoursworked' to hold the number of hours worked
		float pay = 0.00; //Defines 'pay' to hold the amount earned per hour
		
			printf("This sequence calculates an employee's total pay based on the number of hours that they have worked and their pay (you'll input both)\n"); //This informs the user what this sequence does
			
			do { //Gets a value for how many hours have been worked, and checks if it is valid
			printf("\n\tPlease input the number of hours worked (as a number greater than 0 with up to 1 decimal(more than 1 decimal will result in rounding))\n"); //Asks the user to provide a valid input
			scanf_s("%f", &hoursworked); //Checks for and fills 'hoursworked' with the user's input

			if (hoursworked <= 0) { //If input is not valid, displays an error
				printf("\x1b[31m\n\nINVALID INPUT\n\n\x1b[37m");
			}

			do { //Keeps looping until any leftover input is cleaned up
				(clear = getchar()); //Sets 'clear' to the next input the system picks up
			} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found

		} while (hoursworked <= 0);  //If input is not valid, loops and asks again


			do { //Gets a value for the hourly wage, and checks if it is valid
				printf("\n\tPlease input how much is made per hour (as a number greater than 0 with up to 2 decimals(more than 2 decimals will result in rounding))\n"); //Asks the user to provide a valid input
				scanf_s("%f", &pay); //Checks for and fills 'pay' with the user's input

				if (pay <= 0) { //If input is not valid, displays an error
					printf("\x1b[31m\n\nINVALID INPUT\n\n\x1b[37m");
				}

				do { //Keeps looping until any leftover input is cleaned up
					(clear = getchar()); //Sets 'clear' to the next input the system picks up
				} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found

			} while (pay < 0); //If input is not valid, loops and asks again
		
			printf("\n\n\nThe total amount the employee earned in %.1f hours at $%.2f per hour is \x1b[33m$%.2f\x1b[37m\n\n", hoursworked, pay, pay * hoursworked);
	}



	//This sequence allows the user to input an original price and a discount percentage. It will then output the price with the discount applied
	else if (choice == 5) {
		float price = 0.00; //Defines 'price' to hold the original price of the product
		float discount = 0; //Defines 'discount' to hold the persentage discounted

		printf("\nThis sequence allows you to find the price of an item by inputing the product's original price and the percentage discounted\n"); //Describes to the user what this sequence does

		do {
			printf("\tPlease input the original price of the product (as a number greater than or equal to 0 with up to 2 decimals (more than 2 decimals will result in rounding)\n");
			scanf_s("%f", &price);

			if (price < 0) { //If input is not valid, displays an error
				printf("\x1b[31m\n\nINVALID INPUT\n\n\x1b[37m");
			}

			do { //Keeps looping until any leftover input is cleaned up
				(clear = getchar()); //Sets 'clear' to the next input the system picks up
			} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found

		} while (price < 0);


		do {
			printf("\tPlease input the percentage of the discount (as a whole number between 0 - 100)\n");
			scanf_s("%f", &discount);

			if (discount < 0 || discount > 100) { //If input is not valid, displays an error
				printf("\x1b[31m\n\nINVALID INPUT\n\n\x1b[37m");
			}

			do { //Keeps looping until any leftover input is cleaned up
				(clear = getchar()); //Sets 'clear' to the next input the system picks up
			} while (clear != '\n' && clear != EOF); //Keeps repeating until no additional input is found

		} while (discount < 0 || discount > 100);

		printf("\n\n\nThe product, with an original price of $%.2f and a discount of %.0f%%, costs \x1b[33m$%.2f\x1b[37m (-$%.2f)\n\n", price, discount, (price - (price * (discount / 100))), (price * (discount / 100)));
		
	}
	

		return 0;
}
