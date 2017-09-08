/*------------------------------------------------------------------------
 *
 * P13_Ex1_4_Cel_To_Faren_Table.c: Write a program to convert a given
 * range of celcius temperature to its farenheit equivalent.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P13_Ex1_4_Cel_To_Faren_Table.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P13_Ex1_4_Cel_To_Faren_Table P13_Ex1_4_Cel_To_Faren_Table.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P13_Ex1_4_Cel_To_Faren_Table.exe
 *   On Unix, in the shell terminal window, type
 *      ./P13_Ex1_4_Cel_To_Faren_Table
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	// Variable declaration
	int lower, upper, step;

	float celcius, fahr;

	//assignments
	lower = 0;		// lower celcius temp limit
	upper = 300;	// upper celcius temp limit
	step = 20;		// step size

	celcius = lower;
	//formula: f = (c + 32) * 9/5

	printf("-----------------------------------------\n");
	printf("%s\t\t%s\n", "celcius", "Farenheit");
	printf("-----------------------------------------\n");

	while (celcius <= upper) {
		fahr = (celcius + 32.0) * (9.0 / 5.0);
		printf("%3.0f\t\t%6.1f\n", celcius, fahr);
		celcius = celcius + 20;
	}

	printf("-----------------------------------------\n");
	return 0;
}

/*-------------------------------------------------------------------------*/
