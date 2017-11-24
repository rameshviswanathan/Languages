/*------------------------------------------------------------------------
 *
 * P41_LeapYear.c: Check if the given year is leap year
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P41_LeapYear.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P41_LeapYear P41_LeapYear.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P41_LeapYear.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P41_LeapYear
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_leap_year(unsigned int year) {
	// A year is leap if it is 
		// divided by 4 and not by 100 but 400

	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/*-------------------------------------------------------------------------*/

int main() {
	for (int year = 2000; year <= 2020; ++year)
		printf(" The year %d is %s\n", year, is_leap_year(year) ? "leap" : "not leap");
	return 0;
}