/*------------------------------------------------------------------------
 *
 * P9_Faren_Cel_Table.c: Write a program to convert Farenheit
 * temperature to Celcius for a given range of farenheit temperature
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P9_Faren_Cel_Table.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P9_Faren_Cel_Table P9_Faren_Cel_Table.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P9_Faren_Cel_Table.exe
 *   On Unix, in the shell terminal window, type
 *      ./P9_Faren_Cel_Table
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main()
{
	// Variable declaration
	int lower, upper, step;
	int fahr, celcius;

	// assignment
	lower = 0;		// lower limit
	upper = 300;	// upper limit
	step = 20;		// step size

	fahr = lower;

	// loop to iterate over a range of farenheit temp
	while (fahr <= upper) {
		celcius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celcius);
		fahr = fahr + step;
	}
}

/*-------------------------------------------------------------------------*/
