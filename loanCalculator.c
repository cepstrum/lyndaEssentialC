//You will ask the user to enter the loan amount, the number of years to pay back, and the yearly interest rate.


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "myUserInput.h"

#define PAYMENTSPERYEAR 12


void getUserInput(float *loanAmount, int *yearsOfLoan, float *interestRate);
double calculateMonthlyPayment(float loanAmount, int yearsOfLoan, float interestRate);
float calculateTotalPayment(float, float);

int main(void)
{
	float loanAmount;
	int yearsOfLoan = 0;
	float interestRate;
	float monthlyPayment;

	getUserInput(&loanAmount, &yearsOfLoan, &interestRate);
	monthlyPayment = calculateMonthlyPayment(loanAmount, yearsOfLoan, interestRate);

	printf("Your monthly payment is $%.2f\nYour total payment will be $%.2f", monthlyPayment, calculateTotalPayment(monthlyPayment, yearsOfLoan));
}


void getUserInput(float *loanAmount, int *yearsOfLoan, float *interestRate)
{
	
	printf("Enter the amount of years for the loan " );	
	while ((*yearsOfLoan = askUserForInt()) == 0) 
	{
		printf("You entered 0 which is an invalid amount of years, enter at least 1 year ");
	}

	printf("You entered: %d\n", *yearsOfLoan);


	printf("Enter the loan amount ");
	*loanAmount = askUserForFloat();
	printf("You entered $%f\n ", *loanAmount);
	

	printf("Enter the interest rate ");
	*interestRate = askUserForFloat();
	printf("You entered %f% \n", *interestRate);
	
}

double calculateMonthlyPayment(float loanAmount, int yearsOfLoan, float interestRate)
{
	if (interestRate != 0)
	{
		double i, discount, onePlusI, num, denom, n;

		i = (interestRate/100) / 12;
		n = yearsOfLoan * 12;

		onePlusI = pow((1+i), n);

		num = onePlusI - 1;
		denom = i * onePlusI;

		discount = num/denom;
	

		return loanAmount/discount;
	}
	else
		return loanAmount/(yearsOfLoan * 12); // no interest rate means monthly payment

}

float calculateTotalPayment(float monthlyPayment, float numberOfYears)
{
	return monthlyPayment * numberOfYears * 12;
}