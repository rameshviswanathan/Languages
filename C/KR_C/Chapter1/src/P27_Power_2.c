/*------------------------------------------------------------------------
 *
 * P27_Power_2.c: Write a function that computes the power of m raise
 * to the power of n.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P27_Power_2.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P27_Power_2 P27_Power_2.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P27_Power_2.exe
 *   On Unix, in the shell terminal window, type
 *      ./P27_Power_2
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int power(int base, int n) {
	int val;

	for (val = 1; n > 0; --n)
		val = val * base;

	return val;
}

/*-------------------------------------------------------------------------*/

int main() {
	int base = 2;
	int exp = 5;

	printf("Base %d raise to the power of %d: %d\n", base, exp, power(base, exp));

	base = 3;
	exp = 3;

	printf("Base %d raise to the power of %d: %d\n", base, exp, power(base, exp));

	return 0;
}

/*-------------------------------------------------------------------------*/
