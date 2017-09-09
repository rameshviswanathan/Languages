/*------------------------------------------------------------------------
 *
 * P18_CharCount.c: Count characters in input
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P18_CharCount.c
 *            EHsc -->standard exception handling 
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P18_CharCount P18_CharCount.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P18_CharCount.exe
 *   On Unix, in the shell terminal window, type 
 *      ./P18_CharCount
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	int ch;
	long char_cnt = 0;

	while ((ch = getchar()) != EOF) {
		++char_cnt;
	}

	printf("Char count: %ld\n", char_cnt);

	return 0;
}

/*-------------------------------------------------------------------------*/
