/*------------------------------------------------------------------------
 *
 * P17_Ex_1_7.c: Write a program to print the value of EOF.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P17_Ex_1_7.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P17_Ex_1_7 P17_Ex_1_7.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P17_Ex_1_7.exe
 *   On Unix, in the shell terminal window, type
 *      ./P17_Ex_1_7
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	printf("Value of EOF: %d\n", EOF);
	return 0;
}

/*-------------------------------------------------------------------------*/
