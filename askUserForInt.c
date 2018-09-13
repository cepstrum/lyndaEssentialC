#include "askUserForInt.h"


// asks user for input from STDIN and only allows user to proceed if they enter a number
// returns a an integer representation of the number entered
// decimal points are not allowed in input


int askUserForInt()
{
	char inputArray[MAX_LINE];
	char *end;
	int x;
	short int flag;
	int userInputAsInt;

	for (x = 0; x < sizeof inputArray; x++) // initialize array to all 0's so that we can check total input and remove garbage
	{
		inputArray[x] = 0;
	}

	flag = 0;

	while (flag == 0)
	{
		printf("Enter string ");
		fgets(inputArray, sizeof inputArray, stdin);

		for (x = 0; x < sizeof inputArray; x++)
		{
			if (((inputArray[x] > 47) && (inputArray[x] < 58)) || (inputArray[x] == 0)) //between 47 and 58 are numbers, 0 is null created earlier
			{	
				flag = 1;
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
				flag = 0;
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