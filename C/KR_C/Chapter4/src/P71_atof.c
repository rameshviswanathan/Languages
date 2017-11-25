/*------------------------------------------------------------------------
 *
 * P71_atof.c: Write a program that converts floating point numbers in
 * text form to a float.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P71_atof.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P71_atof P71_atof.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P71_atof.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P71_atof
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define BUF_SIZE 20

double atof(char *buf) {
	double val = 0.0;
	int sign = 1;
	int mantessa = 0;
	int fraction = 0;
	int power = 1;

	// remove spaces
	while (isspace(*buf))
		++buf;

	// check for sign
	if (*buf == '+' || *buf == '-') {
		sign = *buf == '-' ? -1 : 1;
		++buf;
	}

	// get the whole part of fraction
	while (isdigit(*buf)) {
		int cur_digit = *buf - '0';
		mantessa = mantessa * 10 + cur_digit;
		++buf;
	}

	// get the fraction piece
	if (*buf == '.') {
		++buf;
		while (isdigit(*buf)) {
			int cur_digit = *buf - '0';
			fraction = fraction * 10 + cur_digit;
			power *= 10;
			++buf;
		}
	}

	return sign * (mantessa + (double)fraction / power);
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char buf[BUF_SIZE] = "-1234.789";
	printf("input floating number is: %f \n", atof(buf));
	return 0;
}

/*-------------------------------------------------------------------------*/
