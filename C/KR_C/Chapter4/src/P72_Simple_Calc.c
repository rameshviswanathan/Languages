/*------------------------------------------------------------------------
 *
 * P72_Simple_Calc.c: Write a program that reads a number per line and
 * prints the sum
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P72_Simple_Calc.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P72_Simple_Calc P72_Simple_Calc.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P72_Simple_Calc.exe
 *   On Unix, in the shell terminal window, type
 *      ./P72_Simple_Calc
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
int GetLine(char *buf, int len) {
	int ch;
	int i;

	for (i = 0; i < len - 1 && (ch = getchar()) != EOF && ch != '\n'; ++i)
		buf[i] = ch;

	if (ch == '\n')
		buf[i++] = ch;

	buf[i] = '\0';

	return i;
}
/*-------------------------------------------------------------------------*/

int main(void) {
	char buf[BUF_SIZE] = "1234.789";
	double sum = 0.0;
	while (GetLine(buf, BUF_SIZE)) {
		sum += atof(buf);
	}
	printf("sum: %f \n", sum);
	return 0;
}

/*-------------------------------------------------------------------------*/
