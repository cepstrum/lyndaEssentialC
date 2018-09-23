//You will ask the user to enter the loan amount, the number of years to pay back, and the yearly interest rate.


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "myUserInput.h"

#define PAYMENTSPERYEAR 12


void getUserInput(double *loanAmount, int *yearsOfLoan, double *interestRate);
double calculateMonthlyPayment(double loanAmount, int yearsOfLoan, double interestRate);
double calculateTotalPayment(double, double);

int main(void)
{
	double loanAmount;
	int yearsOfLoan = 0;
	double interestRate;
	double monthlyPayment;

	getUserInput(&loanAmount, &yearsOfLoan, &interestRate);
	monthlyPayment = calculateMonthlyPayment(loanAmount, yearsOfLoan, interestRate);

	printf("Your monthly payment is $%.2f\nYour total payment will be $%.2f", monthlyPayment, calculateTotalPayment(monthlyPayment, yearsOfLoan));
}


void getUserInput(double *loanAmount, int *yearsOfLoan, double *interestRate)
{
	
		
	printf("Enter an integer number of years: ");
	while ((*yearsOfLoan = askUserForInt()) <= 0 || *yearsOfLoan > 100)
	{

		if (*yearsOfLoan > 100)
			printf("Amount of years cannot exceed 100, please try again: ");
		if(*yearsOfLoan <= 0)
			printf("Amount of years is less than or equal to zero.\nAmount of years must be greater than zero. Please try again: ");
	}
	printf("You entered %d years \n", *yearsOfLoan);


	printf("Enter the loan amount: ");
	while ((*loanAmount = askUserForDouble()) <= 0 || *loanAmount > 1000000000000)
	{

		if (*loanAmount > 1000000000000)
			printf("This program can handle a maximum loan amount of 1,000,000,000,000, please try again");
		if(*loanAmount <= 0)
			printf("Loan amount is less than or equal to zero.\nLoan amount must be greater than zero. Please try again: ");
	}
	printf("You entered %.2f\n", *loanAmount);
	

	printf("Enter the interest rate: ");
	while ((*interestRate = askUserForDouble()) <= 0 || *interestRate > 1000)
	{

		if (*interestRate > 1000)
			printf("This program can handle a maximum interest rate of 1,000%% \nPlease try again: ");
		if(*interestRate <= 0)
			printf("Interest rate is less than or equal to zero.\nInterest rate must be greater than zero. Please try again: ");
	}
	printf("You entered %f%% \n", *interestRate);

	
}

double calculateMonthlyPayment(double loanAmount, int yearsOfLoan, double interestRate)
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

double calculateTotalPayment(double monthlyPayment, double numberOfYears)
{
	return monthlyPayment * numberOfYears * 12;
}