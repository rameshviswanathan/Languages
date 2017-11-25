/*------------------------------------------------------------------------
 *
 * P73_Ex_4_2_atof.c: Extend atof to handle scientific notaition of
 * the form 123.45e-6 where a floating-point number may be followed by e
 * or E and an optionally signed exponent.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P73_Ex_4_2_atof.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P73_Ex_4_2_atof P73_Ex_4_2_atof.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P73_Ex_4_2_atof.exe
 *   On Unix, in the shell terminal window, type
 *      ./P73_Ex_4_2_atof
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

	val = mantessa + (double)fraction / power;
	val *= sign;

	printf("mantessa: %f\n", val);
	fraction = 0;
	sign = 1;

	if (*buf == 'e' || *buf == 'E') {
		buf++;
		if (*buf == '+' || *buf == '-') {
			sign = (*buf == '-') ? -1 : 1;
			++buf;
		}
		while (isdigit(*buf)) {
			int cur_digit = *buf - '0';
			fraction = fraction * 10 + cur_digit;
			++buf;
		}
	}

	while (fraction) {
		if (sign == -1)
			val /= 10;
		else
			val *= 10;

		--fraction;
	}

	return val;
}

/*-------------------------------------------------------------------------*/

int main(void) {
	char buf[BUF_SIZE] = "-1234.789e+3";
	printf("input floating number is: %f \n", atof(buf));
	return 0;
}

/*-------------------------------------------------------------------------*/