/*------------------------------------------------------------------------
 *
 * P14_Faren_Cel_Table_Reverse.c: Write a program to convert a given
 * range of farenheit temperature to its celcius equivalent.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P14_Faren_Cel_Table_Reverse.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P14_Faren_Cel_Table_Reverse P14_Faren_Cel_Table_Reverse.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P14_Faren_Cel_Table_Reverse.exe
 *   On Unix, in the shell terminal window, type
 *      ./P14_Faren_Cel_Table_Reverse
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main() {
	printf("------------------------------------\n");
	printf("%s\t\t%s\n", "Farenheit", "Celcius");
	printf("------------------------------------\n");

	for (int fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
		printf("%3d\t\t%6.1f\n", fahr, (5.0 / 9.0) *(fahr - 32.0));

	printf("------------------------------------\n");
	return 0;
}

/*-------------------------------------------------------------------------*/
