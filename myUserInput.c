#include "myUserInput.h"


// asks user for input from STDIN and only allows user to proceed if they enter a number
// returns a an integer representation of the number entered
// decimal points are not allowed in input


int askUserForInt()
{
	char inputArray[INT_MAX_LINE];
	char *end;
	int x;
	short int numberFlag;
	int userInputAsInt;

	for (x = 0; x < sizeof inputArray; x++) // initialize array to all 0's so that we can check total input and remove garbage
	{
		inputArray[x] = 0;
	}

	numberFlag = 0;

	while (numberFlag == 0)
	{
		printf("using an integer value: "); // before calling this function printf something more specific like "Enter loan amount" (using integer value)
		fgets(inputArray, sizeof inputArray, stdin);

		for (x = 0; x < sizeof inputArray; x++)
		{
			if (((inputArray[x] > 47) && (inputArray[x] < 58)) || (inputArray[x] == 0)) //between 47 and 58 are numbers, 0 is null created earlier
			{	
				numberFlag = 1;
				//printf("I got a number! \n");
			} 
			else if (inputArray[x] == 10) //newline from fgets is replaced by 0
			{
				inputArray[x] = 0;
				x--;
			}
			else
			{ 

				printf("I did not get a number, try again by entering only a positive whole number without characters, spaces, or other syntax \n");
				numberFlag = 0;
				for (x = 0; x < sizeof inputArray; x++)
				{
					inputArray[x] = 0;
				}
				break;
			}			
		}	
	}	

	userInputAsInt = strtol(inputArray, &end, 10);
	if (userInputAsInt == 2147483647 )
		printf("The number you entered is equal to or exceeds the maximum allowable value for this program, we will use the maximum value of 2147483647 as your input\n");
	return userInputAsInt;

}




float askUserForFloat()
{
	char inputArray[FLOAT_MAX_LINE];
	char *end;
	int x;
	short int numberFlag, decimalFlag;
	float userInputAsFloat;


	for (x = 0; x < sizeof inputArray; x++) // initialize array to all 0's so that we can check total input and remove garbage
	{
		inputArray[x] = 0;
	}

	numberFlag = 0;
	decimalFlag = 0;

	while (numberFlag == 0)
	{
		printf("using a float value: "); // before calling this function printf something more specific like "Enter loan amount" (using float value)
		fgets(inputArray, sizeof inputArray, stdin);

		for (x = 0; x < sizeof inputArray; x++)
		{
			if (((inputArray[x] > 47) && (inputArray[x] < 58)) || (inputArray[x] == 0)) //between 47 and 58 are numbers in ascii, 0 is null created earlier, 46 is a decimal point
			{	
				numberFlag = 1;
				//printf("I got a number! \n");
			}
			else if(inputArray[x] == 46)
			{
				if (decimalFlag == 1)
				{
					printf("Too many decimal points in the number you entered, please try again \n");
					numberFlag = 0;
					decimalFlag = 0;
					for (x = 0; x < sizeof inputArray; x++)
					{
					inputArray[x] = 0;
					}
					break;
				}

				decimalFlag = 1;
			} 
			else if (inputArray[x] == 10) //newline from fgets is replaced by 0
			{
				inputArray[x] = 0;
				x--;
			}
			else
			{ 

				printf("I did not get a number, try again by entering only a positive number without characters (with the exception of a single decimal), spaces, or other syntax \n");
				numberFlag = 0;
				for (x = 0; x < sizeof inputArray; x++)
				{
					inputArray[x] = 0;
				}
				break;
			}			
		}	
	}	

	userInputAsFloat = strtof(inputArray, &end);
	if (userInputAsFloat >= 999999986991104)
	{						
		printf("You entered a number which was too high, we are using $999,999,986,991,104.0 instead");
		userInputAsFloat = 999999986991104;
	}
		
	return userInputAsFloat;

}