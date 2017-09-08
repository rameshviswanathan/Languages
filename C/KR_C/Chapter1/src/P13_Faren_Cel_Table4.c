/*------------------------------------------------------------------------
 *
 * P13_Faren_Cel_Table4.c: Write a program to convert a given range of
 * farenheit temperature to its celcius equivalent using for loop.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P13_Faren_Cel_Table4.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P13_Faren_Cel_Table4 P13_Faren_Cel_Table4.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P13_Faren_Cel_Table4.exe
 *   On Unix, in the shell terminal window, type
 *      ./P13_Faren_Cel_Table4
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return 0;
}

/*-------------------------------------------------------------------------*/
