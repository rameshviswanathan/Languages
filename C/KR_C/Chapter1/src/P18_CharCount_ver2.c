/*------------------------------------------------------------------------
 *
 * P18_CharCount_ver2.c: Count characters in input
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P18_CharCount_ver2.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P18_CharCount_ver2 P18_CharCount_ver2.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P18_CharCount_ver2.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P18_CharCount_ver2
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("Char count: %.0f\n", nc);

	return 0;
}

/*-------------------------------------------------------------------------*/
