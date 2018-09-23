#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INT_MAX_LINE 15
#define FLOAT_MAX_LINE 15

#ifndef MYUSERINPUT_H_INCLUDED
#define MYUSERINPUT_H_INCLUDED

int askUserForInt(void); // asks user for input from STDIN and only allows user to proceed if they enter a positive whole number
double askUserForDouble(void); //asks user for input from STDIN and only allows them to proceed if they enter a positive number up to 999,999,986,991,104

#endif