/*------------------------------------------------------------------------
 *
 * P27_Ex_1_15_TempConversion.c: Write a function that converts a
 * given range of farenheit temp to its celcius.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P27_Ex_1_15_TempConversion.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P27_Ex_1_15_TempConversion P27_Ex_1_15_TempConversion.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P27_Ex_1_15_TempConversion.exe
 *   On Unix, in the shell terminal window, type
 *      ./P27_Ex_1_15_TempConversion
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

void faren_to_celcius(int lower, int upper, int step) {

	for (; lower <= upper; lower = lower + step) {
		printf("%3d\t\t%6.1f\n", lower, (5.0 / 9.0) *(lower - 32));
	}
}

int main() {
	faren_to_celcius(0, 300, 20);

	return 0;
}

/*-------------------------------------------------------------------------*/
