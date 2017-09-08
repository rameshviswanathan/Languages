/*------------------------------------------------------------------------
 *
 * P12_Faren_Cel_Table2.c: Write a program to convert Farenheit
 * temperature to Celcius for a given range of farenheit temperature
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P12_Faren_Cel_Table2.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P12_Faren_Cel_Table2 P12_Faren_Cel_Table2.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P12_Faren_Cel_Table2.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P12_Faren_Cel_Table2
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	// Variable declaration
	float fahr, celcius;

	int lower, upper, step;

	// assignments
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celcius = (5.0 / 9.0) *(fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
	
	return 0;
}

/*-------------------------------------------------------------------------*/
