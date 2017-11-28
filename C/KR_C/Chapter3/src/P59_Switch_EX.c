/*------------------------------------------------------------------------
 *
 * P59_Switch_EX.c: Write a program using switch statement to count
 * the number of occurrence of digits 0...9, white spaces and other
 * characters.
 *
 * COMPILE:
 *   To compile on VC++:
 *         cl.exe /EHsc /W4 P59_Switch_EX.c
 *            EHsc -->standard exception handling
 *            W4 is for enabling warning
 *   To compile on gcc:
 *            gcc -Wall -g -o P59_Switch_EX P59_Switch_EX.c
 *            Wall for enable all Warning
 *            g for debug information
 *
 * EXECUTE:
 *   On Windows, in the command prompt window, type
 *      P59_Switch_EX.exe
 *   On Unix, in the shell terminal window, type
 *      ./P59_Switch_EX
 *
 *-------------------------------------------------------------------------*/
#include <stdio.h>
#define NUM_DIGITS 10
int main(void) {
	int ch;
	int nDigits[NUM_DIGITS];
	int nOther, nWhiteSpace;
	int i;

	nOther = nWhiteSpace = 0;
	for (i = 0; i < NUM_DIGITS; ++i)
		nDigits[i] = 0;

	while ((ch = getchar()) != EOF) {
		switch (ch) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			nDigits[ch - '0']++;
			break;
		case ' ':
		case '\t':
		case '\n':
			nWhiteSpace++;
			break;
		default:
			nOther++;
			break;
		}
	}

	printf(" nWhiteSpace: %d nOthers: %d nDigits: ", nWhiteSpace, nOther);
	for (i = 0; i < NUM_DIGITS; ++i)
		printf("%d\t", nDigits[i]);

	return 0;
}

/*-------------------------------------------------------------------------*/
