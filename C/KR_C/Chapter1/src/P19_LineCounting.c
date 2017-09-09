/*------------------------------------------------------------------------
 *
 * P19_LineCounting.c: Count lines in input
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P19_LineCounting.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P19_LineCounting P19_LineCounting.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P19_LineCounting.exe
 *   On Unix, in the shell terminal window, type
 *      ./P19_LineCounting
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
	int ch;
	int nLineCnt = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			++nLineCnt;
		}
	}

	printf("Newline Count:  %d\n", nLineCnt);
	return 0;
}

/*-------------------------------------------------------------------------*/
