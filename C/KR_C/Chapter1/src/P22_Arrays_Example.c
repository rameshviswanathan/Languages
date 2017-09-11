/*------------------------------------------------------------------------
 *
 * P22_Arrays_Example.c: Use arrays to keep track of number of each
 * digits present in the input stream.  Also use local variables to track
 * spaces and any other variables in the input stream
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P22_Arrays_Example.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P22_Arrays_Example P22_Arrays_Example.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P22_Arrays_Example.exe
 *   On Unix, in the shell terminal window, type
 *      ./P22_Arrays_Example
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>

#define DIGIT_CNT     10

int main() {
	int ch;
	int nOther, nSpace;
	int digits[DIGIT_CNT];

	for (int i = 0; i < DIGIT_CNT; ++i)
		digits[i] = 0;

	nSpace = nOther = 0;

	while ((ch = getchar()) != EOF) {
		if (isspace(ch))
			++nSpace;
		else if (ch >= '0' && ch <= '9') {
			++digits[ch - '0'];
		}
		else
			++nOther;
	}

	printf("nOther: %d nSpace: %d ", nOther, nSpace);

	printf(" digits: ");

	for (int i = 0; i < DIGIT_CNT; ++i)
		printf("%d ", digits[i]);

	printf("\n");

	return 0;
}

/*-------------------------------------------------------------------------*/
