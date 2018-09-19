#include "myUserInput.h"


// asks user for input from STDIN and only allows user to proceed if they enter a number
// returns a an integer representation of the number entered
// decimal points are not allowed in input


int askUserForInt()
{
	char inputArray[INT_MAX_LINE];
	char *end;
	int x, y; //counters
	int ch;
	short int numberFlag, negativeFlag, newlineFlag;
	int userInputAsInt;

	numberFlag = 0;
	negativeFlag = 0;
	newlineFlag = 0;

	while (numberFlag == 0) //while we don't have a number
	{
		y = 0;
		for (x = 0; x <= sizeof inputArray; x++)
				{
					inputArray[x] = 0;
				}
		
		if (fgets(inputArray, sizeof inputArray, stdin))
		{


			for (x = 0; x <= sizeof inputArray; x++)
			{
				//printf("element %d is: %d\n", x, inputArray[x]);
				if (inputArray[x] == 10) // if newline
				{
					newlineFlag = 1;
				}
			}

			if (newlineFlag == 0)
			{
				printf("The input you entered was too long \n");
				while ((ch = getchar()) != 10 && ch != EOF)
				{
					
					y++;
					if (y >= 30)
					{
						printf("\nToo many characters entered, please try running the program again and entering a smaller number.");
						exit(1);
					}
				}
				//break;
			}

			for (x = 0; x <= sizeof inputArray; x++)
			{
				//printf("Inside For Loop element %d is: %d\n", x, inputArray[x]);
				if ((inputArray[x] > 47) && (inputArray[x] < 58))//between 47 and 58 are numbers, 0 is null created earlier
				{	
					numberFlag = 1;
					//printf("I got a number! \n");
				}

				else if (inputArray[x] == 45 && x == 0) //- sign must be at the beginning of string  
				{
					numberFlag = 0;
				} 

				else if (inputArray[x] == 10) //newline from fgets is replaced by 0. If this is removed, user can hit return and fgets will add only a newline // if number flag exists, brek
				{
					
					if (numberFlag == 0)
					{
						printf("Invalid input, please try again: \n");
						break;
					}
					else
					{
						break;
					}					 
				}

				else
				{ 

					printf("I did not get a number, try again by entering a whole number without spaces or other syntax: ");
					numberFlag = 0;
					
					break;
					printf("I should have broken \n");
				}			
			}	
		}
		else
		{
			printf("You did not enter a number, please run the program again ");
		}
	}	

	userInputAsInt = strtol(inputArray, &end, 10);
	if (userInputAsInt >= 2147483647 )
	{
		printf("The number you entered is equal to or exceeds 2147483646, we will use the maximum value of 2147483647 as your input\n");
		userInputAsInt = 2147483647;
	}
		
	return userInputAsInt;

}




float askUserForFloat()
{
	char inputArray[FLOAT_MAX_LINE];
	char *end;
	int x, y;
	int ch;
	short int numberFlag, decimalFlag, negativeFlag, newlineFlag;
	float userInputAsFloat;

	numberFlag = 0;
	decimalFlag = 0;
	newlineFlag = 0;
	negativeFlag = 0;

	while (numberFlag == 0)
	{
		y = 0;
		for (x = 0; x < sizeof inputArray; x++) // initialize array to all 0's so that we can check total input and remove garbage
		{
			inputArray[x] = 0;
		}
		
		if (fgets(inputArray, sizeof inputArray, stdin))
		{
			for (x = 0; x <= sizeof inputArray; x++)
			{
				//printf("element %d is: %d\n", x, inputArray[x]);
				if (inputArray[x] == 10) // if newline
				{
					newlineFlag = 1;
				}
			}

			if (newlineFlag == 0)
			{
				printf("The input you entered was too long \n");
				while ((ch = getchar()) != 10 && ch != EOF)
				{
					
					y++;
					if (y >= 30)
					{
						printf("\nToo many characters entered, please try running the program again and entering a smaller number.");
						exit(1);
					}
				}
				//break;
			}
		

			for (x = 0; x < sizeof inputArray; x++)
			{
				if ((inputArray[x] > 47) && (inputArray[x] < 58)) //between 47 and 58 are numbers in ascii, 0 is null created earlier, 46 is a decimal point
				{	
					numberFlag = 1;
					//printf("I got a number! \n");
				}
				else if (inputArray[x] == 45 && x == 0) //- sign must be at the beginning of string  
				{
					numberFlag = 0;
				} 
				else if(inputArray[x] == 46) // decimal
				{
					if (decimalFlag == 1)
					{
						printf("Too many decimal points in the number you entered, please try again \n");
						numberFlag = 0;
						decimalFlag = 0;						
						break;
					}

					decimalFlag = 1;
				} 
				else if (inputArray[x] == 10) //newline from fgets is replaced by 0. If this is removed, user can hit return and fgets will add only a newline // if number flag exists, brek
					{
					
						if (numberFlag == 0)
						{
							printf("Invalid input, please try again: \n");
							break;
						}
						else
						{
						break;
						}					 
					}

				else
				{ 

					printf("I did not get a number, try again by entering only a positive number without characters (with the exception of a single decimal or negative sign), spaces, or other syntax \n");
					numberFlag = 0;
					for (x = 0; x < sizeof inputArray; x++)
					{
						inputArray[x] = 0;
					}
					break;
				}			
			}	
		}
		else
		{
			printf("You did not enter a number, please run the program again ");
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