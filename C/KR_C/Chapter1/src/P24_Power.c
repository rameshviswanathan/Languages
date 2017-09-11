/*------------------------------------------------------------------------
 *
 * P24_Power.c: Write a function that computes the power of m raise to
 * the power of n.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P24_Power.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P24_Power P24_Power.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P24_Power.exe
 *   On Unix, in the shell terminal window, type
 *      ./P24_Power
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int power(int base, int n) {
	int val = 1;

	for (int i = 0; i < n; ++i)
		val = val * base;

	return val;
}

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
